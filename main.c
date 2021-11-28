/* Ini buat main program */
#include <stdio.h>
#include "engine/Exit/exit.h"
#include "engine/Game/Game.h"
#include "engine/Main Menu/menu.h"

void Welcome(){
    printf("Selamat datang di Mobitangga!\n");
}

int main(){
    Welcome();
    MenuView();
    if (selection == 1 || selection == 3){
        GameView(selection);
    } else if (selection == 2){
        exitView();
    }

    return 0;
}