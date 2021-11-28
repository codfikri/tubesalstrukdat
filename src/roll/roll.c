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

int STARTROLL(PlayerList PL, addressPlayer P, int nPlayer)
{
      int getdice = randomroll(maxRoll);
      int currPostition = CheckPlayerPosition(nPlayer, PositionToInteger);
      int forward = currPostition + getdice;
      int backward = currPostition - getdice;
      printf("%s mendapatkan angka %d\n", Nama(P), getdice);
      if ((forward <= lengthMap) && (backward >= 1)) // Petak maju dan mundur valid (di dalam range Map)
      {
            // int idxF = getIdx(forward);
            // int tempF = LT.T[idxF].dest;
            // int idxB = getIdx(backward);
            // int tempB = LT.T[idxB].dest;
            if (isPetakTerlarang(forward)){ // Petak maju terlarang
                  if (isPetakTerlarang(backward)){ // Petak mundur terlarang
                        printf("%s tidak dapat bergerak\n", Nama(P)); // Tidak dapat bergerak
                  } else {
                        printf("%s dapat mundur\n", Nama(P));
                        printf("%s mundur %d langkah\n", Nama(P), getdice);
                        printf("%s berada di petak %d\n", Nama(P), backward);
                        if (isPetakTeleport(backward)){
                              printf("%s menemukan teleporter\n", Nama(P));
                              int idxB = getIdxTeleporter(backward);
                              int tempB = LT.T[idxB].dest;
                              if (isImmune(P)){
                                    char tempInput[1];
                                    printf("%s memiliki imunitas teleport\n");
                                    printf("Apakah %s ingin teleport? (Y/N)\n");
                                    scanf("%s", tempInput);
                                    if (strcmp(tempInput, "Y") == 0){ // Player tetap teleport
                                          printf("%s teleport\n", Nama(P));
                                          printf("%s teleport ke petak %d\n", Nama(P), tempB);
                                          Petak(P) = tempB;
                                    }
                                    else{ // Player tidak teleport
                                          printf("%s tidak teleport\n", Nama(P));
                                          printf("Buff imunitas teleport hilang\n");
                                          isImmune(P) = false;
                                    }
                              } else { // Player tidak imun
                                    printf("%s tidak memiliki imunitas teleport.\n", Nama(P));
                                    printf("%s teleport ke petak %d\n", Nama(P), tempB);
                                    Petak(P) = tempB;
                              } 
                              updatePosition(PL, &PositionToInteger);
                              }
                        else { // Petak maju bukan teleporter
                              printf("%s tidak menemukan teleporter\n", Nama(P));
                              updatePosition(PL, &PositionToInteger);
                        }
                  }
                  
            }
            else{ // Petak maju tidak terlarang
                  if (!isPetakTerlarang(backward)){ // Petak mundur tidak terlarang
                        int inputMove; 
                        printf("%s dapat maju dan mundur\n", Nama(P));
                        printf("Kemana %s mau bergerak?\n", Nama(P));
                        printf("1. %d\n", forward);
                        printf("2. %d\n", backward);
                        printf("Masukkan pilihan: ");
                        scanf("%d", &inputMove); // Dapat maju ke dua petak
                        if (inputMove == 1){ // Memilih maju
                              printf("%s maju %d langkah\n", Nama(P), getdice);
                              printf("%s berada di petak %d\n", Nama(P), forward);
                              Petak(P) = forward;
                              if (isPetakTeleport(forward)){ // Petak maju teleport
                                    printf("%s menemukan teleporter\n", Nama(P));
                                    int idxF = getIdxTeleporter(forward);
                                    int tempF = LT.T[idxF].dest;
                                    if (isImmune(P)) // Player imun
                                    {
                                          char tempInput[1];
                                          printf("%s memiliki imunitas teleport\n", Nama(P));
                                          printf("Apakah %s ingin teleport? (Y/N)\n", Nama(P));
                                          scanf("%s", tempInput);
                                          if (strcmp(tempInput, "Y") == 0)
                                          { // Player tetap teleport
                                                printf("%s teleport\n", Nama(P));
                                                printf("%s teleport ke petak %d\n", Nama(P), tempF);
                                                Petak(P) = tempF;
                                          }
                                          else{ // Player tidak teleport
                                                printf("%s tidak teleport\n", Nama(P));
                                                printf("Buff imunitas teleport hilang\n");
                                                isImmune(P) = false;
                                          }
                                    }
                                    else{ // Player tidak imun
                                          printf("%s tidak memiliki imunitas teleport.\n", Nama(P));
                                          printf("%s teleport ke petak %d\n", Nama(P), tempF);
                                          Petak(P) = tempF;
                                    }
                                    updatePosition(PL, &PositionToInteger);
                              }
                              else{ // Petak maju bukan teleporter
                                    printf("%s tidak menemukan teleport\n", Nama(P));
                                    updatePosition(PL, &PositionToInteger);
                              }
                        }
                        else if (inputMove == 2) { // Player memilih mundur
                              printf("%s mundur %d langkah\n", Nama(P), getdice);
                              printf("%s berada di petak %d\n", Nama(P), backward);
                              if (isPetakTeleport(backward)){ // Petak mundur adalah teleporter
                                    int idxB = getIdxTeleporter(backward);
                                    int tempB = LT.T[idxB].dest;
                                    Petak(P) = backward;
                                    printf("%s menemukan teleporter\n", Nama(P));
                                    if (isImmune(P)) // Player imun
                                    {
                                          char tempInput[1];
                                          printf("%s memiliki imunitas teleport\n");
                                          printf("Apakah %s ingin teleport? (Y/N)\n");
                                          scanf("%s", tempInput);
                                          if (strcmp(tempInput, "Y") == 0)
                                         { // Player tetap memilih teleport
                                                printf("%s teleport\n", Nama(P));
                                                printf("%s teleport ke petak %d\n", Nama(P), tempB);
                                                Petak(P) = tempB;
                                          }
                                          else{ // Player tidak teleport
                                                printf("%s tidak teleport\n", Nama(P));
                                                printf("Buff imunitas teleport hilang\n");
                                                isImmune(P) = false;
                                          }
                                    }
                                    else { // Player tidak imun
                                          printf("%s tidak memiliki imunitas teleport.\n", Nama(P));
                                          printf("%s teleport ke petak %d\n", Nama(P), tempB);
                                          Petak(P) = tempB;
                                    }
                                    updatePosition(PL, &PositionToInteger);
                              }
                              else{ // Petak mundur bukan teleporter
                                    printf("%s tidak menemukan teleport\n", Nama(P));
                                    updatePosition(PL, &PositionToInteger);
                              }
                        }
                  }
                  else { // Petak mundur terlarang
                        printf("%s dapat maju\n", Nama(P));
                        printf("%s maju %d langkah\n", Nama(P), getdice);
                        printf("%s berada di petak %d\n", Nama(P), forward);
                        Petak(P) = forward;
                        if (!isPetakTeleport(forward))
                        {
                              printf("%s tidak menemukan teleporter.\n", Nama(P));
                              updatePosition(PL, &PositionToInteger);
                        }
                        else{ // Petak maju teleporter
                              printf("%s menemukan teleporter.\n", Nama(P));
                              int idxF = getIdxTeleporter(forward);
                              int tempF = LT.T[idxF].dest;
                              if (isImmune(P))
                                    {
                                          char tempInput[1];
                                          printf("%s memiliki imunitas teleport\n");
                                          printf("Apakah %s ingin teleport? (Y/N)\n");
                                          scanf("%s", tempInput);
                                          if (strcmp(tempInput, "Y") == 0)
                                          {
                                                printf("%s teleport\n", Nama(P));
                                                printf("%s teleport ke petak %d\n", Nama(P), tempF);
                                                Petak(P) = tempF;
                                          }
                                          else
                                          {
                                                printf("%s tidak teleport\n", Nama(P));
                                                printf("Buff imunitas teleport hilang\n");
                                                isImmune(P) = false;
                                          }
                                    updatePosition(PL, &PositionToInteger);
                                    }
                              else {
                                    printf("%s tidak memiliki imunitas teleport.\n", Nama(P));
                                    printf("%s teleport ke petak %d\n", Nama(P), tempF);
                                    Petak(P) = tempF;
                                    updatePosition(PL, &PositionToInteger);
                              }
                  }
            // updatePosition(PL, &PositionToInteger);
                  }
            }
      }
      else if (backward >= 1 && forward > lengthMap) // Petak mundur saja yang valid (dalam range map)
      {
            if (isPetakTerlarang(backward)){ // Petak mundur terlarang
                  printf("%s tidak dapat bergerak\n", Nama(P));
            }
            else // Petak mundur tidak terlarang
            {
                  printf("%s dapat mundur\n", Nama(P));
                  printf("%s mundur %d langkah\n", Nama(P), getdice);
                  printf("%s berada di petak %d\n", Nama(P), backward);
                  Petak(P) = backward;
                  if (!isPetakTeleport(backward))
                  {
                        printf("%s tidak menemukan teleporter.\n", Nama(P));
                        updatePosition(PL, &PositionToInteger);
                  }
                  else{
                        int idxB = getIdxTeleporter(backward);
                        int tempB = LT.T[idxB].dest;
                        printf("%s menemukan teleporter\n", Nama(P));
                        if (isImmune(P)) // Player imun
                              {
                                    char tempInput[1];
                                    printf("%s memiliki imunitas teleport\n");
                                    printf("Apakah %s ingin teleport? (Y/N)\n");
                                    scanf("%s", tempInput);
                                    if (strcmp(tempInput, "Y") == 0)
                                    {
                                          printf("%s teleport\n", Nama(P));
                                          printf("%s teleport ke petak %d\n", Nama(P), tempB);
                                          Petak(P) = tempB;
                                    }
                                    else
                                    {
                                          printf("%s tidak teleport\n", Nama(P));
                                          printf("Buff imunitas teleport hilang\n");
                                          isImmune(P) = false;
                                    }
                                    updatePosition(PL, &PositionToInteger);
                              }
                        else { // Plauer tidak imum
                              printf("%s tidak memiliki imunitas teleport.\n", Nama(P));
                              printf("%s teleport ke petak %d\n", Nama(P), tempB);
                              Petak(P) = tempB;
                        }
                  }
            }
      }
      else if (forward <=lengthMap && backward < 1) // Petak maju saja yang valid (dalam rentang Map)
      {
            if (isPetakTerlarang(forward)){ // petak maju terlarang
                  printf("%s tidak dapat bergerak\n", Nama(P));
            }
            else // petak maju tidak terlarang
            {
                  printf("%s dapat maju\n", Nama(P));
                  printf("%s maju %d langkah\n", Nama(P), getdice);
                  printf("%s berada di petak %d\n", Nama(P), forward);
                  Petak(P) = forward;
                  if (!isPetakTeleport(forward))
                  {
                        printf("%s tidak menemukan teleporter.\n", Nama(P));
                        // updatePosition(PL, &PositionToInteger);
                  }
                  else{
                        int idxF = getIdxTeleporter(forward);
                        int tempF = LT.T[idxF].dest;
                        printf("%s menemukan teleporter\n", Nama(P));
                        if (isImmune(P))
                              {
                                    char tempInput[1];
                                    printf("%s memiliki imunitas teleport\n");
                                    printf("Apakah %s ingin teleport? (Y/N)\n");
                                    scanf("%s", tempInput);
                                    if (strcmp(tempInput, "Y") == 0)
                                    {
                                          printf("%s teleport\n", Nama(P));
                                          printf("%s teleport ke petak %d\n", Nama(P), tempF);
                                          Petak(P) = tempF;
                                    }
                                    else
                                    {
                                          printf("%s tidak teleport\n", Nama(P));
                                          printf("Buff imunitas teleport hilang\n");
                                          isImmune(P) = false;
                                    }
                                    // updatePosition(PL, &PositionToInteger);
                              }
                        else {
                              printf("%s tidak memiliki imunitas teleport.\n", Nama(P));
                              printf("%s teleport ke petak %d\n", Nama(P), tempF);
                              Petak(P) = tempF;
                        }
                  }
            updatePosition(PL, &PositionToInteger);
            }
      }
      else{
            printf("%s tidak dapat bergerak\n", Nama(P));
      }

      }