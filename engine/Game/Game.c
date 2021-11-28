#include "Game.h"

PlayerList PL;
Stack S;
addressPlayer AP;
boolean isEndGame = false;
boolean isExitGame = false;
boolean isRolled = false;
boolean isEndTurn = false;
int currentPlayer;

void showCommands(){
        printf("Perintah-perintah yang tersedia: \n");
        printf("SKILL: Menampilkan skill yang dimiliki player\n"); //skill
        printf("MAP: Menampilkan map dan posisi player pada map\n"); //map
        printf("BUFF: Menampilkan daftar buff yang dimiliki player\n"); //buff
        printf("INSPECT: Melihat apakah petak n merupakan sebuah teleporter\n"); //inspect
        printf("ROLL: Memutar dadu\n"); //roll
        printf("SAVE: Menyimpan state permainan\n"); //save
        printf("ENDTURN: Mengakhiri giliran\n"); //endturn
        printf("UNDO: Mengembalikan state seperti akhir ronde sebelumnya\n");
        printf("EXIT: Keluar dari permainan\n");
        printf("HELP: Menampilkan perintah-perintah yang tersedia\n");
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
        char exit[] = "EXIT";

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
        } else if (strcmp(cmd, exit) == 0){
                return 10;
        } else {
                return 11;
        }
}

void Turn(addressPlayer AP){
        isEndTurn = false;
        int option, command;
        char cmd[50];
        MapPlayer(PL, PositionToInteger);
        printf("Giliran Player %d untuk Bermain\n", NoUrut(AP));
        printf("Merandom Skill...");
        printf("\n");
        delay(1);
        srand(time(NULL));
        getSkill(&Skill(AP));
        showCommands();
        while (!isEndTurn){
                printf("Masukkan perintah: ");
                scanf("%s", cmd);
                command = getNum(cmd);
                if (command == 1){ // SKILL
                        MenuSkill(AP);
                } else if (command == 2){ // MAP
                        MapPlayer(PL, PositionToInteger);
                } else if (command == 3){ // BUFF
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
                } else if (command == 4){ // INSPECT
                        int petak;
                        printf("Masukkan petak: ");
                        scanf("%d", &petak);
                        inspectPetak(petak);
                } else if (command == 5){ // ROLL
                        STARTROLL(PL,AP,NoUrut(AP));
                        isRolled = true;
                        if (isGameFinished(AP)){
                                isEndGame = true;
                                isExitGame = true;
                        }
                } else if (command == 6){ // SAVE
                        if (isRolled){
                                saveData(PL, currentPlayer);
                        } else {
                                printf("Lakukan Roll terlebih dahulu sebelum melakukan save game!\n");
                        }
                } else if (command == 7){ // END TURN
                        endTurn(AP, isRolled);
                } else if (command == 8){ 
                        if (IsSEmpty || isRolled)
                        {
                                printf("Yes\n");
                                printf("Tidak dapat melakukan Undo\n");
                        }
                        else{
                                printf("No\n");
                                Undo(&S, &PL);
                        }
                } else if (command == 9){
                        showCommands();
                } else if (command == 10){
                        Exit();
                        isExitGame = true;
                } else {
                        printf("Perintah tidak valid! Harap masukan kembali perintah!\n");
                }
        }

}

void gameFinished(addressPlayer AP){
        printf("Selamat! %s telah mencapai finish!\n", Nama(AP));
}

void gameView(int option){
    if (option == 1){
        printf("Let's start the game!\n");
        startNewGame();
    } else if (option == 3){
        Load();
    }
}

int Exit(){
        char prompt[1];
        printf("Yakin ingin keluar dari permainan? [Y/N]: ");
        scanf("%s", prompt);
        if (strcmp(prompt, "Y") == 0 ){
                isEndTurn = true;
                isExitGame = true;
                exitView();
        }
}

void endTurn(addressPlayer AP, boolean isRolled){
        if (isRolled){
                Player X;
                GetPlayer(&X, AP);
                if (NoUrut(AP) == JumlahPlayer(PL)){
                        Push(&S, X);
                        PushUndef;
                }else{
                        Push(&S, X);
                }
                
                isEndTurn = true;
                setAfterTurn(AP);
                printf("nourut %d\n", NoUrut(AP));
                isRolled = false;
 
        } else{
                printf("Lakukan Roll terlebih dahulu sebelum melakukan End Turn!\n");
        }
}

void newGame(){
        CreatePlayerList(&PL);
        boolean isLastPlayer = false;
        int numberOfPlayer;
        printf("Masukan jumlah pemain: ");
        scanf("%d", &numberOfPlayer);
        if (numberOfPlayer < 2 || numberOfPlayer > 4){
                printf("Pemain hanya dapat berjumlah 2, 3, atau 4 orang.\n");
                newGame();
        } else {
                for (int i=1; i<=numberOfPlayer; i++){
                        char playerName[50];
                        printf("PLAYER %d\n", i);
                        printf("Masukan nama pemain: ");
                        scanf("%s", playerName);
                        addressPlayer AP = AlokasiPlayer(i, playerName);
                        if (i==numberOfPlayer){
                                isLastPlayer = true;
                        }
                        strcpy(Nama(AP), playerName);
                        insertPlayer(&PL, AP, isLastPlayer);
                        }
                printPlayer(PL, numberOfPlayer);
                setJumlahPlayer(&PL, numberOfPlayer);
        }
        
}

void startNewGame(){
        SCreateEmpty(&S);
        newGame();
        printf("\n");
        printf("Membaca konfigurasi...\n");
        startConfig();
        updatePosition(PL, &PositionToInteger);
        delay(3);
        printf("Pembacaan Selesai.\n");
        printf("Selamat Bermain!\n");
        addressPlayer AP = FirstPlayer(PL);
        currentPlayer = NoUrut(AP);
        while (!isExitGame && !isEndGame){
                Turn(AP);
                if (isEndTurn){
                        AP = NextPlayer(AP);
                        currentPlayer = NoUrut(AP);
                }
        }
        if (isEndGame){
                gameFinished(AP);
        }
}

boolean isGameFinished(addressPlayer AP){
        return Petak(AP) == lengthMap;
}

void startConfig(){
        STARTGAME("data/map.txt");
        lengthMap = KataTOInteger(CKata);
        ADVKATA();

        /*Membaca peta*/
        MakeEmpty(&Map);
        SetNeff(&Map, lengthMap);
        setMap(CKata, &Map, lengthMap);
        ADVKATA();

        /*Membaca MaxRoll*/
        maxRoll = KataTOInteger(CKata);
        ADVKATA();

        /*Membaca banyaknya teleporter pada map*/
        countTel = KataTOInteger(CKata);
        ADVKATA();

        /*Membaca destinasi teleporter*/
        for (int i= 0; i< countTel; i++){
                int temp1 = KataTOInteger(CKata);
                ADVKATA();
                int temp2 = KataTOInteger(CKata);
                ADVKATA();
                LT.T[i].src = temp1;
                LT.T[i].dest = temp2;
        }
}

void Load(){
        SCreateEmpty(&S);
        LoadFile(&PL, &currentPlayer);
        printf("\n");
        printf("Membaca konfigurasi...\n");
        startConfig();
        updatePosition(PL, &PositionToInteger);
        delay(3);
        printf("Pembacaan Selesai.\n");
        printf("Selamat Bermain!\n");

        addressPlayer AP = getIndexPlayer(currentPlayer, PL);
        while (!isExitGame && !isEndGame){
                Turn(AP);
                if (isEndTurn){
                        AP = NextPlayer(AP);
                        currentPlayer = NoUrut(AP);
                }
        }
        if (isEndGame){
                gameFinished(AP);
        }
}

addressPlayer getIndexPlayer(int currentPlayer, PlayerList PL){
        addressPlayer P = FirstPlayer(PL);
        while (NoUrut(P) != (currentPlayer + 1)){
                P = NextPlayer(P);
        }
        return P;
}