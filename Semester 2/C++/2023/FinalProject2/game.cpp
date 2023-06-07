#include <iostream>
#include <fstream>
#include <string.h>
#include <ncurses.h>
#include <locale.h>
#include "game.h"
#include "player.h"
#include "LoukasP1.h"

Game::Game() {}

// Αρχικοποίηση του file path
Game::Game(std::string filePath) : filePath(filePath) {

    playerVector.push_back( new Player('X', COLOR_MAGENTA, -1) ); // TODO Color is not working properly it overrides the value
    playerVector.push_back( new LoukasP1());

}

Game::~Game() {

    if (!playerVector.empty()) {
        delete playerVector[0];
        delete playerVector[1];
    }
    //TODO More delete
}


// Εμφανίζει ενα αλφαριθμητικό στην αρχή της οθόνης
void Game::startScreen(std::string inputString) {    
    setlocale(LC_ALL, "");

    int row, column = 0;
    getmaxyx(stdscr, row, column);  //* Βρίσκει την τελευτάια γραμμή και στήλη 
    mvprintw(0, 0,inputString.c_str());
    mvprintw(row - 1 , 0, "[Για την έναρξη του παιχνιδιού, εισάγετε οποιοδήποτε χαρακτήρα]");

    refresh();
    getch();
}

void Game::endScreen(std::string inputString) {
    setlocale(LC_ALL, "");

    int row, column = 0;
    getmaxyx(stdscr, row, column);  //* Βρίσκει την τελευτάια γραμμή και στήλη 
    mvprintw(0, 0, inputString.c_str());
    mvprintw(row - 1 , 0, "Το παιχνίδι ολοκληρώθηκε!! [Εισάγετε οποιοδήποτε χαρακτήρα για τερματισμό]");

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
    // for (Player* player: playerVector) {
    //     player->initializePlayerPositions(this->maxRow, this->maxColumn);
    // }
    playerVector[0]->initializePlayerPositions(this->maxRow, this->maxColumn);
    playerVector[1]->initializePlayerPositions(this->maxRow, this->maxColumn);
}

void Game::beginRound() {

}

// std::cout << this->maxRow << "\n"<< this->maxColumn << std::endl;