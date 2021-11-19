#include <stdio.h>
#include <stdlib.h>
#include "stack2.h"

int main ()
{
    StackPlayer S;
    Player P1, P2;
    int temp;
    addressStack A1, A2;
    Queue Q;
    CreateEmptyStack(&S);
    QCreateEmpty (&Q, 2);
    printf("isSEmpty? : %d\n", IsEmptyStack(S));
    CreatePlayer(&P1);
    CreatePlayer(&P2);
    temp = 1;
    /**/
    PushUndef(&S);
    Add (&Q, P1);
    Add (&Q, P2);
    PushPlayer( &S,P1, Q);
    printf("infoTail %d\n", InfoTail(QUEUE(InfoTopPlayer(S))).Petak);
    PushPlayer( &S,P2, Q);
    printf("infoTail %d\n", InfoTail(QUEUE(InfoTopPlayer(S))).Petak);
    PushUndef(&S);
    
    while (temp < 20)
    {
        /*INCREMENT PETAK*/
        (P1).Petak = (P1).Petak + 2;
        (P2).Petak = (P2).Petak + 5;
        /*P1*/
        GameQueue(&Q, P1);
        PushPlayer( &S,P1, Q);
        printf("infotopplayer : %d\n", PLAYER(InfoTopPlayer(S)).Petak);
        printf("infoTail %d\n", InfoTail(QUEUE(InfoTopPlayer(S))).Petak);
        temp = P1.Petak;
        /*P2*/
        GameQueue(&Q, P2);
        PushPlayer( &S,P2, Q);
        printf("infotopplayer : %d\n", PLAYER(InfoTopPlayer(S)).Petak);
        printf("infoTail %d\n", InfoTail(QUEUE(InfoTopPlayer(S))).Petak);
        temp = P2.Petak;
        /*undef*/
        PushUndef(&S);
        printf("infotopplayer : %d\n", PLAYER(InfoTopPlayer(S)).Petak);
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
    printf("infoTail %d\n", InfoTail(QUEUE(info(A1))).Petak);
    return 0;
}
