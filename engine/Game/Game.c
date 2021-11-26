#include "Game.h"

PlayerList PL;
Stack S;
boolean isEndGame = false;

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

void Turn(addressPlayer AP){
        boolean isRolled = false;
        boolean isEndTurn = false;
        int option, command;
        char* cmd;
        // Print Map Player
        printf("Giliran Player %d untuk Bermain\n", NoUrut(AP));
        printf("Merandom Skill...");
        printf("\n");
        delay(100);
        getSkill(&Skill(AP));
        //printf("Anda mendapatkan skill %s", )
        showCommands();
        while (!isEndGame && !isEndTurn){
                printf("Masukkan perintah: ");
                scanf("%s", cmd);
                command = getNum(cmd);
                if (command == 1){
                        MenuSkill(AP);
                } else if (command == 2){
                        // MapPlayer()
                } else if (command == 3){
                        if (isImmune(AP)){
                                printf("Anda memiliki buff imunitas teleport!\n");
                        } else {printf("Anda tidak immune terhadap teleport!\n");}
                        if (isHokiKecil(AP)){
                                printf("Buff Senter Pengecil Hoki sedang aktif pada diri Anda!\n");
                        } else{ printf("Buff Senter Pengecil Hoki sedang tidak aktif pada diri Anda!\n");}
                        if (isHokiBesar(AP)){
                                printf("Buff Senter Pembesar Hoki sedang aktif pada diri Anda!\n");
                        } else {printf("Buff Senter Pembesar Hoki sedang tidak aktif pada diri Anda!\n");}
                        if (isPostCermin(AP)){
                                printf("Anda sudah menggunakan Cermin Pengganda pada ronde ini!\n");
                        } else {printf("Anda belum menggunakan Cermin Pengganda pada ronde ini!\n");}
                } else if (command == 4){
                        // InspectPetak();
                } else if (command == 5){
                        // startroll
                        isRolled = true;
                        /* check posisi dia udh sampe akhir apa blm,
                        kalo udah, isEndGame = true */
                        /* if (isEndGame){
                                gameFinished(AP);
                        } */
                } else if (command == 6){
                        // save
                } else if (command == 7){
                        if (!isRolled){
                                printf("Player tidak dapat melakukan End Turn karena belum melakukan Roll!\n");
                        } else {
                                setAfterTurn(AP);
                                isEndTurn = true;
                                AP = NextPlayer(AP);
                        }
                } else if (command == 8){
                        endTurn(AP, isRolled);
                } else if (command == 9){
                        showCommands();
                } else {
                        printf("Perintah tidak valid!\n");
                }
        }

}

void gameFinished(addressPlayer AP){
        printf("Selamat! %s telah mencapai finish!\n", Nama(AP));
}

void gameView(int option){
    if (option == 1){
        // New Game
    } else if (option == 2){
        // Load Game
    }
}

void endTurn(addressPlayer AP, boolean isRolled){
        if (!isRolled){
                print("Lakukan Roll terlebih dahulu sebelum melakukan End Turn!\n");
        } else{
                Player X;
                GetPlayer(&X, AP);
                if (NoUrut(AP) == JumlahPlayer(PL)){
                        Push(&S, X);
                        PushUndef;
                }else{
                        Push(&S, X);
                }
                setAfterTurn(AP);
                AP = Next(AP);
        }
}

void newGame(){
        CreatePlayerList(&PL);
        char* playerName;
        boolean isLastPlayer = false;
        int numberOfPlayer;
        printf("Masukan jumlah pemain: ");
        scanf("%d", &numberOfPlayer);
        if (numberOfPlayer < 2 || numberOfPlayer > 4){
                printf("Pemain hanya dapat berjumlah 2, 3, atau 4 orang.\n");
                newGame();
        } else {
                for (int i=1; i<=numberOfPlayer; i++){
                        printf("PLAYER %d\n", i);
                        printf("Masukan nama pemain: ");
                        scanf("%s", playerName);
                        addressPlayer AP = AlokasiPlayer(i, playerName);
                        if (i==numberOfPlayer){
                                isLastPlayer = true;
                        }
                        insertPlayer(&PL, AP, isLastPlayer);
                        }
                printPlayer(PL, numberOfPlayer);
        }
}

void startNewGame(){
        SCreateEmpty(&S);
        newGame();
        addressPlayer AP = FirstPlayer(PL);
        while (!isEndGame){
                Turn(AP);
        }

}