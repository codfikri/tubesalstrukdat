# Permainan Mobitangga
Disusun dalam rangka memenuhi Tugas Besar Algoritma dan Struktur Data STI
# Daftar Isi
- [Penjelasan Ringkas Program](https://github.com/codfikri/tubesalstrukdat#penjelasan-ringkas-program)
- [Struktur Program](https://github.com/codfikri/tubesalstrukdat#struktur-program)
- [Cara Kompilasi Program](https://github.com/codfikri/tubesalstrukdat#cara-kompilasi-program)
- [Versi 1](
- [Pembagian Tugas](https://github.com/codfikri/tubesalstrukdat#pembagian-tugas)
# Penjelasan Ringkas Program
Mobitangga merupakan permainan yang pada dasarnya merupakan sebuah permainan ular tangga, namun terdapat beberapa modifikasi terhadap mekanisme permainan. Pada permainan Mobitangga terdapat mekanisme yang membuat seorang pemain dapat mengganggu pemain lainnya. Secara garis besar, permainan ini dimainkan mirip dengan ular tangga, pemain yang dapat mencapai akhir dari map merupakan pemenang dari permainan. Setiap pemain akan mendapatkan skill pada setiap turn, lalu pemain juga bisa menggunakan skill yang memiliki berbagai efek. Pada peta permainan terdapat teleporter yang dapat memindahkan posisi pemain dari petak ke-n menuju petak ke-n lainnya.
# Cara Kompilasi Program
## Versi 1
1. Pastikan gcc compiler versi terbaru sudah terpasang pada mesin eksekusi (Anda dapat mengecek versi gcc compiler dengan menjalankan command ```gcc --version``` pada command prompt).
2. Jalankan command ```make``` pada command prompt untuk melakukan kompilasi pada program.
3. Jika berhasil dikompilasi, maka akan terdapat ```main.exe``` pada directory program.
## Versi 2
1. Download extension ```Code Runner``` pada Visual Studio Code.
2. Masukkan potongan kode pada file ```settings.json``` seperti berikut</br> 
```
"code-runner.executorMap": {
        "c": "cd $dir && gcc -o $fileNameWithoutExt main.c src/array/array.c src/inspect/inspect.c src/konfigurasi/mesinkar.c src/konfigurasi/mesinkata.c src/load/load.c src/map/arrayint.c src/map/map.c src/player/player.c src/roll/roll.c src/save/save.c src/skill/skill.c src/skill/listlinier.c src/stack/stack.c src/teleporter/teleporter.c engine/exit/exit.c engine/game/game.c engine/Mainmenu/menu.c && $dir$fileNameWithoutExt"
    }
```
3. Jalankan ```main.c``` dan jika berhasil akan muncul file ```main.exe``` pada directory program.
 
# Cara Menjalankan Program
1. Pastikan Anda telah melakukan kompilasi pada program.
2. Jalankan command ./main untuk run program.
3. Jika berhasil run, maka Anda akan tiba pada Main Menu program.
# Struktur Program
```
.
│   .gitattributes
│   Makefile 
│   README.md 
│   
├───src 
│   │boolean.h 
│   │src.zip 
│   ├───array 
│   │       array.c 
│   │       array.h 
│   │ 
│   ├───load 
│   │       driverload.c 
│   │       load.c 
│   │       load.h 
│   │        
│   ├───map 
│   │       arrayint.c 
│   │       arrayint.h 
│   │       drivermap.c 
│   │       map.c 
│   │       map.h 
│   │        
│   ├───player 
│   │       driver.exe 
│   │       driverplayer.c 
│   │       player.c 
│   │       player.h 
│   │        
│   ├───roll 
│   │       roll.c 
│   │       roll.h 
│   │        
│   ├───save 
│   │       driversave.c
│   │       save.c 
│   │       save.h 
│   │             
│   ├───skill 
│   │       driverskill.c 
│   │       listlinier.c 
│   │       listlinier.h 
│   │       skill.c 
│   │       skill.h 
│   │        
│   ├───stack 
│   │       driverstack.c 
│   │       stack.c
│   │       stack.h
│   │        
│   ├───teleporter & inspect 
│   │       inspect.c 
│   │       inspect.h 
│   │       teleporter.c 
│   │       teleporter.h 
│   │        
│   ├───teleporter 
│   │       driverteleporter.c 
│   │       driverteleporter.exe
│   │       teleporter.c 
│   │       teleporter.h 
│   │        
│   └───word 
│           driverword.c 
│           driverword.exe 
│           mesin_kar.c 
│           mesin_kar.h 
│           mesin_kata.c 
│           mesin_kata.h 
│            
├───konfigurasi 
│       array.h 
│       boolean.h
│       map.txt 
│       mesinkar.c
│       mesinkar.h 
│       mesinkata.c 
│       mesinkata.h 
│       readconfig.c 
│       readconfig.exe 
│       teleporter.c 
│       teleporter.h 
│
├───engine 
│   ├───Exit
│   │       exit.c
│   │       exit.h 
│   │        
│   ├───Game 
│   │       Game.c
│   │       Game.h 
│   │ 
│   ├───Main Menu 
│   │       menu.c 
│   │       menu.h 
│   │        
│   └───map 
│           arrayint.c 
│           arrayint.h 
│           drivermap.c 
│           map.c 
│           map.h 
│        
├───.vscode 
└──    settings.json
```
# Pembagian Tugas
1. 18220001 - Stephanie Hutagalung
     - Membuat ADT Stack
     - Membuat fitur Load
     - Membuat firut Save
     - Merevisi fitur Map
     - Membuat fitur Undo
     - Mengujicoba Main Program
     - Mengisi Laporan
2. 18220031 - Muhammad Raihan Aulia
     - Membuat ADT List Linear
     - Membuat dan merevisi ADT Skill
     - Membuat Main Program
     - Mengimplementasikan ADT Skill
     - Merevisi main program
     - Merivisi ADT Player
3. 18220071 - Muhammad Zaky
     - Membuat ADT List Linear
     - Membuat ADT Skill
     - Merevisi Main Program
     - Mengimplementasikan ADT Skill
     - Membuat kerangka laporan
     - Mengisi laporan
     - Membuat file readme
     - Membuat fitur makefile
4. 18220097 - Muhamad Fikri Nurohman
     - Membuat dan Merevisi ADT Player
     - Membuat rancangan awal ADT Teleporter dan List Teleporter
     - Membuat ADT Array of Character
     - Membuat Main Program
     - Menambahkan menu exit dan game awal
     - Membuat file game yang menggabungkan seluruh ADT
     - Merevisi fitur Roll
     - Membuat fitur makefile
5. 18220105 - Made Adi Surya Pramana
     - Merevisi ADT Teleporter dan List Teleporter
     - Membuat ADT Array of Integer
     - Membuat ADT Mesin Kata dan Mesin Karakter
     - Membuat fitur pembacaan file konfigurasi
     - Membuat fitur Inspect
     - Membuat fitur Roll
     - Membuat fitur Map
     - Merevisi Main Program
     - Mengisi Laporan
