#include <stdio.h>
#include <unistd.h>
#include "loadsave.h"
#include "../konfigurasi/mesinkar.h"
#include "../konfigurasi/mesinkata.h"
/*#include "../teleporter & inspect/ inspect.h"*/
#include "../player/player.h"
#include "../skill/skill.h"


void LoadFile(PlayerList * LP)
{
    int n, jumlahskill, skill;
    char input[200] = "savefile/";
    Player P;
    boolean isLastPlayer;
    printf("Masukkan nama file : ");
    scanf("%s", input + 9);
    
    STARTGAME(input);

    CreatePlayerList(LP);
    isLastPlayer = false;
    n = KataTOInteger(CKata);
    ADVKATA();
    printf("%d\n", n);
    for (int i = 0; i < n; i++){
        P.nama = KataToChar(CKata);
        ADVKATA();
        P.Petak = KataTOInteger(CKata);
        ADVKATA();
        P.noUrut = KataTOInteger(CKata);
        ADVKATA();
        jumlahskill = KataTOInteger(CKata);
        ADVKATA();
        CreateEmpty (&P.Skillpemain);
        for(int j = 0; j< jumlahskill ; j++){
            printf("tes\n");
            skill = KataTOInteger(CKata);
            InsVLast (&P.Skillpemain, skill);
            ADVKATA();
        }
        P.isImmune = KataTOInteger(CKata);
        ADVKATA();
        P.isHokiKecil = KataTOInteger(CKata);
        ADVKATA();
        P.isHokiBesar = KataTOInteger(CKata);
        ADVKATA();
        P.isPostCermin = KataTOInteger(CKata);
        ADVKATA();
        P.next = Nil;
        if (i == n-1){
            isLastPlayer = true;    
        }
        insertUpdatePlayerToList(LP,P,isLastPlayer);
    }
}

void saveData(PlayerList PL)
{
    int n, jumlahskill;
    
    char input[100] = "savefile/";
    addressPlayer AP;
    printf("Enter the name of your save file (without .txt/.dat) : ");
    scanf("%s", input + 9);
    FILE *fp = fopen(input, "w");
    n = JumlahPlayer(PL);
    fprintf(fp, "%d\n", n);
    AP = FirstPlayer(PL);
    for (int i = 0; i < n; i++){
        fprintf(fp, "%c\n", Nama(AP));
        fprintf(fp, "%d\n", Petak(AP));
        fprintf(fp, "%d\n", NoUrut(AP));
        jumlahskill = NbElmt(Skill(AP));
        fprintf(fp, "%d\n", jumlahskill);
        address AS = First(Skill(AP));
        for (int j = 0; j <jumlahskill; j++)
        {

            fprintf(fp, "%d\n", Info(AS));
            AS = Next(AS);
        }
        fprintf(fp, "%d\n", isImmune(AP));
        fprintf(fp, "%d\n", isHokiKecil(AP));
        fprintf(fp, "%d\n", isHokiBesar(AP));
        fprintf(fp, "%d\n", isPostCermin(AP));
        AP = NextPlayer(AP);
    }
    fprintf(fp, ";\n");

    fclose(fp);

    printf("File berhasil disimpan!\n");
}