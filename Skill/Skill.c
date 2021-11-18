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
    printf("player menggunakan skill %s-nyan\n", daftarSkill[idSkill]);
    switch (idSkill)
    {
    case 0:
        printf("dengan kekuatan Pintu Ga Ke Mana Mana, player-sama mendapatkan imunitas terhadap teleport-nya \n");
        break;
    case 1:
        printf("dengan kekuatan Mesin Waktu, Semua pemain mundur~~~ \n");
        break;
    case 2:
        printf("dengan kekuatan Baling Baling Jambu, Semua pemain dipaksa maju sejauh n \n");
        break;
    case 3:
        printf("dengan kekuatan Cermin Pengganda, player-sama mendapatkan imunitas terhadap teleport-nya \n");
        break;

    case 4:
        printf("dengan kekuatan Senter Pembesar Hoki, player-sama mendapatkan imunitas terhadap teleport-nya \n");
        break;
    case 5:
        printf("dengan kekuatan Senter Pengecil Hoki, player-sama mendapatkan imunitas terhadap teleport-nya \n");
        break;
    case 6:
        printf("dengan kekuatan Mesin Penukar Posisi, player-sama mendapatkan imunitas terhadap teleport-nya \n");
        break;
    }
    DelAddress(skillPemain, p);
}

void MenuSkill(List *skillPemain) // main dari skill nya
{
    // Kamus lokal
    int n = 0;

    // Algoritma
    printSkill(*skillPemain);
    while(n != -999){
        printf("");
        scanf("%d", &n);
        if(abs(n) <= NbElmt(*skillPemain)){
            if(n < 0){
                DelSkill(skillPemain, -n);
            }
            else{
                useSkill(skillPemain, n);
            }
        }
    }

}
