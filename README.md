# Permainan Mobitangga
Disusun dalam rangka memenuhi Tugas Besar Algoritma dan Struktur Data STI
# Daftar Isi
- [Penjelasan Ringkas Program](https://github.com/codfikri/tubesalstrukdat#penjelasan-ringkas-program)
- [Struktur Program](https://github.com/codfikri/tubesalstrukdat#struktur-program)
- [Pembagian Tugas](https://github.com/codfikri/tubesalstrukdat#pembagian-tugas)
# Penjelasan Ringkas Program
Mobitangga merupakan permainan yang pada dasarnya merupakan sebuah permainan ular tangga, namun terdapat beberapa modifikasi terhadap mekanisme permainan. Pada permainan Mobitangga terdapat mekanisme yang membuat seorang pemain dapat mengganggu pemain lainnya. Secara garis besar, permainan ini dimainkan mirip dengan ular tangga, pemain yang dapat mencapai akhir dari map merupakan pemenang dari permainan. Setiap pemain akan mendapatkan skill pada setiap turn, lalu pemain juga bisa menggunakan skill yang memiliki berbagai efek. Pada peta permainan terdapat teleporter yang dapat memindahkan posisi pemain dari petak ke-n menuju petak ke-n lainnya.
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
2. 18220031 - Muhammad Raihan Aulia
3. 18220071 - Muhammad Zaky
- Membuat ADT
- Mengisi Laporan
- Membuat file readme
4. 18220097 - Muhamad Fikri Nurohman
5. 18220105 - Made Adi Surya Pramana
