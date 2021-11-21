#include <stdio.h>
#include "mesinkar.h"
#include "mesinkar.c"
#include "mesinkata.h"
#include "mesinkata.c"
#include "teleporter.c"
#include "teleporter.h"

int main(){
      /*Membaca panjang peta*/
      STARTGAME("map.txt");
      int lengthMap = KataTOInteger(CKata);
      ADVKATA();

      /*Membaca peta*/
      char map[100];
      KataTOChar(CKata, map); //why masih ada error garbage output n.m
      ADVKATA();

      /*Membaca MaxRoll*/
      int MaxRoll = KataTOInteger(CKata);
      ADVKATA();

      /*Membaca banyaknya teleporter pada map*/
      int countTel = KataTOInteger(CKata);
      ADVKATA();

      /*Membaca destinasi teleporter*/
      ListTeleporter LT;
      for (int i= 0; i< countTel; i++){
            int temp1 = KataTOInteger(CKata);
            ADVKATA();
            int temp2 = KataTOInteger(CKata);
            ADVKATA();
            LT.T[i].src = temp1;
            LT.T[i].dest = temp2;
      }
      return 0;

}
