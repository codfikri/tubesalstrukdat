#include "roll.h"
#include "../konfigurasi/mesinkar.h"
#include "../konfigurasi/mesinkata.h"
#include "../teleporter/teleporter.h"
#include "../inspect/inspect.h"

int main(){
    /*Membaca panjang peta*/
    // TabChar Map;
    STARTGAME("map.txt");
    lengthMap = KataTOInteger(CKata);
    ADVKATA();

    /*Membaca peta*/
    MakeEmpty(&Map);
    SetNeff(&Map, lengthMap);
    setMap(CKata, &Map, lengthMap);
    ADVKATA();
    printf("%d\n", lengthMap);

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
    PlayerList PL;
    CreatePlayerList(&PL);
    List Skill1;
    List Skill2;
    List Skill3;
    List Skill4;
    CreateEmpty(&Skill1);
    CreateEmpty(&Skill2);
    CreateEmpty(&Skill3);
    CreateEmpty(&Skill4);
    char *nama1 = "orang1";          
    char *nama2 = "orang2";         
    char *nama3 = "orang3";         
    char *nama4 = "orang4";
    int urut1 = 1;
    int urut2 = 2;
    int urut3 = 3;
    int urut4 = 4;
    addressPlayer AP1 = AlokasiPlayer(urut1, nama1);
    strcpy(Nama(AP1), nama1);
    Petak(AP1) = 10;
    addressPlayer AP2 = AlokasiPlayer(urut2, nama2);
    strcpy(Nama(AP2), nama2);
    Petak(AP2) = 10;
    addressPlayer AP3 = AlokasiPlayer(urut3, nama3);
    strcpy(Nama(AP3), nama3);
    Petak(AP3) = 18;
    addressPlayer AP4 = AlokasiPlayer(urut4, nama4);
    strcpy(Nama(AP4), nama4);

    insertPlayer(&PL, AP1, false);
    insertPlayer(&PL, AP2, false);
    insertPlayer(&PL, AP3, false);
    insertPlayer(&PL, AP4, true);
    
    printf("%s\n", Nama(AP1));
    printf("%s\n", Nama(AP2));
    printf("%s\n", Nama(AP3));
    printf("%s\n", Nama(AP4));
    printf("countel %d\n", countTel);
    printf("maxroll %d\n", maxRoll);
    printf("dest %d\n", LT.T[3].dest);
    // insertPlayerToList(&PL, nama1, Skill1, urut1, false);
    // insertPlayerToList(&PL, nama2, Skill1, urut2, false);
    // insertPlayerToList(&PL, nama3, Skill1, urut3, false);
    // insertPlayerToList(&PL, nama4, Skill1, urut4, true);

    printf("indeks tele 6: %d\n", getIdxTeleporter(6));
    printf("indeks tele 13: %d\n", getIdxTeleporter(13));
    makeEmpty(&PositionToInteger);
    updatePosition(PL, &PositionToInteger);
    MapPlayer(PL, PositionToInteger);
    STARTROLL(PL, AP1, urut1);
   
    STARTROLL(PL, AP1, urut1);
    
    STARTROLL(PL, AP1, urut1);
    
} 