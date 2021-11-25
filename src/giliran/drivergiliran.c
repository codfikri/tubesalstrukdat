#include "giliran.h"

int main(){
    PlayerList PL;
    CreatePlayerList(&PL);
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
        inputPlayerList(&PL, l);
        break;
    default: printf("Pemain hanya dapat berjumlah 2, 3, atau 4 orang.\n");
    }

    printPlayer(PL, l);
    addressPlayer AP = FirstPlayer(PL);
    int PetakMax = 20;
    while (Petak(AP) != PetakMax){
        // Roll(AP);
        // CekTeleport(Petak(AP));
    }
    return 0;
}