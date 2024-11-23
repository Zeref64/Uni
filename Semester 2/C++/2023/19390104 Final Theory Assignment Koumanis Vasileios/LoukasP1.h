#ifndef LOUKAS_H // Προστασία από errors του linker
#define LOUKAS_H
#include "player.h"

class LoukasP1 : public Player {

    private:
        std::pair <int, int> gemLocation;

    public:
        LoukasP1();

        virtual ~LoukasP1();

        bool action() override;
        void endScreen() override;
        void getGemLocation( std::pair<int, int> gemLocation_) override;
};

#endif