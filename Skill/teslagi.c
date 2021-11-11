#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "skill.h"

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
}



void printSkill(TabStr skillPemain)
{
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
    for(int i = 0; i < 6; i++){
        printf("%d. %s\n", i+1, daftarSkill[skillPemain.TI[i].skillId]);
    }
}

void getSkill(TabStr *skillPemain, int i){
    int x;

    x = rand();
    srand(x);
    x = check((x)%100 +1);

    (*skillPemain).TI[i].skillId = x;
    (*skillPemain).Neff += 1;
}


int main(){
    TabStr skillPemain;
    srand(time(NULL));

    for(int i = 0; i < 6; i++){
        getSkill(&skillPemain, i);

    }

    printSkill(skillPemain);
}
