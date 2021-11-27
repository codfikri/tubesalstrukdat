#include <stdio.h>
#include "teleporter.h"

ListTeleporter LT;
Teleporter *Tel;
int countTel;

void createTeleporter(int n, int m){
    //Membuat Teleporter
    (*Tel).src = n;
    (*Tel).dest = m;
}

boolean isPetakTeleport(int n){
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

int srcTeleporter(int n){
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

int destTeleporter(int n){
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