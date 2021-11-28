#include "Menu.h"

int selection = -1;

void MenuView() {
    int select = -9;
    printf("Pilihan Menu: \n");
    printf("[1]. New Game\n");
    printf("[2]. Exit\n");
    printf("[3]. Load Game\n");
    printf("Masukan pilihan: ");
    scanf("%d", &select);
    printf("\n");
    selection = select;
}