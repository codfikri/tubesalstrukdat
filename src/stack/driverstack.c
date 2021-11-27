#include "../player/player.h"
#include "stack.h"
#include "../skill/skill.h"

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

    Stack S;
    addressPlayer AP;
    infostack X;
    int TempPetak, TempNoUrut, BanyakStack;

    SCreateEmpty(&S);
    PushUndef(&S);
    AP = FirstPlayer(PL);
    GetPlayer(&X, AP);
    TempPetak = X.Petak;
    TempNoUrut = 0;

    while (TempPetak < 20)
    {
        if( X.noUrut > TempNoUrut) 
        {
            Petak(AP) += 3;

            GetPlayer(&X, AP);
            Push(&S, X);
            printf("Petak %d\n", InfoTop(S).Petak);
            printf("No Urut %d\n", InfoTop(S).noUrut);
            
            TempPetak = X.Petak;
            TempNoUrut = X.noUrut;
            AP = NextPlayer(AP);
            GetPlayer(&X, AP);
            printf("\n");
        }
        else
        {
            PushUndef(&S);
            TempNoUrut = 0;
        }
    }
    Pop(&S, &X);
    printPlayer(PL, l);
    printf("Petak %d\n", NextStack(S).Petak);
    printf("No Urut %d\n", NextStack(S).noUrut);
    Undo(&S, &PL);
    printf("Petak %d\n", NextStack(S).Petak);
    printf("No Urut %d\n", NextStack(S).noUrut);
    printPlayer(PL, l);

    return 0;
}