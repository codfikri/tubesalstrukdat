#include "stack.h"
#include <stdio.h>
#include <stdlib.h>

void SCreateEmpty (Stack *S){
	Top(*S) = SNil;
}



boolean IsSEmpty (Stack S){
	return Top(S) == SNil;
}

boolean IsSFull (Stack S){
	return Top(S) == SMaxEl;
}


void Push (Stack * S, infostack X){
	if(Top(*S) == SNil){
		Top(*S) = 1;
	}
	else{
		Top(*S)++;
	}
	InfoTop(*S) = X;
}

void Pop (Stack * S, infostack* X){
	*X = InfoTop(*S);
	Top(*S)--;
}

void PushUndef(Stack * S){
    infostack X;
	X.Petak = -1;
	if(Top(*S) == SNil){
		Top(*S) = 1;
	}
	else{
		Top(*S)++;
	}
	InfoTop(*S) = X;
}

void Undo(Stack * S)
{
    infostack X;
    int temp;
    temp = (InfoTop(*S)).Petak;
    if (temp == -1 )
    {
        Pop(S, &X);
        temp = (InfoTop(*S)).Petak;
    }
    while (temp != -1)
    {
        Pop (S, &X);
        temp = (InfoTop(*S)).Petak;
    }
}