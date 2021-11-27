#include "player.h"

#define Nil NULL

void CreatePlayerList(PlayerList *P){ //sama kaya CreateEmpty pada List
    FirstPlayer(*P) = Nil;
}

boolean isListPlayerEmpty(PlayerList PL){ //sama kaya IsEmpty pada list
    return FirstPlayer(PL)==Nil;
}

addressPlayer AlokasiPlayer(int noUrut, char* playerName){ //sama kaya Alokasi pada list
    addressPlayer AP;
    List L;
    CreateEmpty(&L);
    AP = (addressPlayer) malloc(sizeof(Player));
    if (AP != Nil){
        Petak(AP) = 1;
        NoUrut(AP) = noUrut;
        Skill(AP) = L;
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
        // Nama(AP) = P.nama;
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

void insertPlayer(PlayerList *PL, addressPlayer P, boolean isLastPlayer){ //sama kaya InsertLast pada list
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
    if (isLastPlayer){
        NextPlayer(P) = FirstPlayer(*PL);
    }
}

void inputPlayerList(PlayerList *PL, int n){
    boolean isLastPlayer = false;
    char* playerName;
    for (int i=1; i<=n; i++){
        printf("PLAYER %d\n", i);
        addressPlayer AP = AlokasiPlayer(i, playerName);
        printf("Masukan nama pemain: \n");
        scanf("%s", playerName);
        if (i==n){
            isLastPlayer = true;
        }
        printf("%s", Nama(AP));
        insertPlayer(PL, AP, isLastPlayer);
    }
}

void setJumlahPlayer(PlayerList *PL, int jumlah){
    JumlahPlayer(*PL) = jumlah;
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
            printf("Nama pemain %d adalah %s\n", NoUrut(P), Nama(P));
            P = NextPlayer(P);
            i++;
        }
    }
}

void GetPlayer(Player* X, addressPlayer AP)
{
    // (*X).nama = Nama(AP);
    (*X).noUrut = NoUrut(AP) ;
    (*X).Petak = Petak(AP);
    (*X).Skillpemain = Skill(AP);
    (*X).isImmune = isImmune(AP);
    (*X).isHokiKecil = isHokiKecil(AP);
    (*X).isHokiBesar = isHokiBesar(AP);
    (*X).isPostCermin = isPostCermin(AP);
    (*X).next = NextPlayer(AP);
}

void insertUpdatePlayerToList(PlayerList *PL, Player P, boolean isLastPlayer){ //sama kaya InsVlast pada list
    addressPlayer AP;
    AP = AlokasiUpdatePlayer(P);
    if (AP != Nil){
        insertPlayer(PL, AP, isLastPlayer);
        if (isLastPlayer){
            NextPlayer(AP) = FirstPlayer(*PL);
        }
    }
}
