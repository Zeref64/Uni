#ifndef MPAMPIS_H // Προστασία από errors του linker
#define MPAMPIS_H
#include "player.h"

class MpampisP2 : public Player {

    private:
        std::pair <int, int> gemLocation;
        
    public:
        MpampisP2();

        virtual ~MpampisP2();

        bool action() override;
        void endScreen() override;

        void getGemLocation(std::pair<int, int> gemLocation_) override;
};

#endif