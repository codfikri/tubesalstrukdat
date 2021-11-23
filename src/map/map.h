#ifndef MAP_H
#define MAP_H

#include "player.h"
#include "player.c"
#include "array.h"
#include "array.c"
#include "arrayint.c"
#include "arrayint.h"
#include "boolean.h"

int updatePosition(PlayerList PL, TabInt *PositionToInteger);
//Menampilkan posisi petak seorang pemain dalam bentuk integer

int MapPlayer(PlayerList PL, TabChar Map, TabInt PositionToInteger);
//Menampilkan current map dari player
//Petak yang ditempati player ditandai dengan  karakter "*"

int CheckPlayerPosition(int nPlayer ,TabInt PositionToInteger);
#endif