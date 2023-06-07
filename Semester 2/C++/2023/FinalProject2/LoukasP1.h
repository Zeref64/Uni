#ifndef LOUKAS_H // Προστασία από errors του linker
#define LOUKAS_H
#include "player.h"

class LoukasP1 : public Player {

    public:
        LoukasP1();

        ~LoukasP1();

        bool action();
};

#endif