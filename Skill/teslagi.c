#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "skill.h"
#include "boolean.h"




int check(int x){
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
    p = First(skillPemain);
    printf("Kamu memiliki skill:\n");
    while(p != Nil){
        printf("%d. %s\n", count, daftarSkill[Info(p)]);
        count += 1;
        p = Next(p);
    }
}

void getSkill(List *skillPemain){
    int x;
    address p;

    x = rand();
    srand(x);
    x = check((x)%100 +1);

    if(x != -999){
        InsVLast(skillPemain, x);
    }
}

// Masukin ke inisialisasi permainan -------------------------------------------
int main(){
    List skillPemain;
    srand(time(NULL));
    CreateEmpty(&skillPemain);
    for(int i = 0; i < 6; i++){
        getSkill(&skillPemain);
    }
    // PrintForward(skillPemain);
    printSkill(skillPemain);
}
