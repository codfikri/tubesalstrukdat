#include "stack2.h"
#include <stdio.h>
#include <stdlib.h>

/* Prototype manajemen memori */
void AlokasiStack (addressStack *P, infostack X)
/* I.S. Sembarang */
/* F.S. Alamat P dialokasi, jika berhasil maka info(P)=X dan
        next(P)=NilStack */
/*      P=NilStack jika alokasi gagal */
{
  *P = (ElmtStackPlayer *)malloc(sizeof(ElmtStackPlayer));
  if(*P != NilStack){
    next(*P) = NilStack;
    info(*P) = X;
  }
}

void DealokasiStack (addressStack P)
/* I.S. P adalah hasil alokasi, P != NilStack */
/* F.S. Alamat P didealokasi, dikembalikan ke sistem */
{
  free(P);
}

/* ********* PROTOTYPE REPRESENTASI LOJIK StackPlayer ***************/
boolean IsEmptyStack (StackPlayer S)
/* Mengirim true jika StackPlayer kosong: TopPlayer(S) = NilStack */
{
  return TopPlayer(S) == NilStack;
}

void CreateEmptyStack (StackPlayer * S)
/* I.S. sembarang */
/* F.S. Membuat sebuah StackPlayer S yang kosong */
{
  TopPlayer(*S) = NilStack;
}

void Push (StackPlayer * S, infostack X)
/* Menambahkan X sebagai elemen StackPlayer S */
/* I.S. S mungkin kosong, X terdefinisi */
/* F.S. X menjadi TopPlayer yang baru jika alokasi X berhasil, */
/*      jika tidak, S tetap */
/* Pada dasarnya adalah operasi Insert First pada list linier */
{
  addressStack P;
  AlokasiStack(&P, X);
  if(P != NilStack){
    next(P) = TopPlayer(*S);
    TopPlayer(*S) = P;
  }
}

void Pop (StackPlayer * S, infostack * X)
/* Menghapus X dari StackPlayer S. */
/* I.S. S tidak mungkin kosong */
/* F.S. X adalah nilai elemen TopPlayer yang lama, */
/*      elemen TopPlayer yang lama didealokasi */
/* Pada dasarnya adalah operasi Delete First pada list linier */
{
  *X = InfoTopPlayer(*S);
  addressStack P = TopPlayer(*S);
  TopPlayer(*S) = next(TopPlayer(*S));
  DealokasiStack(P);
}

/* ********* PROTOTYPE LAINNYA ***************/

void PushPlayer (StackPlayer *S, Player P, Queue Q)
{
  infostack X;
  PLAYER(X) = P;
  QUEUE(X) = Q;
  Push(S, X);
}


void PushUndef (StackPlayer * S)
/* Menambahkan elemen StackPlayer S dengan infostack player tak terdefinisi, num(X) = -1*/
/* I.S. S mungkin kosong, tabel penampung elemen stack TIDAK penuh */
/* F.S. X menjadi TOP yang baru,TOP bertambah 1 */
{
  infostack X;
  Player P;
  Queue Q;
  QCreateEmpty (&Q, 4);
  PUndef(&P);
  PLAYER(X) = P; 

  QUEUE(X) = Q;
  Push( S, X);
}

void PUndef(Player *P)
{
  (*P).Petak = -1;
}


void Undo(StackPlayer * S)
{
  infostack X;
  int temp;
  temp = (PLAYER(InfoTopPlayer(*S))).Petak;
  if (temp == -1 )
  {
    Pop(S, &X);
    temp = (PLAYER(InfoTopPlayer(*S))).Petak;
  }
  while (temp != -1)
  {
    Pop (S, &X);
    temp = (PLAYER(InfoTopPlayer(*S))).Petak;
  }
}
