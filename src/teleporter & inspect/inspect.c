#include <stdio.h>
#include "teleporter.c"
#include "inspect.h"

boolean isPetakTerlarang(int petak, TabChar Map){
      //mengembalikan true apabila Petak adalah petak terlarang
      //petak terlarang ditandai dengan karakter "#"
      char temp = Map.TI[petak];
      return temp == terlarang;
}

int inspectPetak(int petak, ListTeleporter LT , int countTel, TabChar Map, int lengthMap)
{
      //ketika map sudah dibaca melalui konfigurasi
      //countTel diassign dari konfigurasi map
      if (isPetakTeleport(petak, countTel, LT)){
            int petak_dest = destTeleporter(petak, countTel, LT);
            int petak_src = srcTeleporter(petak, countTel, LT);
            printf("Petak %d memiliki teleporter menuju %d\n", petak_src, petak_dest);
      }
      else{
            if (isPetakTerlarang(petak, Map)){
                  printf("Petak %d merupakan petak terlarang\n", petak);
            }
            else{
                  printf("Petak %d merupakan petak kosong\n", petak);
            }
      }

      
}