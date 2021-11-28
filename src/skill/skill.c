/*
PENGGUNAAN SKILL
menggunakan seed sebelumya untuk random

gunakan getSkill(&skillPemain) untuk mendapatkan skill (skillPemain : List)
untuk melakukan pemanggilan command skill, gunakan MenuSkill(AP) (AP : AddressPlayer)

PERINGATAN!!
random pada getskill tidak menggunakan seed yang digenerate oleh fungsi, melainkan menghasilkan seed baru
*/

#include "skill.h"


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


void DelAddress(List *L, address p)
/* I.S. Sembarang */
/* F.S. Jika ada elemen list beraddress P,  */
/* Maka P dihapus dari list dan di-dealokasi */
/* List mungkin menjadi kosong karena penghapusan */
{
    // Kamus lokal
    address q;

    // Algoritma
    q = First(*L);
    if(p != Nil){
        if(p == q){
            DelFirst(L,&p);
        }
        else{
            while(Next(q) != p){
                q = Next(q);
            }
            DelAfter(L,&p, q);
        }
        Dealokasi(&p);
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
        printf(">> Tidak terdapat skill di sini...\n");
    }
    else{
        p = First(skillPemain);
        printf(">> Kamu memiliki skill:\n");
        while(p != Nil){
            printf("       %d. %s\n", count, daftarSkill[Info(p)]);
            count += 1;
            p = Next(p);
        }
    }
}

void getSkill(List *skillPemain){
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

    if(NbElmt(*skillPemain) <= 10){
        x = rand();
        srand(x);
        x = chance((x)%100 +1);
        if(x != -999){
            InsVLast(skillPemain, x);
            printf("Anda mendapatkan skill %s.\n", daftarSkill[x]);

        }
        else{
            printf("Anda Mendapatkan skill yang tidak berguna. anda langsung membuangnya.\n");
        }
    }
}

int chance(int x){
    /*
    else if((x >= 11) && (x <= 20)){
        return 1; // Mesin Waktu
    }
    else if((x >= 21) && (x <= 30)){
        return 2; // Baling baling jambu
    }
    */
    if ((x >= 1) && (x <= 14)){
        return 0; // Pintu ga kemana mana
    }
    else if((x >= 15) && (x <= 24)){
        return 3; // Cermin Pengganda
    }
    else if((x >= 25) && (x <= 43)){
        return 4; // Senter pembesar hoki
    }
    else if((x >= 44) && (x <= 62)){
        return 5; // senter pengecil hoki
    }
    else if((x >= 63) && (x <= 70)){
        return 6; // Mesin penukar posisi
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
    printf("\n\\_____/SKILL\\____________________________________________________________________________/\n");
    printf(">> Masukkan urutan skill yang ingin dipakai.\n   Jika ingin membuang skill, tambahkan \"-\" didepan urutan skill yang ingin dibuang.\n");
    printf(">> DILARANG KERAS MEMASUKKAN INPUT SELAIN BILANGAN\n");
    while(n != -99){
        printf("\n>>================+\n");
        printSkill(Skill(AP));
        printf(">> Gunakan -99 untuk keluar dari menu skill\n");
        printf("\n>> Masukkan urutan skill: ");
        scanf("%d", &n);

        if(abs(n) <= NbElmt(Skill(AP)) && n != 0){
            if(n < 0){
                DelSkill(&Skill(AP), -n);
            }
            else{
                useSkill(AP, n);
            }
        }
        else if(n!= -99){
            printf(">> Input anda menunjuk ke urutan kosong, Masukkan input yang benar.\n");
        }
    }
    printf(">> Memberhentikan command skill....\n");
    delay(1);
    printf("\n\\__________________________________________________________________________________________/\n\n");
}


void DelSkill(List *skillPemain,int n)
// Menghapus skill
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
    printf(">> Walaupun banyak yang menginginkan skill ini,\n   anda membuang skill %s dihadapan mereka.\n", daftarSkill[Info(p)]);
    DelAddress(skillPemain, p);
}

void useSkill(addressPlayer AP, int n)
// Menggunakan skill
{
    // Kamus Lokal
    address p;
    infotype idSkill;
    List skillpemain = Skill(AP);

    // Algoritma
    p = First(skillpemain);
    for(int i = 1; i < n; i++){
        p = Next(p);
    }
    idSkill = Info(p);
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
/* Memberi buff imunitas kepada pemain */
{

    List skillpemain = Skill(AP);

    isImmune(AP) = true;
    DelAddress(&skillpemain, p);
    First(Skill(AP)) = First(skillpemain);
    printf(">> Walaupun pintu tersebut tidak menuju ke manapun, %s-sama merasakan dirinya\n   mendapatkan tameng perlindungan teleportasi\n", Nama(AP));
    printf(">> %s mendapatkan status buff Imunitas Teleport\n", Nama(AP));
}

void mesinwaktu(addressPlayer AP, address p)
/* Membuat seluruh player kecuali pengguna skill sejauh roll dadu */
{

    List skillpemain = Skill(AP);
    int roll;
    addressPlayer tempP = NextPlayer(AP);


    roll = rand() % 6 + 1;
    srand(roll);
    printf("%s melakukan roll daaaaaan, Mendapatkan %d !!!!\n", Nama(AP), roll);

    while(tempP!= AP){
        if(Petak(tempP)< roll){
            printf("%s tidak dapat mundur sejauh %d.\n", Nama(tempP), roll);
        }
        else{
            printf("%s  mundur sejauh %d.\n", Nama(tempP), roll);
            Petak(tempP) -= roll;
        }
        tempP = NextPlayer(tempP);
    }

    DelAddress(&skillpemain, p);
    First(Skill(AP)) = First(skillpemain);

}

void balingjambu(addressPlayer AP, address p)
{

    List skillpemain = Skill(AP);
    int roll;
    addressPlayer tempP = NextPlayer(AP);

    roll = rand() % 6 + 1;
    srand(roll);
    printf("%s melakukan roll daaaaaan, Mendapatkan %d !!!!\n", Nama(AP), roll);

    while(tempP!= AP){
        if(Petak(tempP)< roll){
            printf("%s tidak dapat mundur sejauh %d.\n", Nama(tempP), roll);
        }
        else{
            printf("%s tidak dapat mundur sejauh %d.\n", Nama(tempP), roll);
            Petak(tempP) += roll;
        }
        tempP = NextPlayer(tempP);
    }

    DelAddress(&skillpemain, p);
    First(Skill(AP)) = First(skillpemain);
}

void cerminGanda(addressPlayer AP, address p)
{

    List skillpemain = Skill(AP);
    int jlhpre = NbElmt(skillpemain);
    if(isPostCermin(AP)){
        printf(">> Maaf anda sudah menggunakan cermin pengganda pada giliran ini. \n");
    }
    else{
        if(NbElmt(skillpemain) <= 9){
            isPostCermin(AP) = true;
            DelAddress(&skillpemain, p);
            getSkill(&skillpemain);
            getSkill(&skillpemain);
            while(NbElmt(skillpemain) < jlhpre+1){
                getSkill(&skillpemain);
            }
            First(Skill(AP)) = First(skillpemain);

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
        printf(">> Ketika anda menggunakan Senter Pembesar Hoki, muncul cahaya keemasan\n   beserta suara Aqua-sama yang menyebutkan \"Blessing!!!\" \n");
        printf(">> %s mendapatkan status buff Luck\n", Nama(AP));
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
        printf(">> Ketika anda menggunakan Senter Pengecil Hoki, Senter tersebut menghisap cahaya,\n   anda merasakan keburuntungan anda tersisa sedikit \n");
        printf(">> %s mendapatkan status buff Unluck\n", Nama(AP));
    }
}

void mesinPenukarPosisi(addressPlayer AP, address p)
{
    addressPlayer tempP = NextPlayer(AP);
    int n, tempPetak;
    int countp = 0;
    while(tempP!= AP){
        printf("%d. %s berada pada petak %d.\n", countp+1, Nama(tempP), Petak(tempP));
        tempP = NextPlayer(tempP);
        countp += 1;
    }
    printf(">> Anda ingin mengganti posisi dengan siapa?\n   (masukkan 0 jika ingin membatalkan): ");
    scanf("%d", &n);
    while(n > countp || n < 0){
        printf(">> Masukan salah, mohon berikan masukan yang benar! : ");
        scanf("%d", &n);
    }
    if(n==0){
        printf(">> Mesin penukar posisi dibatalkan, mesin dimatikan.\n");
    }
    else{
        tempP = NextPlayer(AP);
        while(n > 1){
            tempP = NextPlayer(tempP);
            n -= 1;
        }
        tempPetak = Petak(AP);
        Petak(AP) = Petak(tempP);
        Petak(tempP) = tempPetak;
        printf(">> Mesin Penukar posisi dijanlankan... Menukar posisi %s-sama dengan %s...\n", Nama(AP),Nama(tempP));
        delay(1);
        printf(">> Mesin penukar sukses dijalankan! tetapi energinya sudah habis.\n");
    }

    List skillpemain = Skill(AP);
    DelAddress(&skillpemain, p);
    Skill(AP) = skillpemain;
}


void setAfterTurn(addressPlayer AP)
// ini buat bikin semuanya balik jadi false jika sudah lewat gilirannya
{
    isPostCermin(AP) = false;
    isHokiBesar(AP) = false;
    isHokiKecil(AP) = false;
}


void delay(int detik) {
    // Converting time into milli_seconds
    int mili_seconds = 1000 * detik;
    // Storing start time
    clock_t start_time = clock();
    // looping till required time is not achieved
    while (clock() < start_time + mili_seconds);
}

void loading(int inputDetik) {
    int i;
    for (i = 0; i < inputDetik; i++) {
        // delay of one second
        delay(1);
    }
    printf("\n");
}

