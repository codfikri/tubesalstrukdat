/* *** Definisi ABSTRACT DATA TYPE TELEPORTER *** */

#ifndef TELEPORTER_H
#define TELEPORTER_H

#include "../boolean.h"
#include "array.h"

#define NMAX 50

typedef struct{
    int src;
    int dest;
} Teleporter;

typedef struct{
    Teleporter T[NMAX];
} ListTeleporter;

void createTeleporter(int n, int m, Teleporter *Tel);

boolean isPetakTeleport(int n, int countTel, ListTeleporter LT);

int srcTeleporter(int n, int countTel, ListTeleporter LT);

int destTeleporter(int n, int countTel, ListTeleporter LT);

#endif