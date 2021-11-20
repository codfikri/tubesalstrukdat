#ifndef _PLAYER_H
#define _PLAYER_H

#include "../skill/skill.h"

/* Player menggunakan circular linked list */
typedef struct player *addressPlayer;
typedef struct player {
    int noUrut;
    char *nama;
    int Petak;
    List Skillpemain;
    addressPlayer next;
} Player;

typedef struct {
    addressPlayer addrFirstPlayer;
} PlayerList;

/*** Selektor ***/
#define Nama(P) P->nama
#define NoUrut(P) P->noUrut
#define Petak(P) P->Petak
#define Skill(P) P->Skillpemain
#define FirstPlayer(P) (P).addrFirstPlayer
#define NextPlayer(p) (p)->next

void CreatePlayerList(PlayerList *P);

boolean isListPlayerEmpty(PlayerList PL);

addressPlayer AlokasiPlayer(char* nama, List Skillpemain, int noUrut);

void insertPlayer(PlayerList *PL, addressPlayer P);

void insertPlayerToList(PlayerList *PL, char *nama, List Skillpemain, int noUrut);

void inputPlayerList(PlayerList *P, int n);

void printPlayer(PlayerList PL);

#endif