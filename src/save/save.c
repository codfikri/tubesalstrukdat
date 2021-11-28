#include <stdio.h>
#include <unistd.h>
#include "save.h"

void saveData(PlayerList PL, int currentPlayer)
{
    int n, jumlahskill;
    
    char input[100] = "data/";
    addressPlayer AP;
    printf("Masukkan nama file yang akan disimpan: ");
    scanf("%s", input + 5);
    FILE *fp = fopen(input, "w");
    n = JumlahPlayer(PL);
    fprintf(fp, "%d\n", n);
    AP = FirstPlayer(PL);
    for (int i = 0; i < n; i++){
        fprintf(fp, "%s\n", Nama(AP));
        fprintf(fp, "%d\n", Petak(AP));
        fprintf(fp, "%d\n", NoUrut(AP));
        jumlahskill = NbElmt(Skill(AP));
        fprintf(fp, "%d\n", jumlahskill);
        address AS = First(Skill(AP));
        for (int j = 0; j <jumlahskill; j++)
        {

            fprintf(fp, "%d\n", Info(AS));
            AS = Next(AS);
        }
        fprintf(fp, "%d\n", isImmune(AP));
        fprintf(fp, "%d\n", isHokiKecil(AP));
        fprintf(fp, "%d\n", isHokiBesar(AP));
        fprintf(fp, "%d\n", isPostCermin(AP));
        AP = NextPlayer(AP);
    }
    fprintf(fp, "%d\n", currentPlayer);
    fprintf(fp, ";\n");

    fclose(fp);

    printf("File berhasil disimpan!\n");
}