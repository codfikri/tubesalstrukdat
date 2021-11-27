#include <stdio.h>
#include "teleporter.c"
#include "inspect.h"

TabChar Map;
int lengthMap;

boolean isPetakTerlarang(int petak){
      //mengembalikan true apabila Petak adalah petak terlarang
      //petak terlarang ditandai dengan karakter "#"
      return Map.TI[petak] == terlarang;
}

void inspectPetak(int petak)
{
      //ketika map sudah dibaca melalui konfigurasi
      //countTel diassign dari konfigurasi map
      if (isPetakTeleport(petak)){
            int petak_dest = destTeleporter(petak);
            int petak_src = srcTeleporter(petak);
            printf("Petak %d memiliki teleporter menuju %d\n", petak_src, petak_dest);
      }
      else{
            if (isPetakTerlarang(petak)){
                  printf("Petak %d merupakan petak terlarang\n", petak);
            }
            else{
                  printf("Petak %d merupakan petak kosong\n", petak);
            }
      }

      
}