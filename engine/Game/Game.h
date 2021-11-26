#ifndef GAME_H
#define GAME_H

#include "../../src/player/player.h"
#include "../../src/stack/stack.h"
#include "../../src/teleporter & inspect/teleporter.h"
#include "../../src/teleporter & inspect/inspect.h"
#include "../../src/map/map.h"
#include "../Exit/exit.h"
#include "../Main Menu/menu.h"

int getNum(char *cmd);

void convertToCommand(int n);

void delay(int detik);

void loading(int inputDetik);

#endif