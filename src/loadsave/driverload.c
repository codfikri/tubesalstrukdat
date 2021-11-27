#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include "../player/player.h"

int main() {
    PlayerList PL;
    addressPlayer P;
    LoadFile(&PL);
    int i= 1;
    int n = 4;
    P = FirstPlayer(PL);
    printPlayer(PL, n);
    
    return 0;
}
