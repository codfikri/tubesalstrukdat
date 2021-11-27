#include <stdio.h>
#include <unistd.h>
#include "load.h"
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
    JumlahPlayer(*LP) = n;
    ADVKATA();
    printf("%d\n", n);
    for (int i = 0; i < n; i++){
        strcpy(P.nama, KataToChar(CKata));
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

