#include <stdio.h>
#include "teleporter.h"
#include "teleporter.c"

boolean isPetakTerlarang(int petak, char map[100]){ //sementara
      int point = petak -1;
      return map[point] == "#"; //karena map dimulai dari indeks 0 maka petak ke-n tersimpan pada map[n-1]
}

int inspectPetak(int petak, ListTeleporter LT , int countTel, char map[100], int lengthmap)
{
      //ketika map sudah dibaca melalui konfigurasi
      //countTel diassign dari konfigurasi map
      printf("Masukkan petak: ");
      scanf("%d", &petak);

      if (isPetakTeleport(petak, countTel, LT)){
            int petak_dest = destTeleporter(petak, countTel, LT);
            int petak_src = srcTeleporter(petak, countTel, LT);
            printf("Petak %d memiliki teleporter menuju %d\n", petak_src, petak_dest);
      }
      else{
            if (isPetakTerlarang(petak, map)){
                  printf("Petak %d merupakan petak terlarang", petak);
            }
            else{
                  printf("Petak %d merupakan petak kosong", petak);
            }
      }

      
}