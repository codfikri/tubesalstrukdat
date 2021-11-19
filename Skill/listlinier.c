/* 	NIM/Nama 	: 18220031/Muhammad Raihan Aulia
	Nama file 	: listlinier.c
	Tanggal		: 28/10/2021
	Topik		: List Linier
	Deskripsi	: mendefinisikan operasi primitif list linier

*/

#include <stdio.h>
#include <stdlib.h>
#include "listlinier.h"
#include "boolean.h"


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
    // KAMUS LOKAL-------

    // ALGORITMA---------
    First(*L) = Nil;
}

/****************** Manajemen Memori ******************/
address Alokasi (infotype X)
/* Mengirimkan address hasil alokasi sebuah elemen */
/* Jika alokasi berhasil, maka address tidak nil, dan misalnya */
/* menghasilkan P, maka Info(P)=X, Next(P)=Nil */
/* Jika alokasi gagal, mengirimkan Nil */
{
    // KAMUS LOKAL
    address p;
    // ALGORITMA
    p = (ElmtList *) malloc(sizeof(ElmtList));
    if(p != Nil){
        Info(p)= X;
        Next(p)= Nil;
    }
    return p;
}
void Dealokasi (address *P)
/* I.S. P terdefinisi */
/* F.S. P dikembalikan ke sistem */
/* Melakukan dealokasi/pengembalian address P */
{
    // Kamus lokal

    // Algoritma
    free(*P);
}

/****************** PENCARIAN SEBUAH ELEMEN LIST ******************/
address Search (List L, infotype X)
/* Mencari apakah ada elemen list dengan Info(P)= X */
/* Jika ada, mengirimkan address elemen tersebut. */
/* Jika tidak ada, mengirimkan Nil */
{
    // Kamus lokal
    address p;
    boolean found;
    // Algoritma
    p = First(L);
    found = false;
    while((p != Nil) && (!found)){
        if (Info(p)== X){
            found = true;
        }
        else{
            p = Next(p);
        }
    }
    if(found) {
        return p;
    }
    else{
        return Nil;
    }
}


/****************** PRIMITIF BERDASARKAN NILAI ******************/
/*** PENAMBAHAN ELEMEN ***/
void InsVFirst (List *L, infotype X)
/* I.S. L mungkin kosong */
/* F.S. Melakukan alokasi sebuah elemen dan */
/* menambahkan elemen pertama dengan nilai X jika alokasi berhasil */
{
    // Kamus lokal
    address p;
    // Algoritma
    p = Alokasi(X);
    if(p != Nil){
        Next(p) = First(*L);
        First(*L) = p;
    }
}

void InsVLast (List *L, infotype X)
/* I.S. L mungkin kosong */
/* F.S. Melakukan alokasi sebuah elemen dan */
/* menambahkan elemen list di akhir: elemen terakhir yang baru */
/* bernilai X jika alokasi berhasil. Jika alokasi gagal: I.S.= F.S. */
{
    // Kamus lokal
    address p;
    // Algoritma
    p = Alokasi(X);
    if(p != Nil){
        InsertLast(L,p);
    }
}

/*** PENGHAPUSAN ELEMEN ***/
void DelVFirst (List *L, infotype *X)
/* I.S. List L tidak kosong  */
/* F.S. Elemen pertama list dihapus: nilai info disimpan pada X */
/*      dan alamat elemen pertama di-dealokasi */
{
    // Kamus lokal
    address p;
    // Algoritma
    p = First(*L);
    *X = Info(p);
    First(*L)= Next(p);
    Dealokasi(&p);
}
void DelVLast (List *L, infotype *X)
/* I.S. list tidak kosong */
/* F.S. Elemen terakhir list dihapus: nilai info disimpan pada X */
/*      dan alamat elemen terakhir di-dealokasi */
{
    // Kamus lokal
    address p;
    address loc;
    // Algoritma
    p = First(*L);
    loc = Nil;
    while(Next(p) != Nil){
        loc = p;
        p = Next(p);
    }
    if(loc == Nil){
        First(*L) = Nil;
    }
    else{
        Next(loc) = Nil;
    }
    *X = Info(p);
    Dealokasi(&p);
}

/****************** PRIMITIF BERDASARKAN ALAMAT ******************/
/*** PENAMBAHAN ELEMEN BERDASARKAN ALAMAT ***/
void InsertFirst (List *L, address P)
/* I.S. Sembarang, P sudah dialokasi  */
/* F.S. Menambahkan elemen ber-address P sebagai elemen pertama */
{
    // Kamus lokal

    // Algoritma
    Next(P) = First(*L);
    First(*L) = P;
}
void InsertAfter (List *L, address P, address Prec)
/* I.S. Prec pastilah elemen list dan bukan elemen terakhir, */
/*      P sudah dialokasi  */
/* F.S. Insert P sebagai elemen sesudah elemen beralamat Prec */
{
    // Kamus lokal

    // Algoritma
    Next(P) = Next(Prec);
    Next(Prec) = P;
}

void InsertLast (List *L, address P)
/* I.S. Sembarang, P sudah dialokasi  */
/* F.S. P ditambahkan sebagai elemen terakhir yang baru */
{
    // Kamus lokal
    address last;
    // Algoritma
    if(IsEmpty(*L)){
        Next(P) = First(*L);
        First(*L) = P;
    }
    else{
        last = First(*L);
        while(Next(last) != Nil){
            last = Next(last);
        }
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
    // Kamus lokal

    // Algoritma
    *P = First(*L);
    First(*L)= Next(First(*L));
}

void DelP(List *L, address nartoh)
/* I.S. Sembarang */
/* F.S. Jika ada elemen list beraddress P, dengan Info(P)=X  */
/* Maka P dihapus dari list dan di-dealokasi */
/* Jika tidak ada elemen list dengan Info(P)=X, maka list tetap */
/* List mungkin menjadi kosong karena penghapusan */
{
    // Kamus lokal
    address hinata;

    // Algoritma
    hinata = First(*L);
    if(nartoh != Nil){
        if(nartoh == hinata){
            DelFirst(L,&nartoh);
        }
        else{
            while(Next(hinata) != nartoh){
                hinata = Next(hinata);
            }
            DelAfter(L,&nartoh, hinata);
        }
        Dealokasi(&nartoh);
    }
}
void DelLast (List *L, address *P)
/* I.S. List tidak kosong */
/* F.S. P adalah alamat elemen terakhir list sebelum penghapusan  */
/*      Elemen list berkurang satu (mungkin menjadi kosong) */
/* Last element baru adalah predesesor elemen terakhir yg lama, */
/* jika ada */
{
    // Kamus lokal
    address p, loc;
    // Algoritma
    p = First(*L);
    loc = Nil;
    while(Next(p) != Nil){
        loc = p;
        p = Next(p);
    }
    *P = p;
    if(loc == Nil){
        First(*L) = Nil;
    }
    else{
        Next(loc) = Nil;
    }
}
void DelAfter (List *L, address *Pdel, address Prec)
/* I.S. List tidak kosong. Prec adalah anggota list  */
/* F.S. Menghapus Next(Prec): */
/*      Pdel adalah alamat elemen list yang dihapus  */
{
    // Kamus lokal

    // Algoritma
    *Pdel = Next(Prec);
    Next(Prec) = Next(Next(Prec));
    Next(*Pdel) = Nil;
}

/****************** PROSES SEMUA ELEMEN LIST ******************/
void PrintInfo (List L)
/* I.S. List mungkin kosong */
/* F.S. Jika list tidak kosong, iai list dicetak ke kanan: [e1,e2,...,en] */
/* Contoh : jika ada tiga elemen bernilai 1, 20, 30 akan dicetak: [1,20,30] */
/* Jika list kosong : menulis [] */
/* Tidak ada tambahan karakter apa pun di awal, akhir, atau di tengah */
{
    // Kamus lokal
    address P;
    // Algoritma
    P = First(L);
    if(IsEmpty(L)){
        printf("[]");
    }
    else{
        printf("[");
        while(Next(P) != Nil){
            printf("%d,", Info(P));
            P = Next(P);
        }
        printf("%d]",Info(P));
    }
}
int NbElmt (List L)
/* Mengirimkan banyaknya elemen list; mengirimkan 0 jika list kosong */
{
    // Kamus lokal
    int count;
    address p;
    // Algoritma
    p = First(L);
    count=0;
    while(p != Nil){
        p = Next(p);
        count += 1;
    }
    return count;
}

/*** Prekondisi untuk Max/Min/rata-rata : List tidak kosong ***/
infotype Max (List L)
/* Mengirimkan nilai Info(P) yang maksimum */
{
    // Kamus lokal
    infotype max;
    address p;
    // Algoritma
    max = Info(First(L));
    p = Next(First(L));
    while(Next(p) != Nil){
        if(max < Info(p)){
            max = Info(p);
        }
        p = Next(p);
    }
    if(max < Info(p)){
        max = Info(p);
    }
    return max;
}

address AdrMax (List L)
/* Mengirimkan address P, dengan info(P) yang bernilai maksimum */
{
    // Kamus lokal

    // Algoritma

    return Search(L, Max(L));
}
infotype Min (List L)
/* Mengirimkan nilai info(P) yang minimum */
{
    infotype min;
    address p;
    // Algoritma
    min = Info(First(L));
    p = Next(First(L));
    while(Next(p) != Nil){
        if(min > Info(p)){
            min = Info(p);
        }
        p = Next(p);
    }
    if(min > Info(p)){
        min = Info(p);
    }
    return min;
}
address AdrMin (List L)
/* Mengirimkan address P, dengan info(P) yang bernilai minimum */
{
    // Kamus lokal

    // Algoritma

    return Search(L, Min(L));
}

float Average (List L)
/* Mengirimkan nilai rata-rata info(P) */
{
    // Kamus lokal
    address P;
    float sum;
    int count;
    // Algoritma
    if(IsEmpty(L)){
        return 0;
    }
    else{
        P = First(L);
        sum = 0;
        count = 0;
        while (P != Nil){
            sum += Info(P);
            count ++;
            P = Next(P);
        }
        return sum/count;
    }
}
/****************** PROSES TERHADAP LIST ******************/
void PrintForward(List L)
{
    if(IsEmpty(L)){
        printf("[]\n");
    }
    else{
        printf("[");
        address p;
        p = First(L);
        while(Next(p) != Nil){
            printf("%d,", Info(p));
            p = Next(p);
        }
        printf("%d]\n", Info(p));
    }
}

void InversList (List *L)
/* I.S. sembarang. */
/* F.S. elemen list dibalik : */
/* Elemen terakhir menjadi elemen pertama, dan seterusnya. */
/* Membalik elemen list, tanpa melakukan alokasi/dealokasi. */
{
    // Kamus Lokal
    address p;
    List temp;
    // Algoritma
    CreateEmpty(&temp);
    while(!IsEmpty(*L)){
        DelLast(L, &p);
        InsertLast(&temp,p);
    }
    *L = temp;
}

void Konkat1 (List *L1, List *L2, List *L3)
/* I.S. L1 dan L2 sembarang */
/* F.S. L1 dan L2 kosong, L3 adalah hasil konkatenasi L1 & L2 */
/* Konkatenasi dua buah list : L1 dan L2    */
/* menghasilkan L3 yang baru (dengan elemen list L1 dan L2) */
/* dan L1 serta L2 menjadi list kosong.*/
/* Tidak ada alokasi/dealokasi pada prosedur ini */
{
    // Kamus lokal
    address p;
    // Algoritma
    CreateEmpty(L3);
    if(IsEmpty(*L1)){
        First(*L3) = First(*L2);

    }
    else
        First(*L3) = First(*L1);
        p = First(*L1);
        while(Next(p) != Nil){
            p = Next(p);
        }
        Next(p) = First(*L2);

    CreateEmpty(L1);
    CreateEmpty(L2);
}

