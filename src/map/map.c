#include "map.h"

void PrintTabChar(TabChar T){
      for (int i = IdxMin; i<= T.Neff; i++){
            printf("%c ", T.TI[i]);
      }
}


int updatePosition(PlayerList PL, TabInt *PositionToInteger)
//Mengembalikan value posisi petak seorang pemain dalam bentuk integer
{
      addressPlayer P = FirstPlayer(PL);
      int i = 1;
      while (P != Nil && i <=4){
            (*PositionToInteger).TI[i] = Petak(P);
            P = NextPlayer(P);
            i++;
      }
}

int CheckPlayerPosition(int nPlayer ,TabInt PositionToInteger)
//Mengirimkan integer posisi player
{
      int a = (PositionToInteger).TI[nPlayer];
      return a;
}

int MapPlayer(PlayerList PL, TabChar Map, TabInt PositionToInteger)
//Menampilkan current map dari player
//Petak yang ditempati player ditandai dengan  karakter "*"
{
      updatePosition(PL, &PositionToInteger);
      int i = 1;
      char v = "*";
      TabChar tempMap;
      while (i <=4)
      {
            int temp;
            temp = CheckPlayerPosition(i, PositionToInteger);
            SetTab(Map, &tempMap);
            Map.TI[temp] = v;
            PrintTabChar(Map);
            printf("%d\n", temp);
            SetTab(tempMap, &Map);
            i++;
      }
}
