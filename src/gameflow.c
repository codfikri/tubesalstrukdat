#include <stdio.h>
#include "boolean.h"
#include "array/array.h"
#include "word/mesin_kata.h"
#include "gameflow.h"

boolean isPetakValid(int n){
    return (n>=1 && n<=lengthConfig && CKata.TabKata[n] != "#");
}

int mundur(int n, int m){
    return n-m;
}

int maju(int n, int m){
    return n+m;
}