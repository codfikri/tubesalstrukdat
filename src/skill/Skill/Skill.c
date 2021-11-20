#include <stdio.h>
#include <stdlib.h>
#include "skill.h"
#include "boolean.h"
#include "listlinier.h"
#include "buff.h"

// dari listlinier.c --------------------------------------------------
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

// dari skill.c ----------------------------------------------------------------------------------
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


void DelAddress(List *L, address nartoh)
/* I.S. Sembarang */
/* F.S. Jika ada elemen list beraddress P,  */
/* Maka P dihapus dari list dan di-dealokasi */
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





/****************** PROSES TERHADAP LIST ******************/



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


void DelSkill(List *skillPemain,int n)
{
    // Kamus lokal
    address p;
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

    // Algoritma
    p = First(*skillPemain);
    for(int i = 1; i < n; i++){
        p = Next(p);
        printf("player membuang skill %s-nyan\n", daftarSkill[Info(p)]);
    }
    DelAddress(skillPemain, p);
}

void useSkill(List *skillPemain, int n, Buff *buff)
{
    // Kamus Lokal
    address p;
    infotype idSkill;
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

    // Algoritma
    p = First(*skillPemain);
    for(int i = 1; i < n; i++){
        p = Next(p);
    }
    idSkill = Info(p);
    // printf("player menggunakan skill %s-nyan\n", daftarSkill[idSkill]);
    switch (idSkill)
    {
    case 0:
        pintuGaKemana(skillPemain, p, buff);
        break;
    case 1:
        mesinwaktu(skillPemain, p);
        break;
    case 2:
        balingjambu(skillPemain, p);
        break;
    case 3:
        cerminGanda(skillPemain, p, buff);
        break;
    case 4:
        senterBesarHoki(skillPemain, p, buff);
        break;
    case 5:
        senterKecilHoki(skillPemain, p, buff);
        break;
    case 6:
        mesinPenukarPosisi(skillPemain, p);
        break;
    }
}

void MenuSkill(List *skillPemain, Buff *buff) // main dari skill nya
{
    // Kamus lokal
    int n = 0;

    // Algoritma
    printf(">>====SKILL==============================================================+\n");
    printSkill(*skillPemain);
    while(n != -999){
        printf("\n>> Gunakan 0 untuk melihat skill sekarang\n");
        printf(">> Gunakan -999 untuk keluar dari menu skill\n");
        scanf("%d", &n);
        if(abs(n) <= NbElmt(*skillPemain) && n != 0){
            if(n < 0){
                DelSkill(skillPemain, -n);
            }
            else{
                useSkill(skillPemain, n, buff);
            }
        }
        else if(n == 0){
            printf("\n>>=======================================================================+\n");
            printSkill(*skillPemain);
        }
    }

}

// Use Skill uwu~~~~~~~~~~~~~~
void pintuGaKemana(List *skillPemain, address p, Buff *buff)
/* Memberi buff kepada pemain */
{
    (*buff).info[0] = true;
    DelAddress(skillPemain, p);
    printf(">> Walaupun pintu tersebut tidak menuju ke manapun, player-san merasakan dirinya\n   mendapatkan pilihan mengenai teleporter\n");
}

void mesinwaktu(List *skillPemain, address p)
/* Membuat seluruh player kecuali pengguna skill sejauh roll dadu */
{
    DelAddress(skillPemain, p);
    printf(">> Player-san mengubah waktu yang ada yang mengakibatkan setiap pemain selain player-san\n   Mundur sejauh rolldadu\n");
}

void balingjambu(List *skillPemain, address p)
{
    DelAddress(skillPemain, p);
    printf(">> Player-san memaksa tiap pemain memakai Baling-Baling Jambu yang mengakibatkan\n   mereka maju sejauh rolldadu\n");
}

void cerminGanda(List *skillPemain, address p, Buff *buff)
{
    if(NbElmt(*skillPemain) <= 9){
        (*buff).info[0] = true;
        DelAddress(skillPemain, p);
        getSkill(skillPemain);
        getSkill(skillPemain);
        printf(">> Dengan kekuatan Cermin Pengganda dan berkah dari Dolos-sama,\n   player-sama mendapatkan 2 skill baru \n");
    }
    else{
        printf(">> skill anda sudah terlalu penuh, tidak dapat menggunakan skill ini\n");
    }
}

void senterBesarHoki(List *skillPemain, address p, Buff *buff)
{
    (*buff).info[2] = true;
    DelAddress(skillPemain, p);
    printf(">> Ketika anda menggunakan Senter Pembesar Hoki, muncul cahaya keemasan\n   beserta suara Aqua-sama yang menyebutkan \"Blessing\" \n");
}

void senterKecilHoki(List *skillPemain, address p, Buff *buff)
{
    (*buff).info[3] = true;
    DelAddress(skillPemain, p);
    printf(">> Ketika anda menggunakan Senter Pengecil Hoki, Senter tersebut menghisap cahaya,\n   terdengar suara asing yang mengutuk anda \"Misfortune\" \n");
}

void mesinPenukarPosisi(List *skillPemain, address p)
{
    DelAddress(skillPemain, p);
    printf(">> Anda menggunakan Mesin Penukar Posisi!\n   Anda menukar posisi anda dengan Player-san\n");
}


// dari buff.c -----------------------------------------------------------------------------------------------
void CreateBuff(Buff *buff)
{
    for(int i=0; i< 4; i++){
        (*buff).info[i] = false;
    }
}

void setAfterTurn(Buff *buff)
{
    (*buff).info[1]= false;
    (*buff).info[2]= false;
    (*buff).info[3]= false;
}


// Masukin ke inisialisasi permainan -------------------------------------------
int main(){
    List skillPemain;
    address p;
    int n;
    Buff buff;
    for(int i=0; i< 4; i++){
        buff.info[i] = false;
    }


    srand(time(NULL));
    CreateEmpty(&skillPemain);
    for(int i = 0; i < 10; i++){
        getSkill(&skillPemain);
    }
    MenuSkill(&skillPemain, &buff);
    for(int i = 0; i < 4; i++){
        printf("%d ", buff.info[i]);
    }
}
