CC=gcc
TARGET=main

all:
	$(CC) main.c scr/array/array.c src/inspect/inspect.c src/konfigurasi/mesinkar.c src/konfigurasi/mesinkata.c src/load/load.c src/map/arrayint.c src/map/map.c src/player/player.c src/roll/roll.c src/save/save.c src/skill/listlinier.c src/skill/skill.c src/stack/stack.c src/teleporter/teleporter.c engine/exit/exit.c engine/mainmenu/menu.c engine/game/game.c -o $(TARGET)

clean:
	rm $(TARGET)