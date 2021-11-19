#include <stdio.h>
#include <stdlib.h>
#include "stack2.h"

int main ()
{
    StackPlayer S;
    Player P1, P2, Pundef, P;
    int temp;
    addressStack A1, A2;
    Queue Q;
    CreateEmptyStack(&S);
    QCreateEmpty (&Q, 3);
    printf("isSEmpty? : %d\n", IsEmptyStack(S));
    CreatePlayer(&P1);
    CreatePlayer(&P2);
    PUndef(&Pundef);
    
    /*Awal*/
    PushUndef(&S);
    Add (&Q, P1);
    Add (&Q, P2);
    Add(&Q, Pundef);
    PushPlayer( &S,P1, Q);
    printf("infoTail %d\n", InfoTail(QUEUE(InfoTopPlayer(S))).Petak);
    PushPlayer( &S,P2, Q);
    printf("infoTail %d\n", InfoTail(QUEUE(InfoTopPlayer(S))).Petak);
    temp = InfoHead(QUEUE(InfoTopPlayer(S))).Petak;
    PushUndef(&S);
    
    printf("%d\n", temp);
    
    while (temp < 20)
    {
        if (temp == -1)
        {
            GameQueue(&Q, Pundef);
            PushUndef(&S);
            printf("infotopplayer : %d\n", PLAYER(InfoTopPlayer(S)).Petak);
        }
        else
        {
            P = InfoHead(QUEUE(InfoTopPlayer(S)));
            GameQueue(&Q, P);
            PushPlayer( &S, P, Q);
            printf("infotopplayer : %d\n", PLAYER(InfoTopPlayer(S)).Petak);
            printf("infoTail %d\n", InfoTail(QUEUE(InfoTopPlayer(S))).Petak);
            
        }
        temp = InfoHead(QUEUE(InfoTopPlayer(S))).Petak;
        
    }

    printf("Before\n");
    A1 = next(TopPlayer(S));
    A2 = next(A1);

    (P1) = PLAYER(info(A1));
    (P2) = PLAYER(info(A2));

    printf("Petak1: %d\n", (P2).Petak);
    printf("Petak2: %d\n", (P1).Petak);

    Undo(&S);

    A1 = next(TopPlayer(S));
    A2 = next(A1);

    (P1) = PLAYER(info(A1));
    (P2) = PLAYER(info(A2));


    printf("Petak1: %d\n", (P2).Petak);
    printf("Petak2: %d\n", (P1).Petak);
    
    return 0;
}
