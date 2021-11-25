#include "Game.h"

void showCommands(){
        printf("Perintah-perintah yang tersedia: \n");
        printf("[1] SKILL: Menampilkan skill yang dimiliki player\n"); //skill
        printf("[2] MAP: Menampilkan map dan posisi player pada map\n"); //map
        printf("[3] BUFF: Menampilkan daftar buff yang dimiliki player\n"); //buff
        printf("[4] INSPECT: Melihat apakah petak n merupakan sebuah teleporter\n"); //inspect
        printf("[5] ROLL: Memutar dadu\n"); //roll
        printf("[6] SAVE: Menyimpan state permainan\n"); //save
        printf("[7] ENDTURN: Mengakhiri giliran\n"); //endturn
        printf("[8] UNDO: Mengembalikan state seperti akhir ronde sebelumnya\n");
        printf("[0] HELP: Menampilkan perintah-perintah yang tersedia\n");
}

int getNum(char *cmd){
        char skill[] = "SKILL";
        char map[] = "MAP";
        char buff[] = "BUFF";
        char inspect[] = "INSPECT";
        char roll[] = "ROLL";
        char save[] = "SAVE";
        char endturn[] = "ENDTURN";
        char undo[] = "UNDO";
        char help[] = "HELP";

        if (strcmp(cmd,skill) == 0) {
                return 1;
        } else if (strcmp(cmd,map) == 0){
                return 2;
        } else if (strcmp(cmd,buff) == 0){
                return 3;
        } else if (strcmp(cmd,inspect) == 0){
                return 4;
        } else if (strcmp(cmd,roll) == 0){
                return 5;
        } else if (strcmp(cmd,save) == 0){
                return 6;
        } else if (strcmp(cmd,endturn) == 0){
                return 7;
        } else if (strcmp(cmd,undo) == 0){
                return 8;
        } else if (strcmp(cmd,help) == 0){
                return 9;
        } else {
                return 10;
        }
}

void gameView(int option){
    if (option == 1){
        // New Game
    } else if (option == 2){
        // Load Game
    }
}

void startGame(){
        PlayerList PL;
        CreatePlayerList(&PL);
        InputAllPlayer(&PL);
        TabChar Map;
        TabInt PositionTOInteger;
        ListTeleporter LT;
        int countTel;
        int maxRoll;
        int nPlayer;
        int countTel;
        int lengthMap;

        switch (n)
        {
        case 1:
                // Skill
                break;
        case 2:
                // Map
                break;
        case 3:
                // Buff
                break;
        case 4: 
                int petak;
                printf("Masukkan petak: \n");
                scanf("%d", &petak);
                inspectPetak(petak, LT, countTel, Map, lengthMap);
                break;
        case 5:
                // Roll
                boolean isRolled = false;
                //Roll, isRolled = true;
                break;
        case 6:
                // Save
                break;
        case 7:
                // EndTurn
                endTurn(AP, PL, isRolled);
                break;
        case 8:
                // Undo
                break;
        case 9:
                showCommands();
                break;
        default:
                printf("Command tidak valid!\n");
                break;
        }
}

void endTurn(addressPlayer AP, PlayerList PL, boolean isRolled){
        if (!isRolled){
                print("Lakukan Roll terlebih dahulu sebelum melakukan End Turn!\n");
        } else{
                // Push(&S, PL);
                AP = Next(AP);
        }
}

int mundur(int n, int m){
    return n-m;
}

int maju(int n, int m){
    return n+m;
}