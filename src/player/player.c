#include <stdio.h>
#include <stdlib.h>
#include "player.h"

void CreatePlayer (Player *P){
    (*P).Petak = 1;
}

void addSkillPlayer(Player *P, List L){
    (*P).Skillpemain = L;
}