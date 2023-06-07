#ifndef PLAYER_H // Προστασία από errors του linker
#define PLAYER_H

#include <vector>

class Player {

    private: 
        char identifier;
        int foregroundColor;
        int backgroundColor;

        // Το first κρατάει τις γραμμές και το second κρατάει τις στήλες
        std::pair<int, int> currentPosition; 

    public:
        Player();
        Player(char symbol, int fgColor, int bgColor);  

        ~Player();

        char getIdentifier();
        std::pair<int, int> getCurrentPosition();

        void showPlayer();
        void initializePlayerPositions(int rowLimit, int columnLimit);
        
    };
#endif  