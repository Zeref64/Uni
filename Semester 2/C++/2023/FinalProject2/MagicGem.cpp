#include <iostream>
#include <ncurses.h>
#include <time.h>
#include <random>
#include "player.h"
#include "MagicGem.h"

#define X first
#define Y second

MagicGem::MagicGem() :  Player('X', COLOR_MAGENTA, -1, 3) {} 

MagicGem::~MagicGem() {}

void MagicGem::getGemLocation(std::pair <int, int> gemLocation_) {
    this->gemLocation.X = gemLocation_.X;
    this->gemLocation.Y = gemLocation_.Y;
}

void MagicGem::showGem (int colorID) {
    start_color();
    use_default_colors(); 

    init_pair(colorID, this->foregroundColor, this->backgroundColor);

    attron(COLOR_PAIR(colorID));
    mvaddch(this->currentPosition.X, this->currentPosition.Y, this->identifier);
    attroff(COLOR_PAIR(colorID));
}

//TODO Random
bool MagicGem::action() { return false; }

void MagicGem::endScreen() { /*το Πετράδι δεν γίνεται να νικήσει ποτέ*/ }