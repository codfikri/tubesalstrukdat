#ifndef GAME_H
#define GAME_H

// #include "../../src/player/player.h"
#include "../../src/skill/skill.h"
#include "../../src/stack/stack.h"
#include "../../src/teleporter/teleporter.h"
#include "../../src/inspect/inspect.h"
#include "../../src/map/map.h"
#include "../../src/load/load.h"
#include "../../src/save/save.h"

void showCommands();

int getNum(char *cmd);

void Turn(addressPlayer AP);

void delay(int detik);

void loading(int inputDetik);

void gameFinished(addressPlayer AP);

// void gameView(int option;

void endTurn(addressPlayer AP, boolean isRolled);

void newGame();

void startNewGame();

#endif
