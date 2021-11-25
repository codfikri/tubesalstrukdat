#ifndef GAME_H
#define GAME_H

#include "../src/player/player.h"
#include "../src/stack/stack.h"
#include "../src/teleporter & inspect/teleporter.h"
#include "../src/teleporter & inspect/inspect.h"
#include "../src/map/map.h"

int mundur(int n, int m);

int maju(int n, int m);

int getNum(char *cmd);

void convertToCommand(int n);

#endif