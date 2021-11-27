#include <stdio.h>
#include "mesinkar.h"
#include "mesinkata.h"
#include "../inspect/inspect.h"

int main(){
      /*Membaca panjang peta*/
      STARTGAME("map.txt");
      lengthMap = KataTOInteger(CKata);
      ADVKATA();

      /*Membaca peta*/
      MakeEmpty(&Map);
      SetNeff(&Map, lengthMap);
      setMap(CKata, &Map, lengthMap);
      ADVKATA();

      /*Membaca MaxRoll*/
      int MaxRoll = KataTOInteger(CKata);
      ADVKATA();

      /*Membaca banyaknya teleporter pada map*/
      countTel = KataTOInteger(CKata);
      ADVKATA();

      /*Membaca destinasi teleporter*/
      for (int i= 0; i< countTel; i++){
            int temp1 = KataTOInteger(CKata);
            ADVKATA();
            int temp2 = KataTOInteger(CKata);
            ADVKATA();
            LT.T[i].src = temp1;
            LT.T[i].dest = temp2;
      }


      /*testing output dari pembacaan konfigurasi*/

      printf("%d\n", lengthMap);
      for (int i= 1; i<=lengthMap; i++){
            printf("%c", Map.TI[i]);
      }
      printf("\n");
      printf("%d\n", GetFirstIdx(Map));
      printf("%d\n", TCNbElmt(Map));
      printf("%d\n", GetLastIdx(Map));
      printf("%c\n", GetElmt(Map, 19));
      printf("%d\n", MaxRoll);
      printf("%d\n", countTel);
      for (int i= 0; i< countTel; i++){
            int temp1 = LT.T[i].src;
            int temp2 = LT.T[i].dest;
            printf("%d %d\n", temp1, temp2);
      }
      printf("\n---111------\n");

      int petak1 = 6;
      int petak2 = 8;
      int petak3 = 4;
      inspectPetak(petak1);
      inspectPetak(petak2);
      inspectPetak(petak3);

      if (!isPetakTerlarang(petak3)){
            printf("sign\n");
      }
      return 0;

}
