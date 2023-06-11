#include <iostream>
#include <fstream>
#include <string.h>
#include <ncurses.h>
#include <locale.h>

#include "game.h"
#include "player.h"
#include "LoukasP1.h"
#include "MpampisP2.h"
#include "MagicGem.h"

#define PLAYER_1 0
#define ENEMY 1
#define MAGIC_GEM 2

#define X first
#define Y second

Game::Game() {}

// Αρχικοποίηση του file path
Game::Game(std::string filePath) : filePath(filePath) {

    playerVector.push_back( new LoukasP1() );
    playerVector.push_back( new MpampisP2() );
    playerVector.push_back( new MagicGem() );
    
    
    // playerVector.push_back( new Player('D', COLOR_RED, -1) );
    //TODO More players 

}

Game::~Game() {

    if (!playerVector.empty()) {
        delete playerVector[0];
        delete playerVector[1];
        delete playerVector[2];
    }
}


// Εμφανίζει ενα αλφαριθμητικό στην αρχή της οθόνης
void Game::startScreen(std::string inputString) {    
    setlocale(LC_ALL, "");

    int row, column = 0;
    getmaxyx(stdscr, row, column);  //* Βρίσκει την τελευτάια γραμμή και στήλη 
    mvprintw(0, 0, "%s", inputString.c_str());
    mvprintw(row - 1 , 0, "[Για την έναρξη του παιχνιδιού, εισάγετε οποιοδήποτε χαρακτήρα]");

    refresh();
    getch();
}


void Game::initializeMap() {

    try {
        std::ifstream file(this->filePath);
        std::string line;
        this->maxRow = 0;

        //* Για κάθε γραμμή του αρχείου
        while (std::getline(file, line)) {
            this->maxColumn = 0;

            //* Για κάθε χαρακτήρα μιας γραμμής
            for (char character : line) {
                mvaddch(this->maxRow, this->maxColumn, character); //* Εμφανίζει τον χαρακτήρα
                this->maxColumn++;
            }
            this->maxRow++;
        }

        file.close();
        refresh();

    }catch(const std::exception& ex) {
        std::cerr << ex.what() << '\n';
    }
}


void Game::initializeGame() {

    initializeMap();
    initializePlayers();
}


void Game::initializePlayers() { 
    for (Player* player : playerVector){
        player->initializePlayerPositions(this->maxRow, this-> maxColumn);
        player->showPlayer(player->getColorID());
    }
    std::pair <int, int> gemLocation = playerVector[MAGIC_GEM]->getCurrentPosition();
    playerVector[ENEMY]->getGemLocation(gemLocation);
}

void Game::beginRound() {

    bool flag = true;
    mvprintw(maxRow + 3, 0, "Xειρισμός του Λουκά Μαλφόι:\n[ARROW_KEYS-> Μετακίνιση SPACE-> Στασημότητα, ESC-> Έξοδος Παιχνιδιού]");
    refresh();

    while (flag) {
        
        refresh();
        if (playerVector[PLAYER_1]->action()) {
            flag = false;
            playerVector[PLAYER_1]->endScreen();

        }else if (playerVector[ENEMY]->action()) {
            flag = false;
            playerVector[ENEMY]->endScreen();
        }

        refresh();
        // mvaddch(playerVector[MAGIC_GEM]->getCurrentPosition().X, playerVector[MAGIC_GEM]->getCurrentPosition().Y, '.');
        // playerVector[MAGIC_GEM]->initializePlayerPositions(this->maxRow, this-> maxColumn); 
        // playerVector[MAGIC_GEM]->showGem(MAGIC_GEM);
        // refresh();
    

    }}
// std::cout << this->maxRow << "\n"<< this->maxColumn << std::endl;