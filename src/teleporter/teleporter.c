#include <stdio.h>
#include "../boolean.h"
#include "../array/array.h"
#include "teleporter.h"

void createTeleporter(int n, int m, Teleporter *Tel){
    (*Tel).src = n;
    (*Tel).dest = m;
}

boolean isPetakTeleport(int n, int countTel, ListTeleporter LT){
    int i = 0;
    boolean flag = false;
    while (!flag && i < countTel){
        if (n == LT.T[i].src){
            flag = true;
        } else{i++;}
    }
    return flag;
}