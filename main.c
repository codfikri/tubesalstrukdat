/* Ini buat main program */
#include <stdio.h>
#include "engine/Exit/exit.h"
#include "engine/Game/Game.h"
#include "engine/Mainmenu/menu.h"

void Welcome(){
    printf("Selamat datang di Mobitangga!\n");
}

int main(){
    Welcome();
    MenuView();
    if (selection == 1 || selection == 3){
        gameView(selection);
    } else if (selection == 2){
        exitView();
    }
    return 0;
}