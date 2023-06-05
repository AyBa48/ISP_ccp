#include "SchoolYard.h"

void removePupilsofYard(SchoolYard &s, int num){
    for(int i = 0; i < num; i++){
        s.removePupil();
    }
}

void addPupilstoYard(SchoolYard *s, int num){
    for(int i = 0; i < num; i++){
        s->addPupil();
    }
}
