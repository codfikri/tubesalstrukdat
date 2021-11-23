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
        isImmune(AP) = false;
        isHokiBesar(AP) = false;
        isHokiKecil(AP) = false;
        isPostCermin(AP) = false;
        NextPlayer(AP) = Nil;
    } else {
        return Nil;
    }
    return AP;
}

addressPlayer AlokasiUpdatePlayer(Player P){ //sama kaya Alokasi pada list
    addressPlayer AP;
    AP = (Player *) malloc(sizeof(Player));
    if (AP != Nil){
        Petak(AP) = P.Petak;
        NoUrut(AP) = P.noUrut;
        Nama(AP) = P.nama;
        Skill(AP) = P.Skillpemain;
        isImmune(AP) = P.isImmune;
        isHokiBesar(AP) = P.isHokiBesar;
        isHokiKecil(AP) = P.isHokiKecil;
        isPostCermin(AP) = P.isPostCermin;
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

void insertPlayerToList(PlayerList *PL, char* nama, List Skillpemain, int noUrut, boolean isLastPlayer){ //sama kaya InsVlast pada list
    addressPlayer P;
    P = AlokasiPlayer(nama, Skillpemain, noUrut);
    if (P != Nil){
        insertPlayer(PL, P);
        if (isLastPlayer){
            NextPlayer(P) = FirstPlayer(*PL);
        }
    }
}

void insertUpdatePlayerToList(PlayerList *PL, Player P, boolean isLastPlayer){ //sama kaya InsVlast pada list
    addressPlayer AP;
    AP = AlokasiUpdatePlayer(P);
    if (AP != Nil){
        insertPlayer(PL, AP);
        if (isLastPlayer){
            NextPlayer(AP) = FirstPlayer(*PL);
        }
    }
}

void inputPlayerList(PlayerList *P, int n){
    char playerName[16];
    List L;
    boolean isLastPlayer = false;
    CreateEmpty(&L);
    for (int i=1; i<=n; i++){
        printf("Masukan nama pemain ke-%d: ", i);
        scanf("%s", playerName);
        if (i==n){
            isLastPlayer = true;
        }
        insertPlayerToList(P, playerName, L, i, isLastPlayer);
    }
}

void printPlayer(PlayerList PL, int n){ //sama kaya printForward di list
    if (isListPlayerEmpty(PL)){printf("List player masih kosong");}
    else{
        addressPlayer P;
        P = FirstPlayer(PL);
        int i = 1;
        while (i <= n){
            printf("Pemain ke %d telah terdaftar\n", NoUrut(P));
            printf("Pemain ke %d berada pada petak %d\n", NoUrut(P), Petak(P));
            P = NextPlayer(P);
            i++;
        }
    }
}

void GetPlayer(Player* X, addressPlayer AP)
{
    (*X).nama = Nama(AP);
    (*X).noUrut = NoUrut(AP) ;
    (*X).Petak = Petak(AP);
    (*X).Skillpemain = Skill(AP);
    (*X).isImmune = isImmune(AP);
    (*X).isHokiKecil = isHokiKecil(AP); 
    (*X).isHokiBesar = isHokiBesar(AP);
    (*X).isPostCermin = isPostCermin(AP); 
    (*X).next = NextPlayer(AP);
}

void UpdatePetak(addressPlayer AP, int x)
{
    Petak(AP) = x;
}

