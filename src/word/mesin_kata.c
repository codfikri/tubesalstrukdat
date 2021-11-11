/*
NIM               : 18220097
Nama              : Muhamad Fikri Nurohman
Tanggal           : 22 September 2021
Pra Praktikum ke- : 3
*/

#include <stdio.h>
#include "mesin_kata.h"

boolean EndKata;
Kata CKata;
int lengthConfig;

void IgnoreBlank()
{
    /* Mengabaikan satu atau beberapa BLANK
    I.S. : CC sembarang
    F.S. : CC ≠ BLANK atau CC = MARK */
    while (CC == BLANK)
    {
        ADV();
    }
}

void STARTKATA()
{
    /*
    I.S. : CC sembarang
    F.S. : EndKata = true, dan CC = MARK;
          atau EndKata = false, CKata adalah kata yang sudah diakuisisi,
          CC karakter pertama sesudah karakter terakhir kata
    */
    START();
    IgnoreBlank();
    SalinKata();
}

void ADVKATA()
{
    /* I.S. : CC adalah karakter pertama kata yang akan diakuisisi
   F.S. : CKata adalah kata terakhir yang sudah diakuisisi,
          CC adalah karakter pertama dari kata berikutnya, mungkin MARK
          Jika CC = MARK, EndKata = true.
   Proses : Akuisisi kata menggunakan procedure SalinKata */
    IgnoreBlank();
    SalinKata();
    IgnoreBlank();
}

void SalinKata()
{
    /* Mengakuisisi kata, menyimpan dalam CKata
    I.S. : CC adalah karakter pertama dari kata
    F.S. : CKata berisi kata yang sudah diakuisisi;
          CC = BLANK atau CC = MARK;
          CC adalah karakter sesudah karakter terakhir yang diakuisisi.
          Jika panjang kata melebihi NMax, maka sisa kata "dipotong" */
    int i = 0;
    while (i <= lengthConfig)
    {
        CKata.TabKata[i] = CC;
        ADV();
        i++;
    }
    CKata.Length = i - 1;
}