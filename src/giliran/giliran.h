#ifndef GILIRAN_H
#define GILIRAN_H

#include "../player/player.h"
#include "../stack/stack.h"
#include "../teleporter & inspect/teleporter.h"
#include "../teleporter & inspect/inspect.h"
#include "../map/map.h"

int mundur(int n, int m);

int maju(int n, int m);

int getNum(char *cmd);

void convertToCommand(int n);

#endif