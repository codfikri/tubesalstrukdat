#ifndef inspect_h
#define inspect_h

#include "teleporter.h"
#include "array.h"
#include "array.c"

#define terlarang '#'

boolean isPetakTerlarang(int petak, TabChar Map);
/* 
Mengirimkan True jika petak adalah petak terlarang
Petak terlarang ditandai dengan karakter "#"
*/
int inspectPetak(int petak, ListTeleporter LT , int countTel, TabChar Map, int lengthMap);
/*
Mengirimkan nilai petak
Petak dapat terdefinisi sebagai petak kosong, petak terlarang, atau teleporter
Petak terlarang ditandai dengan karakter "#"
Petak kosong ditandai dengan karakter "."
Petak adalah teleporter apabila terdapat teleporter yang tersimpan pada List Teleporter pada petak tersebut
*/
#endif