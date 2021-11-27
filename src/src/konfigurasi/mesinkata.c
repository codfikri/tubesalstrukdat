#include <stdio.h>
#include "mesinkata.h"
#include "mesinkar.h"

boolean EndKata;
Kata CKata;

void IgnoreBlank()
/* Mengabaikan satu atau beberapa BLANK
   I.S. : CC sembarang 
   F.S. : CC ≠ BLANK atau CC = MARK */
{
    while (CC == BLANK || CC == ENTER){
        ADV();
    }
}

void STARTGAME(char* filename)
/* I.S. : CC sembarang 
   F.S. : EndKata = true, dan CC = MARK; 
          atau EndKata = false, CKata adalah kata yang sudah diakuisisi,
          CC karakter pertama sesudah karakter terakhir kata */
{
    START(filename);
    IgnoreBlank();
    if (CC == MARK){
        EndKata = true;
    } else {
        EndKata = false;
        ADVKATA();
    }
}

void ADVKATA()
/* I.S. : CC adalah karakter pertama kata yang akan diakuisisi 
   F.S. : CKata adalah kata terakhir yang sudah diakuisisi, 
          CC adalah karakter pertama dari kata berikutnya, mungkin MARK
          Jika CC = MARK, EndKata = true.		  
   Proses : Akuisisi kata menggunakan procedure SalinKata */
{
    IgnoreBlank();
    if (CC == MARK && !EndKata){
        EndKata = true;
    } else{
        SalinKata();
        IgnoreBlank();
    }
}

void SalinKata()
/* Mengakuisisi kata, menyimpan dalam CKata
   I.S. : CC adalah karakter pertama dari kata
   F.S. : CKata berisi kata yang sudah diakuisisi; 
          CC = BLANK atau CC = MARK; 
          CC adalah karakter sesudah karakter terakhir yang diakuisisi.
          Jika panjang kata melebihi NMax, maka sisa kata "dipotong" */
{
    int i = 1;
    while ((CC != MARK) && (CC != BLANK) && (CC != ENTER) && i != NMax) {
        CKata.TabKata[i] = CC;
        ADV();
        i++;
    }
    if (i <NMax){
        CKata.Length = i;
    }
    else{
        CKata.Length = NMax;
    }
}

void PrintKata(Kata Kata) 
/* Mencetak kata ke layar
   I.S. : Kata K terdefinisi
   F.S. : Kata K tercetak pada layar */
{
    for (int i = 1; i <= Kata.Length; i ++) {
        printf("%c", Kata.TabKata[i]);
    }
}

int convertNumber(char Charnumber) {
    /* Mengonversi angka basis 10 dalam type char menjadi tipe int */
    switch (Charnumber)
    {
    case '1':
        return 1;
        break;
    case '2':
        return 2;
        break;
    case '3':
        return 3;
        break;
    case '4':
        return 4;
        break;
    case '5':
        return 5;
        break;
    case '6':
        return 6;
        break;
    case '7':
        return 7;
        break;
    case '8':
        return 8;
        break;
    case '9':
        return 9;
        break;
    default:
        return 0;
        break;
    }
}

int KataTOInteger(Kata CKata) {
    //mengembalikan angka dalam bentuk integer
    int temp = 1;
    int num = 0;
    for (int i = CKata.Length-1; i >= 0; i--)
    {
        num += convertNumber(CKata.TabKata[i])*(temp);
        temp *= 10; 
    }
    return num;
}

void setMap(Kata CKata, TabChar *Map, int lengthMap)
/* I.S. Kata terdefinisi, sembarang */
/* F.S. Map berisi salinan Kata */
{
    for (int i = 1; i<= lengthMap ;i++){
        (*Map).TI[i] = CKata.TabKata[i];
    }
}