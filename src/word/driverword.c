#include <stdio.h>
#include "../boolean.h"
#include "../array/array.h"
#include "mesin_kata.h"

void printKata(int n, Kata kata);

int main(){
  printf("Masukan panjang peta konfigurasi: ");
  scanf("%d", &lengthConfig);
  STARTKATA();
  printKata(lengthConfig, CKata);
  
  return 0;
}

void printKata(int n, Kata kata){
  for(int i = 1; i <= n+1 ; i++){
    printf("%c", kata.TabKata[i]);
  }
  printf("\n");
}