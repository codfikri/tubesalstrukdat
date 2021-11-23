#include <stdio.h>
#include "mesinkar.h"
#include "mesinkar.c"
#include "mesinkata.h"
#include "mesinkata.c"
#include "inspect.h"
#include "inspect.c"

int main(){
      /*Membaca panjang peta*/
      STARTGAME("map.txt");
      int lengthMap = KataTOInteger(CKata);
      ADVKATA();

      /*Membaca peta*/
      TabChar Map;
      MakeEmpty(&Map);
      SetNeff(&Map, lengthMap);
      setMap(CKata, &Map, lengthMap);
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


      /*testing output dari pembacaan konfigurasi*/

      printf("%d\n", lengthMap);
      for (int i= 1; i<=lengthMap; i++){
            printf("%c", Map.TI[i]);
      }
      printf("\n");
      printf("%d\n", GetFirstIdx(Map));
      printf("%d\n", NbElmt(Map));
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

      int petak1 = 2;
      int petak2 = 3;
      int petak3 = 4;
      inspectPetak(petak1, LT, countTel, Map, lengthMap);
      inspectPetak(petak2, LT, countTel, Map, lengthMap);
      inspectPetak(petak3, LT, countTel, Map, lengthMap);

      return 0;

}
