#include <ncurses.h>
#include <random>
#include <ctime>
#include "player.h"

Player::Player() {}
Player::Player(char symbol, int fgColor, int bgColor) : identifier(symbol), foregroundColor(fgColor), backgroundColor(bgColor) {}

Player::~Player() {}

char Player::getIdentifier() {return this->identifier;}
std::pair<int, int> Player::getCurrentPosition() {return this->currentPosition;}


void Player::showPlayer() {

    init_pair(1, this->foregroundColor, this->backgroundColor);

    attron(COLOR_PAIR(1));
    mvaddch(this->currentPosition.first, this->currentPosition.second, this->identifier);
    attroff(COLOR_PAIR(1));
} 

//* Αρχοικοποιεί τους παίχτες σε τυχαία θέση εντός ορίων του χάρτη
void Player::initializePlayerPositions(int rowLimit, int columnLimit) {

    std::srand(std::time(NULL));
    int currentX, currentY;

    int maxAttempts = rowLimit * columnLimit;
    int attempts = 0;

    while (attempts < maxAttempts) {
        currentX = std::rand() % rowLimit;
        currentY = std::rand() % columnLimit;

        if (mvinch(currentX, currentY) == '.') {

            this->currentPosition = std::make_pair(currentX, currentY);

            start_color();
            use_default_colors(); 
            showPlayer();
            break;
        }
        attempts++;
    }

}