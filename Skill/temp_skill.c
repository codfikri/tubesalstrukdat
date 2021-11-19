#include <stdio.h>
#include <stdlib.h>
#include "skill.h"
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
address SearchId (List L, infotype X)
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
        if (Info(p) == X){
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

void DelP(List *L, address nartoh)
/* I.S. Sembarang */
/* F.S. Jika ada elemen list beraddress P,  */
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

int NbElmt(List Q)
/* Mengirimkan banyaknya elemen list. Mengirimkan 0 jika Q kosong */
{
    // Kamus Lokal
    int count = 0;
    address p;

    // Algoritma
    p = First(Q);
    if(p == Nil){
        return 0;
    }
    else{
        while(p != Nil){
            count += 1;
            p = Next(p);
        }
        return count+1;
    }

}

// SKILL LESGOOOOOO ----------------------------------------------------------------
void printSkill(List skillPemain)
{
    // Kamus Lokal
    address p;
    int count = 1;
    char daftarSkill[][22] =
    {
        "Pintu Ga Ke Mana Mana",
        "Mesin Waktu",
        "Baling Baling Jambu",
        "Cermin Pengganda",
        "Senter Pembesar Hoki",
        "Senter Pengecil Hoki",
        "Mesin Penukar Posisi"
    };
    if(IsEmpty(skillPemain)){
        printf("Ndda ada skill-nya~~\n");
    }
    else{
        p = First(skillPemain);
        printf("Kamu memiliki skill:\n");
        while(p != Nil){
            printf("%d. %s\n", count, daftarSkill[Info(p)]);
            count += 1;
            p = Next(p);
        }
    }
}

void getSkill(List *skillPemain){
    int x;
    address p;

    if(NbElmt(*skillPemain) <= 10){
        x = rand();
        srand(x);
        x = chance((x)%100 +1);

        if(x != -999){
            InsVLast(skillPemain, x);
        }
    }
}

int chance(int x){
    if ((x >= 1) && (x <= 10)){
        return 0;
    }
    else if((x >= 11) && (x <= 20)){
        return 1;
    }
    else if((x >= 21) && (x <= 30)){
        return 2;
    }
    else if((x >= 31) && (x <= 36)){
        return 3;
    }
    else if((x >= 37) && (x <= 51)){
        return 4;
    }
    else if((x >= 52) && (x <= 66)){
        return 5;
    }
    else if((x >= 67) && (x <= 70)){
        return 6;
    }
    else{
        return -999;
    }
}


void SkillUse(List *skillPemain,int n)
{
    // Kamus lokal
    address p;
    // Algoritma
    p = First(*skillPemain);
    for(int i = 1; i < n; i++){
        p = Next(p);
    }

    DelP(skillPemain, p);
}





//------------- teslagi.c
int main(){
    List skillPemain;
    address p;

    srand(time(NULL));
    CreateEmpty(&skillPemain);
    getSkill(&skillPemain);
    getSkill(&skillPemain);
    getSkill(&skillPemain);
    getSkill(&skillPemain);
    getSkill(&skillPemain);
    getSkill(&skillPemain);
    getSkill(&skillPemain);
    getSkill(&skillPemain);
    getSkill(&skillPemain);
    getSkill(&skillPemain);
    getSkill(&skillPemain);
    getSkill(&skillPemain);
    getSkill(&skillPemain);
    getSkill(&skillPemain);
    getSkill(&skillPemain);
    PrintForward(skillPemain);
    printSkill(skillPemain);
    SkillUse(&skillPemain, 5);
    printSkill(skillPemain);
}


