#include "player.h"

#define Nil NULL

void CreatePlayerList(PlayerList *P){ //sama kaya CreateEmpty pada List
    FirstPlayer(*P) = Nil;
}

boolean isListPlayerEmpty(PlayerList PL){ //sama kaya IsEmpty pada list
    return FirstPlayer(PL)==Nil;
}

addressPlayer AlokasiPlayer(char* nama, List Skillpemain, int noUrut){ //sama kaya Alokasi pada list
    addressPlayer AP;
    AP = (Player *) malloc(sizeof(Player));
    if (AP != Nil){
        Petak(AP) = 1;
        NoUrut(AP) = noUrut;
        Nama(AP) = nama;
        Skill(AP) = Skillpemain;
        NextPlayer(AP) = Nil;
    } else {
        return Nil;
    }
    return AP;
}

void insertPlayer(PlayerList *PL, addressPlayer P){ //sama kaya InsertLast pada list
    addressPlayer last;
    if (isListPlayerEmpty(*PL)){
        NextPlayer(P) = FirstPlayer(*PL);
        FirstPlayer(*PL) = P;
    } else{
        last = FirstPlayer(*PL);
        while(NextPlayer(last) != Nil){
            last = NextPlayer(last);
        }
        NextPlayer(last) = P;
    }
}

void insertPlayerToList(PlayerList *PL, char* nama, List Skillpemain, int noUrut){ //sama kaya InsVlast pada list
    addressPlayer P;
    P = AlokasiPlayer(nama, Skillpemain, noUrut);
    if (P != Nil){
        insertPlayer(PL, P);
    }
}

void inputPlayerList(PlayerList *P, int n){
    char playerName[16];
    List L;
    CreateEmpty(&L);
    for (int i=1; i<=n; i++){
        printf("Masukan nama pemain ke-%d: ", i);
        scanf("%s", playerName);
        insertPlayerToList(P, playerName, L, i);
    }
}

void printPlayer(PlayerList PL){ //sama kaya printForward di list
    if (isListPlayerEmpty(PL)){printf("List player masih kosong");}
    else{
        addressPlayer P;
        P = FirstPlayer(PL);
        while (P != Nil){
            printf("Pemain ke %d telah terdaftar\n", NoUrut(P));
            printf("Pemain ke %d berada pada petak %d\n", NoUrut(P), Petak(P));
            P = NextPlayer(P);
        }
    }
}