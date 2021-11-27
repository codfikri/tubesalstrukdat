#include "arrayint.h"

/* ********** KONSTRUKTOR ********** */
/* Konstruktor : create tabel kosong */
void makeEmpty (TabInt *T)
/* I.S. sembarang */
/* F.S. Terbentuk tabel T kosong dengan kapasitas idxMax-idxMin+1 */
{
    (*T).neff = 0;
}

/* ********** SELEKTOR ********** */
/* *** Banyaknya elemen *** */
int nbElmt (TabInt T)
/* Mengirimkan banyaknya elemen efektif tabel */
/* Mengirimkan nol jika tabel kosong */
{
    return T.neff;
}

/* *** Daya tampung container *** */
int maxNbEl (TabInt T)
/* Mengirimkan maksimum elemen yang dapat ditampung oleh tabel */
{
    return idxMax;
}

/* *** Selektor INDEKS *** */
IdxType getFirstIdx (TabInt T)
/* Prekondisi : Tabel T tidak kosong */
/* Mengirimkan indeks elemen pertama */
{
    return idxMin;
}

IdxType getLastIdx (TabInt T)
/* Prekondisi : Tabel T tidak kosong */
/* Mengirimkan indeks elemen terakhir */
{
    return T.neff;
}

/* *** Menghasilkan sebuah elemen *** */
ElIntType getElmt (TabInt T, IdxType i)
/* Prekondisi : Tabel tidak kosong, i antara FirstIdx(T)..LastIdx(T) */
/* Mengirimkan elemen tabel yang ke-i */
{
    return T.TI[i];
}

/* *** Selektor SET : Mengubah nilai TABEL dan elemen tabel *** */
/* Untuk type private/limited private pada bahasa tertentu */
void setTab (TabInt Tin, TabInt *Tout)
/* I.S. Tin terdefinisi, sembarang */
/* F.S. Tout berisi salinan Tin */
{
    int i;
    for (i=idxMin;i<=idxMax;i++){
        (*Tout).TI[i] = Tin.TI[i];
    }
}

/* Assignment THsl -> Tin */
void setEl (TabInt *T, IdxType i, ElIntType v)
/* I.S. T terdefinisi, sembarang */
/* F.S. Elemen T yang ke-i bernilai v */
/* Mengeset nilai elemen tabel yang ke-i sehingga bernilai v */
{   
    (*T).TI[i] = v;
}
void setneff (TabInt *T, IdxType N)
/* I.S. T terdefinisi, sembarang */
/* F.S. Nilai indeks efektif T bernilai N */
/* Mengeset nilai indeks elemen efektif sehingga bernilai N */
{
    (*T).neff = N;
}

/* ********** Test Indeks yang valid ********** */
boolean isIdxValid (TabInt T, IdxType i)
/* Prekondisi : i sembarang */
/* Mengirimkan true jika i adalah indeks yang valid utk ukuran tabel */
/* yaitu antara indeks yang terdefinisi utk container*/
{
    return ((i >= idxMin) && (i <= idxMax));
}

boolean isIdxEff (TabInt T, IdxType i)
/* Prekondisi : i sembarang*/
/* Mengirimkan true jika i adalah indeks yang terdefinisi utk tabel */
/* yaitu antara FirstIdx(T)..LastIdx(T) */
{
    return (i >= getFirstIdx(T)) && (i <= getLastIdx(T));
}

/* ********** TEST KOSONG/PENUH ********** */
/* *** Test tabel kosong *** */
boolean isEmpty (TabInt T)
/* Mengirimkan true jika tabel T kosong, mengirimkan false jika tidak */
{
    return (T.neff == 0);
}

/* *** Test tabel penuh *** */
boolean isFull (TabInt T)
/* Mengirimkan true jika tabel T penuh, mengirimkan false jika tidak */
{
    return (T.neff == idxMax);
}