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
      KataTOChar(CKata, map);
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


      /*test output dari pembacaan konfigurasi*/

      printf("%d\n", lengthMap);
      for (int i= 0; i<lengthMap; i++){
            printf("%c", map[i]);
      }
      printf("\n");
      printf("%d\n", MaxRoll);
      printf("%d\n", countTel);
      for (int i= 0; i< countTel; i++){
            int temp1 = LT.T[i].src;
            int temp2 = LT.T[i].dest;
            printf("%d %d\n", temp1, temp2);
      }

      return 0;

}
