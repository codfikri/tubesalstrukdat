/* File : stack.h */
#ifndef stack_H
#define stack_H

#include "../boolean.h"
#include <stdlib.h>
#include <stdio.h>
#include "../player/player.h"
#include "../skill/skill.h"

/* Konstanta */
#define NilStack NULL

/* Deklarasi infostack */
typedef Player infostack;

/* StackPlayer dengan representasi berkait dengan pointer */
typedef struct tElmtStackPlayer * addressStack;
typedef struct tElmtStackPlayer {
	infostack info;
	addressStack next;
} ElmtStackPlayer;

/* Type StackPlayer dengan ciri TOP : */
typedef struct {
	addressStack TOP;  /* alamat TOP: elemen puncak */
} StackPlayer;

/* Selektor */
#define TopPlayer(S) (S).TOP
#define InfoTopPlayer(S) (S).TOP->info
#define next(P) (P)->next
#define info(P) (P)->info

/* Prototype manajemen memori */
void AlokasiStack (addressStack *P, infostack X);
/* I.S. Sembarang */
/* F.S. Alamat P dialokasi, jika berhasil maka info(P)=X dan
        next(P)=NilStack */
/*      P=NilStack jika alokasi gagal */
void DealokasiStack (addressStack P);
/* I.S. P adalah hasil alokasi, P != NilStack */
/* F.S. Alamat P didealokasi, dikembalikan ke sistem */

/* ********* PROTOTYPE REPRESENTASI LOJIK StackPlayer ***************/
boolean IsEmptyStack (StackPlayer S);
/* Mengirim true jika StackPlayer kosong: TOP(S) = NilStack */
void CreateEmptyStack (StackPlayer * S);
/* I.S. sembarang */
/* F.S. Membuat sebuah StackPlayer S yang kosong */
void Push (StackPlayer * S, infostack X);
/* Menambahkan X sebagai elemen StackPlayer S */
/* I.S. S mungkin kosong, X terdefinisi */
/* F.S. X menjadi TOP yang baru jika alokasi X berhasil, */
/*      jika tidak, S tetap */
/* Pada dasarnya adalah operasi Insert First pada list linier */
void Pop (StackPlayer * S, infostack * X);
/* Menghapus X dari StackPlayer S. */
/* I.S. S tidak mungkin kosong */
/* F.S. X adalah nilai elemen TOP yang lama, */
/*      elemen TOP yang lama didealokasi */
/* Pada dasarnya adalah operasi Delete First pada list linier */

/* ********* PROTOTYPE LAINNYA ***************/

void PushUndef (StackPlayer * S);
/* Menambahkan elemen StackPlayer S dengan infostack player tak terdefinisi, num(X) = -1*/
/* I.S. S mungkin kosong, tabel penampung elemen stack TIDAK penuh */
/* F.S. X menjadi TOP yang baru,TOP bertambah 1 */


void Undo(StackPlayer * S);
/*
  */


#endif
