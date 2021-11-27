// Masukin ke inisialisasi permainan -------------------------------------------
#include <stdio.h>
#include <stdlib.h>
#include "..\boolean.h"
#include "..\player\player.h"
#include "listlinier.h"

int main(){
    PlayerList PL;
    CreatePlayerList(&PL);
    boolean isLastPlayer = false;
    int l;
    printf("Masukan jumlah pemain: ");
    scanf("%d", &l);
    switch (l)
    {
    case 1: printf("Minimal pemain adalah sebanyak 2 orang.\n");
        break;
    case 2:
    case 3:
    case 4:
        for (int i=1; i<=l; i++){
            char playerName[50];
            printf("PLAYER %d\n", i);
            printf("Masukan nama pemain: ");
            scanf("%s", playerName);
            addressPlayer AP = AlokasiPlayer(i, playerName);
            if (i==l){
                isLastPlayer = true;
            }
            strcpy(Nama(AP), playerName);
            insertPlayer(&PL, AP, isLastPlayer);
        }
        setJumlahPlayer(&PL, l);
        printf("%d\n", JumlahPlayer(PL));
        printPlayer(PL, l);
        break;

    default: printf("Pemain hanya dapat berjumlah 2, 3, atau 4 orang.\n");
    }
    addressPlayer P1 = FirstPlayer(PL);
    addressPlayer P2 = NextPlayer(P1);
    srand(time(NULL));
    getSkill(Skill(&P1));
    getSkill(Skill(&P1));
    Petak(P2) = 3;
    P1 = FirstPlayer(PL);
    MenuSkill(P1);

    P2 = NextPlayer(P1);
    printPlayer(PL,2);
    // MenuSkill(P1);

    return 0;
}
/*
int main()
{
    PlayerList PL;
    CreatePlayerList(&PL);
    int l = 2;

    address p;
    inputPlayerList(&PL, l);
    printPlayer(PL, l);


    Petak(P2) = 2;

    srand(time(NULL));
    for(int i = 0; i < 10; i++){
        getSkill(Skill(&P1));
    }



    MenuSkill(P1);
    printf("petak p1: %d\n",Petak(P1));
    printf("petak p2: %d\n",Petak(P2));
    MenuSkill(P1);

}
*/
