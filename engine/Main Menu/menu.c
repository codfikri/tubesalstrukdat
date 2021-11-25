#include "Menu.h"

int selection = -1;

void MenuView() {
    int select = -9;
    printf("Pilihan Menu: \n");
    printf("[0].Exit\n");
    printf("[1].New Game\n");
    printf("[2].Load Game\n");
    printf("Masukan pilihan: ");
    scanf("%d", &select);
    printf("\n");
    selection = select;
}