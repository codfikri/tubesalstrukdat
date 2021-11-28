#include "roll.h"
 
int randomroll(int maxRoll)
{
      srand(time(0));
      int dice = rand()%maxRoll;  
      while (dice == 0){
            dice = rand()%maxRoll;  
      }    
      return dice;
}

int STARTROLL(PlayerList PL, TabChar Map, TabInt PositionTOInteger, ListTeleporter LT, int maxRoll, int nPlayer, int lengthMap, int countTel)
{
      addressPlayer P;
      P = FirstPlayer(PL);
      int getdice = randomroll(maxRoll);
      int currPostition = CheckPlayerPosition(nPlayer, PositionTOInteger);
      int forward = currPostition + getdice;
      int backward = currPostition - getdice;
      if ((forward <= lengthMap) && (backward >= 1))
      {
            int tempF = LT.T[forward].dest;
            int tempB = LT.T[backward].dest;
            if (isPetakTerlarang(forward)){
                  if (isPetakTerlarang(backward)){
                        printf("%s mendapatkan angka %d\n", Nama(P), getdice);
                        printf("%s tidak dapat bergerak\n", Nama(P));
                  }
            }
            else{
                  if (!isPetakTerlarang(backward)){
                        int inputMove;
                        printf("%s dapat maju dan mundur\n", Nama(P));
                        printf("Kemana %s mau bergerak?\n", Nama(P));
                        printf("1. %d\n", forward);
                        printf("2. %d\n", backward);
                        scanf("Masukkan pilihan %d\n", &inputMove);
                        if (inputMove == forward){
                              if (isPetakTeleport(forward){
                                    printf("%s maju %d langkah\n", Nama(P), getdice);
                                    Petak(P) = forward;
                                    printf("%s menemukan teleporter\n");
                                    if (isImmune(P))
                                    {
                                          char tempInput;
                                          printf("%s memiliki imunitas teleport\n");
                                          printf("Apakah %s ingin teleport? (Y/N)\n");
                                          scanf("%c", &tempInput);
                                          if (tempInput == "Y"){
                                                printf("%s teleport\n", Nama(P));
                                                printf("%s teleport ke petak %d\n", Nama(P), tempF);
                                                Petak(P) = tempF;
                                          }
                                          else{
                                                printf("%s tidak teleport\n", Nama(P));
                                                printf("Buff imunitas teleport hilang\n");
                                                isImmune(P) = false;

                                          }
                                    }
                                    updatePosition(PL, &PositionTOInteger);
                              }
                              else{
                                    printf("%s maju %d langkah\n", Nama(P), getdice);
                                    printf("%s ada di petak %d\n", Nama(P), forward);
                                    printf("%s tidak menemukan teleport\n", Nama(P));
                                    Petak(P) = forward;
                                    updatePosition(PL, &PositionTOInteger);
                              }
                        else{
                              if (isPetakTeleport(backward){
                                    printf("%s mundur %d langkah\n", Nama(P), getdice);
                                    Petak(P) = backward;
                                    printf("%s menemukan teleporter\n");
                                    if (isImmune(P))
                                    {
                                          char tempInput;
                                          printf("%s memiliki imunitas teleport\n");
                                          printf("Apakah %s ingin teleport? (Y/N)\n");
                                          scanf("%c", &tempInput);
                                          if (tempInput == "Y"){
                                                printf("%s teleport\n", Nama(P));
                                                printf("%s teleport ke petak %d\n", Nama(P), tempF);
                                                Petak(P) = tempB;
                                          }
                                          else{
                                                printf("%s tidak teleport\n", Nama(P));
                                                printf("Buff imunitas teleport hilang\n");
                                                isImmune(P) = false;
                                          }
                                    }
                                    updatePosition(PL, &PositionTOInteger);
                              }
                              else{
                                    printf("%s mundur %d langkah\n", Nama(P), getdice);
                                    printf("%s ada di petak %d\n", Nama(P), backward);
                                    printf("%s tidak menemukan teleport\n", Nama(P));
                                    Petak(P) = backward;
                                    updatePosition(PL, &PositionTOInteger);
                              }
                        }
                  }
            }
      }
      else if (backward >= 1 && forward > lengthMap)
      {
            if (isPetakTerlarang(backward, Map)){
                  printf("%s tidak dapat bergerak\n", Nama(P));
            }
            else
            {
                  printf("%s dapat mundur\n", Nama(P));
                  printf("%s mundur %d langkah\n", Nama(P), getdice);
                  Petak(P) = backward;
                  int tempBdest = LT.T[backward].dest;
                  if (!isPetakTeleport(backward, countTel, LT))
                  {
                        printf("%s berada di petak %d\n", Nama(P), backward);
                        updatePosition(PL, &PositionTOInteger);
                  }
                  else{
                        printf("%s menemukan teleporter\n");
                        if (isImmune(P))
                              {
                                    char tempInput;
                                    printf("%s memiliki imunitas teleport\n", Nama(P));
                                    printf("Apakah %s ingin teleport? (Y/N)\n", Nama(P));
                                    scanf("%c", &tempInput);
                                    if (tempInput == "Y")
                                    {
                                          printf("%s teleport\n", Nama(P));
                                          printf("%s teleport ke petak %d\n", Nama(P), tempBdest);
                                          Petak(P) = tempBdest;
                                    }
                                    else
                                    {
                                          printf("%s tidak teleport\n", Nama(P));
                                          printf("Buff imunitas teleport hilang\n");
                                          isImmune(P) = false;
                                    }
                                    updatePosition(PL, &PositionTOInteger);
                              }
                  }
            }
      }
      else if (forward <=lengthMap && backward < 1)
      {
            if (isPetakTerlarang(forward, Map)){
                  printf("%s tidak dapat bergerak\n", Nama(P));
            }
            else
            {
                  printf("%s dapat maju\n", Nama(P));
                  printf("%s maju %d langkah\n", Nama(P), getdice);
                  Petak(P) = forward;
                  int tempFdest = LT.T[forward].dest;
                  if (!isPetakTeleport(forward, countTel, LT))
                  {
                        printf("%s berada di petak %d\n", Nama(P), forward);
                        updatePosition(PL, &PositionTOInteger);
                  }
                  else{
                        printf("%s menemukan teleporter\n");
                        if (isImmune(P))
                              {
                                    char tempInput;
                                    printf("%s memiliki imunitas teleport\n", Nama(P));
                                    printf("Apakah %s ingin telepor? (Y/N)\n", Nama(P));
                                    scanf("%c", &tempInput);
                                    if (tempInput == "Y")
                                    {
                                          printf("%s teleport\n", Nama(P));
                                          printf("%s teleport ke petak %d\n", Nama(P), tempFdest);
                                          Petak(P) = tempFdest;
                                    }
                                    else
                                    {
                                          printf("%s tidak teleport\n", Nama(P));
                                          printf("Buff imunitas teleport hilang\n");
                                          isImmune(P) = false;
                                    }
                                    updatePosition(PL, &PositionTOInteger);
                              }
                  }
            }
      }
      else{
            printf("%s tidak dapat bergerak\n", Nama(P));
      }

      }