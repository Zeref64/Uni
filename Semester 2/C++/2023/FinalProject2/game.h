#ifndef GAME_H // Προστασία από errors του linker
#define GAME_H

#include <string>
#include <vector>
#include "player.h"

class Game {

    private: 
        std::string filePath;
        std::vector<Player*> playerVector;
        int maxRow;
        int maxColumn;

    public: 
        Game();
        Game(std::string filePath);

        ~Game();


        // Μέθοδοι
        void startScreen(std::string str);
        

        void initializeMap();
        void initializeGame();
        void initializePlayers();
        void beginRound();
};

#endif