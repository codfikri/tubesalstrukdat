#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "skill.h"
#include "boolean.h"


// Masukin ke inisialisasi permainan -------------------------------------------
int main(){
    List skillPemain;
    address p;
    int n;


    srand(time(NULL));
    CreateEmpty(&skillPemain);
    for(int i = 0; i < 10; i++){
        getSkill(&skillPemain);
    }
    PrintForward(skillPemain);
    MenuSkill(&skillPemain);

}
