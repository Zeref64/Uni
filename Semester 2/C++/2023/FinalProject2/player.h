#ifndef PLAYER_H // Προστασία από errors του linker
#define PLAYER_H

#include <vector>

class Player {

    protected: 
        char identifier;
        int foregroundColor;
        int backgroundColor;
        int colorID;

        // Το first κρατάει τις γραμμές και το second κρατάει τις στήλες
        std::pair<int, int> currentPosition; 

    public:
        Player();
        Player(char symbol, int fgColor, int bgColor, int color_id);  

        virtual ~Player();

        virtual bool action() = 0; 
        virtual void endScreen() = 0;
        virtual void getGemLocation(std::pair<int, int> gemLocation_) = 0;
        
        virtual void showGem(int colorID) {;}

        char getIdentifier() const;
        std::pair<int, int> getCurrentPosition() const;
        int getColorID() const;

        void showPlayer(int colorID);
        void initializePlayerPositions(int rowLimit, int columnLimit);
    };
#endif



