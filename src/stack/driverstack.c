#include "../player/player.h"
#include "stack.h"
#include "../skill/skill.h"

void GetPlayer(infostack * X, addressPlayer AP)
    {
        (*X).nama = Nama(AP);
        (*X).noUrut = NoUrut(AP) ;
        (*X).Petak = Petak(AP);
        (*X).Skillpemain = Skill(AP);
        (*X).isImmune = isImmune(AP);
        (*X).isHokiKecil = isHokiKecil(AP); 
        (*X).isHokiBesar = isHokiBesar(AP);
        (*X).isPostCermin = isPostCermin(AP); 
        (*X).next = NextPlayer(AP);

    }
    
void UpdatePetak(addressPlayer AP, int x)
    {
        Petak(AP) = x;
    }

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

    while (TempPetak < 10)
    {
        if( X.noUrut > TempNoUrut) 
        {
            X.Petak += 3;
            UpdatePetak(AP, X.Petak);
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
    
    printf("Petak %d\n", NextStack(S).Petak);
    printf("No Urut %d\n", NextStack(S).noUrut);
    Undo(&S);
    printf("AAA\n");
    printf("Petak %d\n", NextStack(S).Petak);
    printf("No Urut %d\n", NextStack(S).noUrut);

    return 0;
}