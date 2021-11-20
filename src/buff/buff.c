#include "boolean.h"
#include "buff.h"

void CreateBuff(Buff *buff)
{
    for(int i=0; i< 4; i++){
        (*buff).info[i] = false;
    }
}

void setAfterTurn(Buff *buff)
{
    (*buff).info[1]= false;
    (*buff).info[2]= false;
    (*buff).info[3]= false;
}
