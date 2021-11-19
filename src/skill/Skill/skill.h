/*  modul tabel skill
    Berisi definisi dan semua primitif pemrosesan list skill
    List skill dalam bentuk array
    Penempatan elemen selalu rapat kiri
*/

#include "boolean.h"

#ifndef SKILL_H
#define SKILL_H

#include "boolean.h"
#include "listlinier.h"


// leSKILL LESGOOOOOOOOOOOOOOOOOO -----------------------------------------
void printSkill(List skillPemain);
/*  I.S. skillPemain mungking kosong
    F.S. daftar skill yang dimiliki oleh player di output ke layar
*/
void DelAddress (List *L, address P);
/* I.S. Sembarang */
/* F.S. Jika ada elemen list beraddress P*/
/* Maka P dihapus dari list dan di-dealokasi */
/* Jika tidak ada elemen list dengan address P, maka list tetap */
/* List mungkin menjadi kosong karena penghapusan */

void getSkill(List *skillPemain);
/*  I.S. Sembarang
    F.S. Jika skillPemain sama dengan 10, tidak akan mendapatkan skill.
         jika kurang dari 10, skill akan ditambah sebanyak satu buah
         secara random
*/

void DelSkill(List *skillPemain,int n);
/*  I.S. skillpemain tidak kosong
    F.S. skillpemain berkurang satu pada urutan ke-n
*/

void useSkill(List *skillPemain, int n);
/*  I.S. skillPemain tidak kosong
    F.S. pemain menggunakan skillnya, skill tersebut dihapus dari
         skillPemain.

*/

void MainSkill(List *skillPemain);
/*  I.S. Sembarang
    F.S. skillpemain mungkin digunakan, mungkin dihapus
*/



#endif // SKILL_H
