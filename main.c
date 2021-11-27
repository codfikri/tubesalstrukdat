/* Ini buat main program */
#include <stdio.h>
#include "engine/Exit/exit.h"
#include "engine/Game/Game.h"
#include "engine/Main Menu/menu.h"

void initial(){
    MenuView();
    if (selection != 0){
        // GameView(selection);
        initial();
    }
}

int main(){
    initial();
    exitView();

    return 0;
}