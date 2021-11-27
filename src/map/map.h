#ifndef MAP_H
#define MAP_H

#include "../player/player.h"
#include "../array/array.h"
#include "arrayint.h"

#define Nil NULL
int updatePosition(PlayerList PL, TabInt *PositionToInteger);
//Menampilkan posisi petak seorang pemain dalam bentuk integer

void MapPlayer(PlayerList PL, TabChar Map, TabInt PositionToInteger);
//Menampilkan current map dari player
//Petak yang ditempati player ditandai dengan  karakter "*"

int CheckPlayerPosition(int nPlayer ,TabInt PositionToInteger);
#endif