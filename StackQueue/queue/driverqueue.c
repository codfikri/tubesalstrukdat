#include <stdio.h>
#include "queue.h"
#include "../boolean.h"

#include <stdlib.h>

int main(){
	Queue Q;
    Player P1, P2;
	QCreateEmpty(&Q,2);
	printf("isEmpty? : %d\n", IsQEmpty(Q));
    CreatePlayer(&P1);
    CreatePlayer(&P2);
	printf("Add 1, ");
	Add(&Q, P1);
    printf("Add 2, ");
	Add(&Q, P2);
	printf("\n");
    printf("isFull? : %d\n", IsQFull(Q));
    printf("QNBElmt? : %d\n", QNBElmt(Q));

    infoqueue X;
    Del (&Q, &X);
    printf("Del? : %d\n", X);
    Del (&Q, &X);
    printf("Del? : %d\n", X);
    printf("Dealokasi : ");
    QDeAlokasi(&Q);
    if(QMaxEl(Q) == 0)
    {
        printf("Terdealokasi\n");
    }
    return 0;
}