/* *** Definisi ABSTRACT DATA TYPE TELEPORTER *** */

#ifndef TELEPORTER_H
#define TELEPORTER_H

#include "boolean.h"
#include "array.h"

#define NMAX 100

typedef struct{
    int src;    int dest;
} Teleporter;

typedef struct{
    Teleporter T[NMAX];
} ListTeleporter;

extern int countTel;
extern ListTeleporter LT;
extern Teleporter *Tel;

void createTeleporter(int n, int m);
//Membuat Teleporter

boolean isPetakTeleport(int n);
//Mengembalikan true apabila petak memiliki teleport

int srcTeleporter(int n);
 //mengembalikan nilai int asal dari sebuah teleport

int destTeleporter(int n);
//mengembalikan nilai int destinasi dari sebuah teleport

#endif