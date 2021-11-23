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
#include "buff.h"
#include "player.h"


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

void useSkill(Player *player, int n);
/*  I.S. skillPemain tidak kosong
    F.S. pemain menggunakan skillnya, skill tersebut dihapus dari
         skillPemain.

*/

void MenuSkill(addressPlayer AP);
/*  I.S. Sembarang
    F.S. skillpemain mungkin digunakan, mungkin dihapus
*/

void pintuGaKemana(addressPlayer AP, address p);
/*  I.S. AP dan P terdefinisi
    F.S. Pemain mendapatkan buff imunitas teleport
*/

void mesinwaktu(addressPlayer AP, address p);
/*  I.S. AP dan P terdefinisi
    F.S. seluruh pemain kecuali user mundur sejauh roll dadu
*/

void balingjambu(addressPlayer AP, address p);
/*  I.S. AP dan P terdefinisi
    F.S. seluruh pemain selain user maju sejauh roll dadu
*/

void cerminGanda(addressPlayer AP, address p);
/*  I.S. AP dan P terdefinisi
    F.S. jika jumlah skill <= 9, skill akan bertambah
*/

void senterBesarHoki(addressPlayer AP, address p);
/*  I.S. AP dan P terdefinisi
    F.S. Memberi buff Hoki Besar jika belum ada buff hoki sebelumnya
*/

void senterKecilHoki(addressPlayer AP, address p);
/*  I.S. AP dan P terdefinisi
    F.S. Memberi buff Hoki Besar jika belum ada buff hoki sebelumnya
*/

void mesinPenukarPosisi(addressPlayer AP, address p);
/*  I.S. AP dan P terdefinisi
    F.S. Menukar posisi user dengan player yang dipilih
*/

#endif // SKILL_H
