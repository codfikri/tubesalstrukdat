#include <stdio.h>
#include "player.h"

int main(){
    Player P1, P2, P3, P4;
    List L1, L2, L3, L4;
    char nama1[50], nama2[50], nama3[50], nama4[50];
    int jmlPemain;
    printf("Masukan jumlah pemain: ");
    scanf("%d", &jmlPemain);
    printf("Masukan nama pemain 1: ");
    scanf("%s", nama1);
    CreatePlayer(&P1);
    CreateEmpty(&L1);
    printf("Masukan nama pemain 2: ");
    scanf("%s", nama2);
    CreatePlayer(&P2);
    CreateEmpty(&L2);
    if (jmlPemain > 2){
        printf("Masukan nama pemain 3: ");
        scanf("%s", nama3);
        CreatePlayer(&P3);
        CreateEmpty(&L3);
        if (jmlPemain > 3){
            printf("Masukan nama pemain 4: ");
            scanf("%s", nama4);
            CreatePlayer(&P4);
            CreateEmpty(&L4);
        }
    }
    getSkill(&L1);
    printSkill(L1);
    addSkillPlayer(&P1, L1);
    printSkill(P1.Skillpemain);
    return 0;
}