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
        void endScreen(std::string str);

        void initializeMap();
        void initializeGame();
        void beginRound();
};