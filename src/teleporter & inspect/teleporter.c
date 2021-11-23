#include <stdio.h>
#include "boolean.h"
#include "teleporter.h"
#include "array.h"

void createTeleporter(int n, int m, Teleporter *Tel){
    //Membuat Teleporter
    (*Tel).src = n;
    (*Tel).dest = m;
}

boolean isPetakTeleport(int n, int countTel, ListTeleporter LT){
    //Mengembalikan true apabila petak memiliki teleport
    int i = 0;
    boolean flag = false;
    while (!flag && i < countTel){
        if (n == LT.T[i].src){
            flag = true;
        } else{i++;}
    }
    return flag;
}

int srcTeleporter(int n, int countTel, ListTeleporter LT){
    //mengembalikan nilai int asal dari sebuah teleport
    int i = 0;
    boolean flag = false;
    while (!flag && i < countTel){
        if (n == LT.T[i].src){
            flag = true;
        } else{i++;}
    }
    return LT.T[i].src;
}

int destTeleporter(int n, int countTel, ListTeleporter LT){
    //mengembalikan nilai int destinasi dari sebuah teleport
    int i = 0;
    boolean flag = false;
    while (!flag && i < countTel){
        if (n == LT.T[i].src){
            flag = true;
        } else{i++;}
    }
    return LT.T[i].dest;
}