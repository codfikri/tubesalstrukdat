#include <stdio.h>
#include <stdlib.h>
#include "skill.h"
#include "boolean.h"
#include "listlinier.h"

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

void useSkill(List *skillPemain, int n)
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
        pintuGaKemana(skillPemain, p);
        break;
    case 1:
        mesinwaktu(skillPemain, p);
        break;
    case 2:
        balingjambu(skillPemain, p);
        break;
    case 3:
        cerminGanda(skillPemain, p);
        break;
    case 4:
        senterBesarHoki(skillPemain, p);
        break;
    case 5:
        senterKecilHoki(skillPemain, p);
        break;
    case 6:
        mesinPenukarPosisi(skillPemain, p);
        break;
    }
}

void MenuSkill(List *skillPemain) // main dari skill nya
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
                useSkill(skillPemain, n);
            }
        }
        else if(n == 0){
            printf("\n>>=======================================================================+\n");
            printSkill(*skillPemain);
        }
    }

}

// Use Skill uwu~~~~~~~~~~~~~~
void pintuGaKemana(List *skillPemain, address p)
/* Memberi buff kepada pemain */
{
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

void cerminGanda(List *skillPemain, address p)
{
    if(NbElmt(*skillPemain) <= 9){
        DelAddress(skillPemain, p);
        getSkill(skillPemain);
        getSkill(skillPemain);
        printf(">> Dengan kekuatan Cermin Pengganda dan berkah dari Dolos-sama,\n   player-sama mendapatkan 2 skill baru \n");
    }
    else{
        printf(">> skill anda sudah terlalu penuh, tidak dapat menggunakan skill ini\n");
    }
}

void senterBesarHoki(List *skillPemain, address p)
{

    DelAddress(skillPemain, p);
    printf(">> Ketika anda menggunakan Senter Pembesar Hoki, muncul cahaya keemasan\n   beserta suara Aqua-sama yang menyebutkan \"Blessing\" \n");
}

void senterKecilHoki(List *skillPemain, address p)
{
    DelAddress(skillPemain, p);
    printf(">> Ketika anda menggunakan Senter Pengecil Hoki, Senter tersebut menghisap cahaya,\n   terdengar suara asing yang mengutuk anda \"Misfortune\" \n");
}

void mesinPenukarPosisi(List *skillPemain, address p)
{
    DelAddress(skillPemain, p);
    printf(">> Anda menggunakan Mesin Penukar Posisi!\n   Anda menukar posisi anda dengan Player-san\n");
}
