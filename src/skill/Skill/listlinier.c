#include <stdio.h>
#include <stdlib.h>
#include "listlinier.h"

/* PROTOTYPE */
/****************** TEST LIST KOSONG ******************/
boolean IsEmpty (List L)
/* Mengirim true jika list kosong */
{
    return First(L) == Nil;
}

/****************** PEMBUATAN LIST KOSONG ******************/
void CreateEmpty (List *L)
/* I.S. sembarang             */
/* F.S. Terbentuk list kosong */
{
    First(*L) = Nil;
}

address Alokasi (infotype X)
/* Mengirimkan address hasil alokasi sebuah elemen */
/* Jika alokasi berhasil, maka address tidak nil, dan misalnya */
/* menghasilkan P, maka Info(P)=X, Next(P)=Nil */
/* Jika alokasi gagal, mengirimkan Nil */
{
    address P = (address) malloc(sizeof(address) + 1);
    Info(P) = X;
    Next(P) = Nil;
    return P;
}

void Dealokasi (address *P)
/* I.S. P terdefinisi */
/* F.S. P dikembalikan ke sistem */
/* Melakukan dealokasi/pengembalian address P */
{
    free(*P);
}

address Search (List L, infotype X)
/* Mencari apakah ada elemen list dengan Info(P)= X */
/* Jika ada, mengirimkan address elemen tersebut. */
/* Jika tidak ada, mengirimkan Nil */
{
    if (IsEmpty(L)){
        return Nil;
    }

    address p = First(L);
    while (p != Nil && Info(p) != X){
        p = Next(p);
    }
    return p;
}

/*** PENAMBAHAN ELEMEN ***/
void InsVFirst (List *L, infotype X)
/* I.S. L mungkin kosong */
/* F.S. Melakukan alokasi sebuah elemen dan */
/* menambahkan elemen pertama dengan nilai X jika alokasi berhasil */
{
    address newNode = Alokasi(X);
    if (newNode != Nil){
        Next(newNode) = First(*L);
        First(*L) = newNode;
    }
}

void InsVLast (List *L, infotype X)
/* I.S. L mungkin kosong */
/* F.S. Melakukan alokasi sebuah elemen dan */
/* menambahkan elemen list di akhir: elemen terakhir yang baru */
/* bernilai X jika alokasi berhasil. Jika alokasi gagal: I.S.= F.S. */
{
    address newNode = Alokasi(X);
    if (IsEmpty(*L)){
        InsVFirst(L, X);
    }
    else{
        address p = First(*L);
        while (Next(p) != Nil){
            p = Next(p);
        }
        Next(p) = newNode;
        Next(Next(p)) = Nil;
    }
}

/*** PENGHAPUSAN ELEMEN ***/
void DelVFirst (List *L, infotype *X)
/* I.S. List L tidak kosong  */
/* F.S. Elemen pertama list dihapus: nilai info disimpan pada X */
/*      dan alamat elemen pertama di-dealokasi */
{
    address p = First(*L);
    *X = Info(p);
    First(*L) = Next(p);
    Dealokasi(&p);
}

void DelVLast (List *L, infotype *X)
/* I.S. list tidak kosong */
/* F.S. Elemen terakhir list dihapus: nilai info disimpan pada X */
/*      dan alamat elemen terakhir di-dealokasi */
{
    address p = First(*L);
    address loc = Nil;

    if (Next(p) != Nil){
        while(Next(Next(p)) != Nil){
            p = Next(p);
        }
        *X = Info(Next(p));
        Dealokasi(&Next(p));
        Next(p) = Nil;
    }
    else{
        DelVFirst(L, X);
    }
}

/****************** PRIMITIF BERDASARKAN ALAMAT ******************/
/*** PENAMBAHAN ELEMEN BERDASARKAN ALAMAT ***/
void InsertFirst (List *L, address P)
/* I.S. Sembarang, P sudah dialokasi  */
/* F.S. Menambahkan elemen ber-address P sebagai elemen pertama */
{
    address first = First(*L);
    if (P != Nil){
        Next(P) = first;
        First(*L) = P;
    }
}

void InsertAfter (List *L, address P, address Prec)
/* I.S. Prec pastilah elemen list dan bukan elemen terakhir, */
/*      P sudah dialokasi  */
/* F.S. Insert P sebagai elemen sesudah elemen beralamat Prec */
{
    Next(P) = Next(Prec);
    Next(Prec) = P;
}

void InsertLast (List *L, address P)
/* I.S. Sembarang, P sudah dialokasi  */
/* F.S. P ditambahkan sebagai elemen terakhir yang baru */
{
    if (IsEmpty(*L)){
        First(*L) = P;
    }
    else{
        address last = First(*L);
        while (Next(last) != Nil){
            last = Next(last);
        }
        Next(P) = Nil;
        Next(last) = P;
    }
}

/*** PENGHAPUSAN SEBUAH ELEMEN ***/
void DelFirst (List *L, address *P)
/* I.S. List tidak kosong */
/* F.S. P adalah alamat elemen pertama list sebelum penghapusan */
/*      Elemen list berkurang satu (mungkin menjadi kosong) */
/* First element yg baru adalah suksesor elemen pertama yang lama */
{
    address delete = First(*L);
    *P = delete;
    First(*L) = Next(delete);
}

void DelP (List *L, infotype X)
/* I.S. Sembarang */
/* F.S. Jika ada elemen list beraddress P, dengan Info(P)=X  */
/* Maka P dihapus dari list dan di-dealokasi */
/* Jika tidak ada elemen list dengan Info(P)=X, maka list tetap */
/* List mungkin menjadi kosong karena penghapusan */
{
    if (!IsEmpty(*L)){
        address p = First(*L);
        address dummy;
        if(Info(p) == X){
            DelFirst(L, &dummy);
        }
        else{
            while (Next(p) != Nil && Info(Next(p)) != X){
                p = Next(p);
            }
            if(Next(p) != Nil){
                DelAfter(L, &dummy, p);
            }
        }
    }
}

void DelLast (List *L, address *P)
/* I.S. List tidak kosong */
/* F.S. P adalah alamat elemen terakhir list sebelum penghapusan  */
/*      Elemen list berkurang satu (mungkin menjadi kosong) */
/* Last element baru adalah predesesor elemen terakhir yg lama, */
/* jika ada */
{
    address last = First(*L);
    if (Next(last) == Nil){
        DelFirst(L, P);
    }
    else{
        while(Next(Next(last)) != Nil){
            last = Next(last);
        }
        DelAfter(L, P, last);
    }
}

void DelAfter (List *L, address *Pdel, address Prec)
/* I.S. List tidak kosong. Prec adalah anggota list  */
/* F.S. Menghapus Next(Prec): */
/*      Pdel adalah alamat elemen list yang dihapus  */
{
    *Pdel = Next(Prec);
    Next(Prec) = Next(*Pdel);
}

void PrintInfo (List L)
/* I.S. List mungkin kosong */
/* F.S. Jika list tidak kosong, iai list dicetak ke kanan: [e1,e2,...,en] */
/* Contoh : jika ada tiga elemen bernilai 1, 20, 30 akan dicetak: [1,20,30] */
/* Jika list kosong : menulis [] */
/* Tidak ada tambahan karakter apa pun di awal, akhir, atau di tengah */
{
    printf("[");
    if (!IsEmpty(L)){
        address p = First(L);
        while (p != Nil){
            printf("%d", Info(p));
            p = Next(p);

            if (p != Nil){
                printf(",");
            }
        }
    }
    printf("]");
}

int NbElmt (List L)
/* Mengirimkan banyaknya elemen list; mengirimkan 0 jika list kosong */
{
    int ctr = 0;
    if (!IsEmpty(L)){
        address p = First(L);
        while (p != Nil){
            ctr++;
            p = Next(p);
        }
    }
    return ctr;
}

/*** Prekondisi untuk Max/Min/rata-rata : List tidak kosong ***/
infotype Max (List L)
/* Mengirimkan nilai Info(P) yang maksimum */
{
    address p = First(L);
    infotype max = Info(p);
    while (Next(p) != Nil){
        p = Next(p);
        if(Info(p) > max){
            max = Info(p);
        }
    }
    return max;
}

address AdrMax (List L)
/* Mengirimkan address P, dengan info(P) yang bernilai maksimum */
{
    return Search(L, Max(L));
}

infotype Min (List L)
/* Mengirimkan nilai info(P) yang minimum */
{
    address p = First(L);
    infotype min = Info(p);
    while (Next(p) != Nil){
        p = Next(p);
        if(Info(p) < min){
            min = Info(p);
        }
    }
    return min;
}

address AdrMin (List L)
/* Mengirimkan address P, dengan info(P) yang bernilai minimum */
{
    return Search(L, Min(L));
}

float Average (List L)
/* Mengirimkan nilai rata-rata info(P) */
{
    if (IsEmpty(L)){
		return 0;
	} else {
		address P = First(L);
		float tot = Info(P);
		float ctr = 1;
		while (Next(P) != Nil){
			P = Next(P);
			tot = tot + Info(P);
			ctr++;
		}
		return (tot/ctr);
	} 
}

/****************** PROSES TERHADAP LIST ******************/

void InversList (List *L)
/* I.S. sembarang. */
/* F.S. elemen list dibalik : */
/* Elemen terakhir menjadi elemen pertama, dan seterusnya. */
/* Membalik elemen list, tanpa melakukan alokasi/dealokasi. */
{
    if (!IsEmpty(*L)){
		address P = First(*L);
		while (Next(P) != Nil){
			P = Next(P);
		}
		address last = P;
		address Prec;
		while (P != First(*L)){
			Prec = First(*L);
			while (Next(Prec) != P){
				Prec = Next(Prec);
			}
			Next(P) = Prec;
			P = Next(P);
		}
		Next(P) = Nil;
		First(*L) = last;
	}
}
void Konkat1 (List *L1, List *L2, List *L3)
/* I.S. L1 dan L2 sembarang */
/* F.S. L1 dan L2 kosong, L3 adalah hasil konkatenasi L1 & L2 */
/* Konkatenasi dua buah list : L1 dan L2    */
/* menghasilkan L3 yang baru (dengan elemen list L1 dan L2) */
/* dan L1 serta L2 menjadi list kosong.*/
/* Tidak ada alokasi/dealokasi pada prosedur ini */
{
    CreateEmpty(L3);
    First(*L3) = First(*L1);
    First(*L1) = Nil;
    if (IsEmpty(*L3)){
        First(*L3) = First(*L2);
    }
    else{
        address p = First(*L3);
        while (Next(p) != Nil){
            p = Next(p);
        }
        Next(p) = First(*L2);
    }
    First(*L2) = Nil;
}