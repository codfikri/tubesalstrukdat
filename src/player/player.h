#ifndef PLAYER_H
#define PLAYER_H
#include "boolean.h"
#include "skill.h"

typedef struct player{
    int Petak;
    List Skillpemain;
} Player;

void CreatePlayer (Player *P);

void addSkillPlayer(Player *P, List L);

#endif