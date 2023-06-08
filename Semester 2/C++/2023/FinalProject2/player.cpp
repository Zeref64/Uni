#include <ncurses.h>
#include <random>
#include <ctime>
#include "player.h"

Player::Player() {}
Player::Player(char symbol, int fgColor, int bgColor) : identifier(symbol), foregroundColor(fgColor), backgroundColor(bgColor) {}

Player::~Player() {}

char Player::getIdentifier() {return this->identifier;}
std::pair<int, int> Player::getCurrentPosition() {return this->currentPosition;}


void Player::showPlayer(int colorID) {


    start_color();
    use_default_colors(); 

    init_pair(colorID, this->foregroundColor, this->backgroundColor);

    attron(COLOR_PAIR(colorID));
    mvaddch(this->currentPosition.first, this->currentPosition.second, this->identifier);
    attroff(COLOR_PAIR(colorID));
    
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
            break;
        }
        attempts++;
    }

}