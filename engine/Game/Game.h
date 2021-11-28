#ifndef GAME_H
#define GAME_H

// #include "../../src/player/player.h"
#include <stdio.h>
#include <stdlib.h>
#include "../../src/skill/skill.h"
#include "../../src/stack/stack.h"
#include "../../src/teleporter/teleporter.h"
#include "../../src/inspect/inspect.h"
#include "../../src/map/map.h"
#include "../../src/load/load.h"
#include "../../src/save/save.h"
#include "../../src/konfigurasi/mesinkar.h"
#include "../../src/konfigurasi/mesinkata.h"
#include "../../src/roll/roll.h"
#include "../Exit/exit.h"
#include "../Mainmenu/menu.h"

void showCommands();

int getNum(char *cmd);

void Turn(addressPlayer AP);

void gameFinished(addressPlayer AP);

void gameView(int option);

int Exit();

void endTurn(addressPlayer *AP, boolean isRolled);

void newGame();

void startNewGame();

void startConfig();

boolean isGameFinished(addressPlayer AP);

void Load();

#endif
