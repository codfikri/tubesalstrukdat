#ifndef inspect_h
#define inspect_h

#include "teleporter.h"

boolean isPetakTerlarang(int petak, char map[100]);
/* 
Mengirimkan True jika petak adalah petak terlarang
Petak terlarang ditandai dengan karakter "#"
*/
int inspectPetak(int petak, ListTeleporter LT , int countTel, char map[100], int lengthmap);
/*
Mengirimkan nilai petak
Petak dapat terdefinisi sebagai petak kosong, petak terlarang, atau teleporter
Petak terlarang ditandai dengan karakter "#"
Petak kosong ditandai dengan karakter "."
Petak adalah teleporter apabila terdapat teleporter yang tersimpan pada List Teleporter pada petak tersebut
*/
#endif