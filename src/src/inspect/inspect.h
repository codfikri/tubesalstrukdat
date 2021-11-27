#ifndef inspect_h
#define inspect_h

#include "../teleporter/teleporter.h"

extern TabChar Map;
extern int lengthMap;

#define terlarang '#'

boolean isPetakTerlarang(int petak);
/* 
Mengirimkan True jika petak adalah petak terlarang
Petak terlarang ditandai dengan karakter "#"
*/
void inspectPetak(int petak);
/*
Mengirimkan nilai petak
Petak dapat terdefinisi sebagai petak kosong, petak terlarang, atau teleporter
Petak terlarang ditandai dengan karakter "#"
Petak kosong ditandai dengan karakter "."
Petak adalah teleporter apabila terdapat teleporter yang tersimpan pada List Teleporter pada petak tersebut
*/
#endif