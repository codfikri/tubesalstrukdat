#include <stdio.h>
#include <stdlib.h>
#include "stack.h"

int main ()
{
    StackPlayer S;
    Player P1, P2;
    int temp;
    addressStack A1, A2;
    CreateEmptyStack(&S);
    printf("isSEmpty? : %d\n", IsEmptyStack(S));
    CreatePlayer(&P1);
    CreatePlayer(&P2);
    temp = 1;
    PushUndef(&S);
    while (temp < 10)
    {
        Push( &S,P1);
        printf("infotopplayer : %d\n", (InfoTopPlayer(S)).Petak);
        temp = P1.Petak;
        Push( &S,P2);
        printf("infotopplayer : %d\n", (InfoTopPlayer(S)).Petak);
        temp = P2.Petak;
        PushUndef(&S);
        printf("infotopplayer : %d\n", (InfoTopPlayer(S)).Petak);

        (P1).Petak = (P1).Petak + 2;
        (P2).Petak = (P2).Petak + 5;

    }
    printf("Before\n");
    A1 = next(TopPlayer(S));
    A2 = next(A1);

    (P1) = info(A1);
    (P2) = info(A2);

    printf("Petak1: %d\n", (P2).Petak);
    printf("Petak2: %d\n", (P1).Petak);
    Undo(&S);
    printf("infotopplayer : %d\n", (InfoTopPlayer(S)).Petak);
    A1 = next(TopPlayer(S));
    A2 = next(A1);

    (P1) = info(A1);
    (P2) = info(A2);

    printf("Petak1: %d\n", (P2).Petak);
    printf("Petak2: %d\n", (P1).Petak);
    return 0;
}
