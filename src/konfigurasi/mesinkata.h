/* File: mesinkata.h */

#ifndef __MESINKATA_H__
#define __MESINKATA_H__

#include "mesinkar.h"
#include "../array/array.h"

#define NMax 100
#define BLANK ' '
#define ENTER '\n'

typedef struct {
	char TabKata[NMax+1]; /* container penyimpan kata, indeks yang dipakai [1..NMax] */
    int Length;
} Kata;

/* State Mesin Kata */
extern boolean EndKata;
extern Kata CKata;

/* *** ADT untuk baca file eksternal *** */

void IgnoreBlank();
/* Mengabaikan satu atau beberapa BLANK
   I.S. : CC sembarang 
   F.S. : CC ≠ BLANK atau CC = MARK */

void STARTGAME(char* filename);
/* I.S. : CC sembarang 
   F.S. : EndKata = true, dan CC = MARK; 
          atau EndKata = false, CKata adalah kata yang sudah diakuisisi,
          CC karakter pertama sesudah karakter terakhir kata */

void ADVKATA();
/* I.S. : CC adalah karakter pertama kata yang akan diakuisisi 
   F.S. : CKata adalah kata terakhir yang sudah diakuisisi, 
          CC adalah karakter pertama dari kata berikutnya, mungkin MARK
          Jika CC = MARK, EndKata = true.		  
   Proses : Akuisisi kata menggunakan procedure SalinKata */

void SalinKata();
/* Mengakuisisi kata, menyimpan dalam CKata
   I.S. : CC adalah karakter pertama dari kata
   F.S. : CKata berisi kata yang sudah diakuisisi; 
          CC = BLANK atau CC = MARK; 
          CC adalah karakter sesudah karakter terakhir yang diakuisisi.
          Jika panjang kata melebihi NMax, maka sisa kata "dipotong" */

/* *** FUNGSI TAMBAHAN *** */

void PrintKata(Kata Kata);
/* Mencetak kata ke layar
   I.S. : Kata K terdefinisi
   F.S. : Kata K tercetak pada layar */

void setMap(Kata CKata, TabChar *Map, int lengthMap);
/* I.S. Kata terdefinisi, sembarang */
/* F.S. Map berisi salinan Kata */

int convertNumber(char Charnumber);
    /* Mengonversi angka basis 10 dalam type char menjadi tipe int */

int KataTOInteger(Kata CKata);
    //mengembalikan angka dalam bentuk integer

char* KataToChar(Kata CKata);
   /*mengembalikan kata dalam bentuk char*/

#endif