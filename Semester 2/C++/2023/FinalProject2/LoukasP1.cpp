#include <iostream>
#include <ncurses.h>
#include <time.h>
#include <random>
#include "player.h"
#include "LoukasP1.h"

LoukasP1::LoukasP1() : Player('L', COLOR_MAGENTA, -1) {} 

LoukasP1::~LoukasP1() {}

bool LoukasP1::action() {

    int input = getch();

    switch (input)
    {
    case KEY_UP:
        if (mvinch(this->getCurrentPosition().first - 1, this->getCurrentPosition().second) == '.') {

            mvaddch(this->getCurrentPosition().first, this->getCurrentPosition().second, '.');
            this->getCurrentPosition().first - 1;
            mvaddch(this->getCurrentPosition().first, this->getCurrentPosition().second, this->getIdentifier());
        }else if(mvinch(this->getCurrentPosition().first - 1, this->getCurrentPosition().second) == 'G') {
            return true;
        }
        break;

    case KEY_DOWN:
        if (mvinch(this->getCurrentPosition().first + 1, this->getCurrentPosition().second) == '.') {

            mvaddch(this->getCurrentPosition().first, this->getCurrentPosition().second, '.');
            this->getCurrentPosition().first + 1;
            mvaddch(this->getCurrentPosition().first, this->getCurrentPosition().second, this->getIdentifier());
        }else if(mvinch(this->getCurrentPosition().first + 1, this->getCurrentPosition().second) == 'G') {
            return true;
        }
        break;

    default:
        break;
    }
}