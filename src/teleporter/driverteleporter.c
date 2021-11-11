#include <stdio.h>
#include "teleporter.h"

// Ini buat ngetes fungsi teleporter jalan apa engga

int main(){
    int i, n, m, countTel;
    Teleporter T;
    ListTeleporter LT;
    printf("Masukan jumlah teleporter: ");
    scanf("%d", &countTel);
    i = 0;
    while (i < countTel){
        scanf("%d %d", &n, &m);
        createTeleporter(n, m, &T);
        LT.T[i] = T;
        i++;
    }
    return 0;    
}