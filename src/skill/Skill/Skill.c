#include <stdio.h>
#include <stdlib.h>
#include "skill.h"
#include "boolean.h"
#include "listlinier.h"
#include "buff.h"
#include "player.h"
// dari player.c
void CreatePlayerList(PlayerList *P){ //sama kaya CreateEmpty pada List
    FirstPlayer(*P) = Nil;
}

boolean isListPlayerEmpty(PlayerList PL){ //sama kaya IsEmpty pada list
    return FirstPlayer(PL)==Nil;
}

addressPlayer AlokasiPlayer(char* nama, List Skillpemain, int noUrut){ //sama kaya Alokasi pada list
    addressPlayer AP;
    AP = (Player *) malloc(sizeof(Player));
    if (AP != Nil){
        Petak(AP) = 1;
        NoUrut(AP) = noUrut;
        Nama(AP) = nama;
        Skill(AP) = Skillpemain;
        isImmune(AP) = false;
        isHokiBesar(AP) = false;
        isHokiKecil(AP) = false;
        isPostCermin(AP) = false;
        NextPlayer(AP) = Nil;
    } else {
        return Nil;
    }
    return AP;
}

void insertPlayer(PlayerList *PL, addressPlayer P){ //sama kaya InsertLast pada list
    addressPlayer last;
    if (isListPlayerEmpty(*PL)){
        NextPlayer(P) = FirstPlayer(*PL);
        FirstPlayer(*PL) = P;
    } else{
        last = FirstPlayer(*PL);
        while(NextPlayer(last) != Nil){
            last = NextPlayer(last);
        }
        NextPlayer(last) = P;
    }
}

void insertPlayerToList(PlayerList *PL, char* nama, List Skillpemain, int noUrut, boolean isLastPlayer){ //sama kaya InsVlast pada list
    addressPlayer P;
    P = AlokasiPlayer(nama, Skillpemain, noUrut);
    if (P != Nil){
        insertPlayer(PL, P);
        if (isLastPlayer){
            NextPlayer(P) = FirstPlayer(*PL);
        }
    }
}

void inputPlayerList(PlayerList *P, int n){
    char playerName[16];
    List L;
    boolean isLastPlayer = false;
    CreateEmpty(&L);
    for (int i=1; i<=n; i++){
        printf("Masukan nama pemain ke-%d: ", i);
        scanf("%s", playerName);
        if (i==n){
            isLastPlayer = true;
        }
        insertPlayerToList(P, playerName, L, i, isLastPlayer);
    }
}

void printPlayer(PlayerList PL, int n){ //sama kaya printForward di list
    if (isListPlayerEmpty(PL)){printf("List player masih kosong");}
    else{
        addressPlayer P;
        P = FirstPlayer(PL);
        int i = 1;
        while (i <= n){
            printf("Pemain ke %d telah terdaftar\n", NoUrut(P));
            printf("Pemain ke %d berada pada petak %d\n", NoUrut(P), Petak(P));
            P = NextPlayer(P);
            i++;
        }
    }
}

// dari listlinier.c --------------------------------------------------
/* PROTOTYPE */
/****************** TEST LIST KOSONG ******************/
boolean IsEmpty (List L)
/* Mengirim true jika list kosong */
{
    return First(L) == Nil;
}

/****************** PEMBUATAN LIST KOSONG ******************/
void CreateEmpty (List *L)
/* I.S. sembarang             */
/* F.S. Terbentuk list kosong */
{
    First(*L) = Nil;
}

address Alokasi (infotype X)
/* Mengirimkan address hasil alokasi sebuah elemen */
/* Jika alokasi berhasil, maka address tidak nil, dan misalnya */
/* menghasilkan P, maka Info(P)=X, Next(P)=Nil */
/* Jika alokasi gagal, mengirimkan Nil */
{
    address P = (address) malloc(sizeof(address) + 1);
    Info(P) = X;
    Next(P) = Nil;
    return P;
}

void Dealokasi (address *P)
/* I.S. P terdefinisi */
/* F.S. P dikembalikan ke sistem */
/* Melakukan dealokasi/pengembalian address P */
{
    free(*P);
}

address Search (List L, infotype X)
/* Mencari apakah ada elemen list dengan Info(P)= X */
/* Jika ada, mengirimkan address elemen tersebut. */
/* Jika tidak ada, mengirimkan Nil */
{
    if (IsEmpty(L)){
        return Nil;
    }

    address p = First(L);
    while (p != Nil && Info(p) != X){
        p = Next(p);
    }
    return p;
}

/*** PENAMBAHAN ELEMEN ***/
void InsVFirst (List *L, infotype X)
/* I.S. L mungkin kosong */
/* F.S. Melakukan alokasi sebuah elemen dan */
/* menambahkan elemen pertama dengan nilai X jika alokasi berhasil */
{
    address newNode = Alokasi(X);
    if (newNode != Nil){
        Next(newNode) = First(*L);
        First(*L) = newNode;
    }
}

void InsVLast (List *L, infotype X)
/* I.S. L mungkin kosong */
/* F.S. Melakukan alokasi sebuah elemen dan */
/* menambahkan elemen list di akhir: elemen terakhir yang baru */
/* bernilai X jika alokasi berhasil. Jika alokasi gagal: I.S.= F.S. */
{
    address newNode = Alokasi(X);
    if (IsEmpty(*L)){
        InsVFirst(L, X);
    }
    else{
        address p = First(*L);
        while (Next(p) != Nil){
            p = Next(p);
        }
        Next(p) = newNode;
        Next(Next(p)) = Nil;
    }
}

/*** PENGHAPUSAN ELEMEN ***/
void DelVFirst (List *L, infotype *X)
/* I.S. List L tidak kosong  */
/* F.S. Elemen pertama list dihapus: nilai info disimpan pada X */
/*      dan alamat elemen pertama di-dealokasi */
{
    address p = First(*L);
    *X = Info(p);
    First(*L) = Next(p);
    Dealokasi(&p);
}

void DelVLast (List *L, infotype *X)
/* I.S. list tidak kosong */
/* F.S. Elemen terakhir list dihapus: nilai info disimpan pada X */
/*      dan alamat elemen terakhir di-dealokasi */
{
    address p = First(*L);
    address loc = Nil;

    if (Next(p) != Nil){
        while(Next(Next(p)) != Nil){
            p = Next(p);
        }
        *X = Info(Next(p));
        Dealokasi(&Next(p));
        Next(p) = Nil;
    }
    else{
        DelVFirst(L, X);
    }
}

/****************** PRIMITIF BERDASARKAN ALAMAT ******************/
/*** PENAMBAHAN ELEMEN BERDASARKAN ALAMAT ***/
void InsertFirst (List *L, address P)
/* I.S. Sembarang, P sudah dialokasi  */
/* F.S. Menambahkan elemen ber-address P sebagai elemen pertama */
{
    address first = First(*L);
    if (P != Nil){
        Next(P) = first;
        First(*L) = P;
    }
}

void InsertAfter (List *L, address P, address Prec)
/* I.S. Prec pastilah elemen list dan bukan elemen terakhir, */
/*      P sudah dialokasi  */
/* F.S. Insert P sebagai elemen sesudah elemen beralamat Prec */
{
    Next(P) = Next(Prec);
    Next(Prec) = P;
}

void InsertLast (List *L, address P)
/* I.S. Sembarang, P sudah dialokasi  */
/* F.S. P ditambahkan sebagai elemen terakhir yang baru */
{
    if (IsEmpty(*L)){
        First(*L) = P;
    }
    else{
        address last = First(*L);
        while (Next(last) != Nil){
            last = Next(last);
        }
        Next(P) = Nil;
        Next(last) = P;
    }
}

/*** PENGHAPUSAN SEBUAH ELEMEN ***/
void DelFirst (List *L, address *P)
/* I.S. List tidak kosong */
/* F.S. P adalah alamat elemen pertama list sebelum penghapusan */
/*      Elemen list berkurang satu (mungkin menjadi kosong) */
/* First element yg baru adalah suksesor elemen pertama yang lama */
{
    address delete = First(*L);
    *P = delete;
    First(*L) = Next(delete);
}

void DelP (List *L, infotype X)
/* I.S. Sembarang */
/* F.S. Jika ada elemen list beraddress P, dengan Info(P)=X  */
/* Maka P dihapus dari list dan di-dealokasi */
/* Jika tidak ada elemen list dengan Info(P)=X, maka list tetap */
/* List mungkin menjadi kosong karena penghapusan */
{
    if (!IsEmpty(*L)){
        address p = First(*L);
        address dummy;
        if(Info(p) == X){
            DelFirst(L, &dummy);
        }
        else{
            while (Next(p) != Nil && Info(Next(p)) != X){
                p = Next(p);
            }
            if(Next(p) != Nil){
                DelAfter(L, &dummy, p);
            }
        }
    }
}

void DelLast (List *L, address *P)
/* I.S. List tidak kosong */
/* F.S. P adalah alamat elemen terakhir list sebelum penghapusan  */
/*      Elemen list berkurang satu (mungkin menjadi kosong) */
/* Last element baru adalah predesesor elemen terakhir yg lama, */
/* jika ada */
{
    address last = First(*L);
    if (Next(last) == Nil){
        DelFirst(L, P);
    }
    else{
        while(Next(Next(last)) != Nil){
            last = Next(last);
        }
        DelAfter(L, P, last);
    }
}

void DelAfter (List *L, address *Pdel, address Prec)
/* I.S. List tidak kosong. Prec adalah anggota list  */
/* F.S. Menghapus Next(Prec): */
/*      Pdel adalah alamat elemen list yang dihapus  */
{
    *Pdel = Next(Prec);
    Next(Prec) = Next(*Pdel);
}

void PrintInfo (List L)
/* I.S. List mungkin kosong */
/* F.S. Jika list tidak kosong, iai list dicetak ke kanan: [e1,e2,...,en] */
/* Contoh : jika ada tiga elemen bernilai 1, 20, 30 akan dicetak: [1,20,30] */
/* Jika list kosong : menulis [] */
/* Tidak ada tambahan karakter apa pun di awal, akhir, atau di tengah */
{
    printf("[");
    if (!IsEmpty(L)){
        address p = First(L);
        while (p != Nil){
            printf("%d", Info(p));
            p = Next(p);

            if (p != Nil){
                printf(",");
            }
        }
    }
    printf("]");
}

int NbElmt (List L)
/* Mengirimkan banyaknya elemen list; mengirimkan 0 jika list kosong */
{
    int ctr = 0;
    if (!IsEmpty(L)){
        address p = First(L);
        while (p != Nil){
            ctr++;
            p = Next(p);
        }
    }
    return ctr;
}

/*** Prekondisi untuk Max/Min/rata-rata : List tidak kosong ***/
infotype Max (List L)
/* Mengirimkan nilai Info(P) yang maksimum */
{
    address p = First(L);
    infotype max = Info(p);
    while (Next(p) != Nil){
        p = Next(p);
        if(Info(p) > max){
            max = Info(p);
        }
    }
    return max;
}

address AdrMax (List L)
/* Mengirimkan address P, dengan info(P) yang bernilai maksimum */
{
    return Search(L, Max(L));
}

infotype Min (List L)
/* Mengirimkan nilai info(P) yang minimum */
{
    address p = First(L);
    infotype min = Info(p);
    while (Next(p) != Nil){
        p = Next(p);
        if(Info(p) < min){
            min = Info(p);
        }
    }
    return min;
}

address AdrMin (List L)
/* Mengirimkan address P, dengan info(P) yang bernilai minimum */
{
    return Search(L, Min(L));
}

float Average (List L)
/* Mengirimkan nilai rata-rata info(P) */
{
    if (IsEmpty(L)){
		return 0;
	} else {
		address P = First(L);
		float tot = Info(P);
		float ctr = 1;
		while (Next(P) != Nil){
			P = Next(P);
			tot = tot + Info(P);
			ctr++;
		}
		return (tot/ctr);
	}
}

/****************** PROSES TERHADAP LIST ******************/

void InversList (List *L)
/* I.S. sembarang. */
/* F.S. elemen list dibalik : */
/* Elemen terakhir menjadi elemen pertama, dan seterusnya. */
/* Membalik elemen list, tanpa melakukan alokasi/dealokasi. */
{
    if (!IsEmpty(*L)){
		address P = First(*L);
		while (Next(P) != Nil){
			P = Next(P);
		}
		address last = P;
		address Prec;
		while (P != First(*L)){
			Prec = First(*L);
			while (Next(Prec) != P){
				Prec = Next(Prec);
			}
			Next(P) = Prec;
			P = Next(P);
		}
		Next(P) = Nil;
		First(*L) = last;
	}
}
void Konkat1 (List *L1, List *L2, List *L3)
/* I.S. L1 dan L2 sembarang */
/* F.S. L1 dan L2 kosong, L3 adalah hasil konkatenasi L1 & L2 */
/* Konkatenasi dua buah list : L1 dan L2    */
/* menghasilkan L3 yang baru (dengan elemen list L1 dan L2) */
/* dan L1 serta L2 menjadi list kosong.*/
/* Tidak ada alokasi/dealokasi pada prosedur ini */
{
    CreateEmpty(L3);
    First(*L3) = First(*L1);
    First(*L1) = Nil;
    if (IsEmpty(*L3)){
        First(*L3) = First(*L2);
    }
    else{
        address p = First(*L3);
        while (Next(p) != Nil){
            p = Next(p);
        }
        Next(p) = First(*L2);
    }
    First(*L2) = Nil;
}

// dari skill.c ----------------------------------------------------------------------------------
/****************** PENCARIAN SEBUAH ELEMEN LIST ******************/
address SearchId (List L, infotype X)
/* Mencari apakah ada elemen list dengan Info(P)= X */
/* Jika ada, mengirimkan address elemen tersebut. */
/* Jika tidak ada, mengirimkan Nil */
{
    // Kamus lokal
    address p;
    boolean found;
    // Algoritma
    p = First(L);
    found = false;
    while((p != Nil) && (!found)){
        if (Info(p) == X){
            found = true;
        }
        else{
            p = Next(p);
        }
    }
    if(found) {
        return p;
    }
    else{
        return Nil;
    }
}


void DelAddress(List *L, address nartoh)
/* I.S. Sembarang */
/* F.S. Jika ada elemen list beraddress P,  */
/* Maka P dihapus dari list dan di-dealokasi */
/* List mungkin menjadi kosong karena penghapusan */
{
    // Kamus lokal
    address hinata;

    // Algoritma
    hinata = First(*L);
    if(nartoh != Nil){
        if(nartoh == hinata){
            DelFirst(L,&nartoh);
        }
        else{
            while(Next(hinata) != nartoh){
                hinata = Next(hinata);
            }
            DelAfter(L,&nartoh, hinata);
        }
        Dealokasi(&nartoh);
    }
}


/****************** PROSES TERHADAP LIST ******************/



// SKILL LESGOOOOOO ----------------------------------------------------------------
void printSkill(List skillPemain)
{
    // Kamus Lokal
    address p;
    int count = 1;
    char daftarSkill[][22] =
    {
        "Pintu Ga Ke Mana Mana",
        "Mesin Waktu",
        "Baling Baling Jambu",
        "Cermin Pengganda",
        "Senter Pembesar Hoki",
        "Senter Pengecil Hoki",
        "Mesin Penukar Posisi"
    };
    if(IsEmpty(skillPemain)){
        printf("Ndda ada skill-nya~~\n");
    }
    else{
        p = First(skillPemain);
        printf("Kamu memiliki skill:\n");
        while(p != Nil){
            printf("%d. %s\n", count, daftarSkill[Info(p)]);
            count += 1;
            p = Next(p);
        }
    }
}

void getSkill(List *skillPemain){
    int x;

    if(NbElmt(*skillPemain) <= 10){
        x = rand();
        srand(x);
        x = chance((x)%100 +1);

        if(x != -999){
            InsVLast(skillPemain, x);
        }
    }
}

int chance(int x){
    if ((x >= 1) && (x <= 10)){
        return 0;
    }
    else if((x >= 11) && (x <= 20)){
        return 1;
    }
    else if((x >= 21) && (x <= 30)){
        return 2;
    }
    else if((x >= 31) && (x <= 36)){
        return 3;
    }
    else if((x >= 37) && (x <= 51)){
        return 4;
    }
    else if((x >= 52) && (x <= 66)){
        return 5;
    }
    else if((x >= 67) && (x <= 70)){
        return 6;
    }
    else{
        return -999;
    }
}

void MenuSkill(addressPlayer AP) // main dari skill nya
{
    // Kamus lokal
    int n = 0;

    // Algoritma
    printf(">>====SKILL==============================================================+\n");
    printSkill(Skill(AP));
    printf("\n>> Gunakan 0 untuk melihat skill sekarang\n");
    printf(">> Gunakan -99 untuk keluar dari menu skill\n");
    while(n != -99){
        scanf("%d", &n);
        if(abs(n) <= NbElmt(Skill(AP)) && n != 0){
            if(n < 0){
                DelSkill(&Skill(AP), -n);
            }
            else{
                useSkill(AP, n);
            }
        }
        else if(n == 0){
            printf("\n>>=======================================================================+\n");
            printSkill(Skill(AP));
        }
        else{
            printf("Input kok ke urutan kosong, ngga masuk akal.\n");
        }
    }
}


void DelSkill(List *skillPemain,int n)
{
    // Kamus lokal
    address p;
    int x;
    char daftarSkill[][22] =
    {
        "Pintu Ga Ke Mana Mana",
        "Mesin Waktu",
        "Baling Baling Jambu",
        "Cermin Pengganda",
        "Senter Pembesar Hoki",
        "Senter Pengecil Hoki",
        "Mesin Penukar Posisi"
    };

    // Algoritma
    p = First(*skillPemain);
    for(int i = 1; i < n; i++){
        p = Next(p);

    }
    printf("anda membuang skill %s-nyan\n", daftarSkill[Info(p)]);
    DelAddress(skillPemain, p);
}

void useSkill(addressPlayer AP, int n)
{
    // Kamus Lokal
    address p;
    infotype idSkill;
    List skillpemain = Skill(AP);

    char daftarSkill[][22] =
    {
        "Pintu Ga Ke Mana Mana",
        "Mesin Waktu",
        "Baling Baling Jambu",
        "Cermin Pengganda",
        "Senter Pembesar Hoki",
        "Senter Pengecil Hoki",
        "Mesin Penukar Posisi"
    };

    // Algoritma
    p = First(skillpemain);
    for(int i = 1; i < n; i++){
        p = Next(p);
    }
    idSkill = Info(p);
    // printf("player menggunakan skill %s-nyan\n", daftarSkill[idSkill]);
    switch (idSkill)
    {
    case 0:
        pintuGaKemana(AP, p);
        break;
    case 1:
        mesinwaktu(AP, p);
        break;
    case 2:
        balingjambu(AP, p);
        break;
    case 3:
        cerminGanda(AP, p);
        break;
    case 4:
        senterBesarHoki(AP, p);
        break;
    case 5:
        senterKecilHoki(AP, p);
        break;
    case 6:
        mesinPenukarPosisi(AP, p);
        break;
    }
}



// Use Skill uwu~~~~~~~~~~~~~~
void pintuGaKemana(addressPlayer AP, address p)
/* Memberi buff kepada pemain */
{

    List skillpemain = Skill(AP);

    isImmune(AP) = true;
    DelAddress(&skillpemain, p);
    First(Skill(AP)) = First(skillpemain);
    printf(">> Walaupun pintu tersebut tidak menuju ke manapun, %s-sama merasakan dirinya\n   mendapatkan tameng perlindungan teleportasi\n", Nama(AP));
}

void mesinwaktu(addressPlayer AP, address p)
/* Membuat seluruh player kecuali pengguna skill sejauh roll dadu */
{

    List skillpemain = Skill(AP);
    int roll;


    DelAddress(&skillpemain, p);
    First(Skill(AP)) = First(skillpemain);
    printf(">> %s-sama mengubah waktu yang ada yang mengakibatkan setiap pemain selain %s-sama\n   Mundur sejauh rolldadu\n", Nama(AP), Nama(AP));
}

void balingjambu(addressPlayer AP, address p)
{

    List skillpemain = Skill(AP);

    DelAddress(&skillpemain, p);
    First(Skill(AP)) = First(skillpemain);
    printf(">> %s-sama memaksa tiap pemain memakai Baling-Baling Jambu yang mengakibatkan\n   mereka maju sejauh rolldadu.\n",Nama(AP));
}

void cerminGanda(addressPlayer AP, address p)
{

    List skillpemain = Skill(AP);

    if(isPostCermin(AP)){
        printf(">> Maaf anda sudah menggunakan cermin pengganda pada giliran ini. \n");
    }
    else{
        if(NbElmt(skillpemain) <= 9){
            isPostCermin(AP) = true;
            DelAddress(&skillpemain, p);
            First(Skill(AP)) = First(skillpemain);
            getSkill(&skillpemain);
            getSkill(&skillpemain);
            printf(">> Dengan kekuatan Cermin Pengganda dan berkah dari Dolos-sama,\n   %s-sama mendapatkan 2 skill baru. \n", Nama(AP));
        }
        else{
            printf(">> skill anda sudah terlalu penuh, tidak dapat menggunakan skill ini.\n");
        }
    }
}

void senterBesarHoki(addressPlayer AP, address p)
{

    List skillpemain = Skill(AP);

    if(isHokiBesar(AP) || isHokiKecil(AP)){
        printf(">> Maaf anda sudah menggunakan salah satu senter hoki... \n");
    }
    else{
        isHokiBesar(AP) = true;
        DelAddress(&skillpemain, p);
        First(Skill(AP)) = First(skillpemain);
        printf(">> Ketika anda menggunakan Senter Pembesar Hoki, muncul cahaya keemasan\n   beserta suara Aqua-sama yang menyebutkan \"Blessing\" \n");
    }
}

void senterKecilHoki(addressPlayer AP, address p)
{
    List skillpemain = Skill(AP);
    if(isHokiBesar(AP) || isHokiKecil(AP)){
        printf(">> Maaf anda sudah menggunakan salah satu senter hoki... \n");
    }
    else{
        isHokiKecil(AP) = true;
        DelAddress(&skillpemain, p);
        First(Skill(AP)) = First(skillpemain);
        printf(">> Ketika anda menggunakan Senter Pengecil Hoki, Senter tersebut menghisap cahaya,\n   terdengar suara asing yang mengutuk anda \"Misfortune\" \n");
    }
}

void mesinPenukarPosisi(addressPlayer AP, address p)
{

    List skillpemain = Skill(AP);
    DelAddress(&skillpemain, p);
    Skill(AP) = skillpemain;
    printf(">> Anda menggunakan Mesin Penukar Posisi!\n   Anda menukar posisi anda dengan Player-sama\n", Nama(AP));
}


void setAfterTurn(addressPlayer AP)
{
    isImmune(AP) = false;
    isPostCermin(AP) = false;
    isHokiBesar(AP) = false;
    isHokiKecil(AP) = false;
}


// Masukin ke inisialisasi permainan -------------------------------------------
int main()
{
    PlayerList PL;
    CreatePlayerList(&PL);
    int l = 1;

    address p;
    inputPlayerList(&PL, l);
    printPlayer(PL, l);
    addressPlayer P1 = FirstPlayer(PL);


    srand(time(NULL));
    for(int i = 0; i < 10; i++){
        getSkill(Skill(&P1));
    }

    // test(P1);



    MenuSkill(P1);
    MenuSkill(P1);
}
