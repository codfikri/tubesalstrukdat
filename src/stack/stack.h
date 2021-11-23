#ifndef stack_H
#define stack_H

#include "../boolean.h"
#include <stdlib.h>
#include <stdio.h>
#include "../player/player.h"
#include "../skill/skill.h"

#define SNil 0
#define SMaxEl 200

typedef Player infostack;

typedef int Saddress;   

typedef struct {
  infostack T[SMaxEl+1];
  Saddress TOP;
} Stack;

#define Top(S) (S).TOP
#define InfoTop(S) (S).T[(S).TOP]
#define NextStack(S) (S).T[(S).TOP-1]

void SCreateEmpty (Stack *S);

boolean IsSEmpty (Stack S);

boolean IsSFull (Stack S);

void Push (Stack * S, infostack X);

void Pop (Stack * S, infostack* X);

void PushUndef(Stack * S);

void Undo(Stack * S);

void UndoPlayerList(Stack S, PlayerList *PL, int l);

#endif