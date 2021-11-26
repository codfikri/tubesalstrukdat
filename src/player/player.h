#ifndef _PLAYER_H
#define _PLAYER_H

#include "../skill/listlinier.h"
#include <stdio.h>
#include <stdlib.h>

/* Player menggunakan circular linked list */
typedef struct player *addressPlayer;
typedef struct player {
    int noUrut;
    char *nama;
    int Petak;
    List Skillpemain;
    boolean isImmune;
    boolean isHokiKecil;
    boolean isHokiBesar;
    boolean isPostCermin;
    addressPlayer next;
} Player;

typedef struct {
    int jumlahPlayer;
    addressPlayer addrFirstPlayer;
} PlayerList;

/*** Selektor ***/
#define Nama(P) P->nama
#define NoUrut(P) P->noUrut
#define Petak(P) P->Petak
#define Skill(P) P->Skillpemain
#define isImmune(P) P->isImmune
#define isHokiKecil(P) P->isHokiKecil
#define isHokiBesar(P) P->isHokiBesar
#define isPostCermin(P) P->isPostCermin
#define NextPlayer(p) (p)->next
#define FirstPlayer(P) (P).addrFirstPlayer
#define JumlahPlayer(P) (P).jumlahPlayer

void setJumlahPlayer(PlayerList *PL, int jumlah);

void CreatePlayerList(PlayerList *P);

boolean isListPlayerEmpty(PlayerList PL);

addressPlayer AlokasiPlayer(int noUrut, char* playerName);

void insertPlayer(PlayerList *PL, addressPlayer P, boolean isLastPlayer);

void inputPlayerList(PlayerList *P, int n);

void printPlayer(PlayerList PL, int n);

addressPlayer AlokasiUpdatePlayer(Player P);

void GetPlayer(Player* X, addressPlayer AP);

void insertUpdatePlayerToList(PlayerList *PL, Player P, boolean isLastPlayer);

#endif
