#ifndef GEM_H 
#define GEM_H

#include "player.h"

class MagicGem : public Player{

    private:
        std::pair <int, int> gemLocation;

    public:
        MagicGem();

        virtual ~MagicGem();

        bool action() override;
        void endScreen() override;
        void getGemLocation(std::pair <int, int> gemLocation_) override;

        void showGem (int colorID) override;
};

#endif