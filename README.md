# Permainan Mobitangga
Disusun dalam rangka memenuhi Tugas Besar Algoritma dan Struktur Data STI
# Daftar Isi
- [Penjelasan Ringkas Program](https://github.com/codfikri/tubesalstrukdat#penjelasan-ringkas-program)
# Penjelasan Ringkas Program
Mobitangga merupakan permainan yang pada dasarnya merupakan sebuah permainan ular tangga, namun terdapat beberapa modifikasi terhadap mekanisme permainan. Pada permainan Mobitangga terdapat mekanisme yang membuat seorang pemain dapat mengganggu pemain lainnya. Secara garis besar, permainan ini dimainkan mirip dengan ular tangga, pemain yang dapat mencapai akhir dari map merupakan pemenang dari permainan. Setiap pemain akan mendapatkan skill pada setiap turn, lalu pemain juga bisa menggunakan skill yang memiliki berbagai efek. Pada peta permainan terdapat teleporter yang dapat memindahkan posisi pemain dari petak ke-n menuju petak ke-n lainnya.
# Struktur Program
```
.</br>
│   .gitattributes</br>
│   Makefile </br>
│   README.md </br>
│   </br>
├───src </br>
│   │boolean.h </br>
│   │src.zip </br>
│   ├───array </br>
│   │       array.c </br>
│   │       array.h </br>
│   │        </br>
│   ├───konfigurasi </br>
│   │       driverconfig.c </br>
│   │       map.txt </br>
│   │       mesinkar.c </br>
│   │       mesinkar.h </br>
│   │       mesinkata.c </br>
│   │       mesinkata.h </br>
│   │ </br>
│   ├───load </br>
│   │       driverload.c </br>
│   │       load.c </br>
│   │       load.h </br>
│   │        </br>
│   ├───map </br>
│   │       arrayint.c </br>
│   │       arrayint.h </br>
│   │       drivermap.c </br>
│   │       map.c </br>
│   │       map.h </br>
│   │        </br>
│   ├───player </br>
│   │       driver.exe </br>
│   │       driverplayer.c </br>
│   │       player.c </br>
│   │       player.h </br>
│   │        </br>
│   ├───roll </br>
│   │       roll.c </br>
│   │       roll.h </br>
│   │        </br>
│   ├───save </br>
│   │       driversave.c </br>
│   │       save.c </br>
│   │       save.h </br>
│   │        </br>
│   ├───savefile </br>
│   │       TesSave.txt </br>
│   │       tessave2.txt </br>
│   │        </br>
│   ├───skill </br>
│   │       driverskill.c </br>
│   │       listlinier.c </br>
│   │       listlinier.h </br>
│   │       skill.c </br>
│   │       skill.h </br>
│   │        </br>
│   ├───stack </br>
│   │       driverstack.c </br>
│   │       stack.c </br>
│   │       stack.h </br>
│   │        </br>
│   ├───teleporter & inspect </br>
│   │       inspect.c </br>
│   │       inspect.h </br>
│   │       teleporter.c </br>
│   │       teleporter.h </br>
│   │        </br>
│   ├───teleporter </br>
│   │       driverteleporter.c </br>
│   │       driverteleporter.exe </br>
│   │       teleporter.c </br>
│   │       teleporter.h </br>
│   │        </br>
│   └───word </br>
│           driverword.c </br>
│           driverword.exe </br>
│           mesin_kar.c </br>
│           mesin_kar.h </br>
│           mesin_kata.c </br>
│           mesin_kata.h </br>
│            </br>
├───konfigurasi </br>
│       array.h </br>
│       boolean.h </br>
│       map.txt </br>
│       mesinkar.c </br>
│       mesinkar.h </br>
│       mesinkata.c </br>
│       mesinkata.h </br>
│       readconfig.c </br>
│       readconfig.exe </br>
│       teleporter.c </br>
│       teleporter.h </br>
│        </br>
├───engine </br>
│   ├───Exit </br>
│   │       exit.c </br>
│   │       exit.h </br>
│   │        </br>
│   ├───Game </br>
│   │       Game.c </br>
│   │       Game.h </br>
│   │ </br>
│   ├───Main Menu </br>
│   │       menu.c </br>
│   │       menu.h </br>
│   │        </br>
│   └───map </br>
│           arrayint.c </br>
│           arrayint.h </br>
│           drivermap.c </br>
│           map.c </br>
│           map.h </br>
│        </br>
├───.vscode </br>
└──    settings.json </br>
```
