/* *** Definisi ABSTRACT DATA TYPE TELEPORTER *** */

#ifndef TELEPORTER_H
#define TELEPORTER_H

#include "boolean.h"
#include "array.h"

#define NMAX 100

typedef struct{
    int src;
    int dest;
} Teleporter;

typedef struct{
    Teleporter T[NMAX];
} ListTeleporter;

void createTeleporter(int n, int m, Teleporter *Tel);
//Membuat Teleporter

boolean isPetakTeleport(int n, int countTel, ListTeleporter LT);
//Mengembalikan true apabila petak memiliki teleport

int srcTeleporter(int n, int countTel, ListTeleporter LT);
 //mengembalikan nilai int asal dari sebuah teleport

int destTeleporter(int n, int countTel, ListTeleporter LT);
//mengembalikan nilai int destinasi dari sebuah teleport

#endif