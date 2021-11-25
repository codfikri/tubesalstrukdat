#include "giliran.h"

void showCommands(){
        printf("Perintah-perintah yang tersedia: \n");
        printf("[1] SKILL\n"); //skill
        printf("[2] use skill\n"); //skill
        printf("[3] show buff\n"); //buff
        printf("[4] inspect map\n"); //inspect
        printf("[5] show position\n"); //map
        printf("[6] undo\n"); //undo
        printf("[7] end turn\n"); //endturn
        printf("[0] exit game\n");
}

int getNum(char *cmd){
        char skill[] = "SKILL";
        char map[] = "MAP";
        char buff[] = "BUFF";
        char inspect[] = "INSPECT";
        char roll[] = "ROLL";
        char save[] = "SAVE";
        char end[] = "ENDTURN";
        char undo[] = "UNDO";

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
        } else if (strcmp(cmd,end) == 0){
                return 7;
        } else if (strcmp(cmd,undo) == 0){
                return 8;
        } else {
                return 9;
        }
}

void convertToCommand(int n){
        PlayerList PL;
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