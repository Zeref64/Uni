#include <ncurses.h>
#include <random>
#include <time.h>
#include "player.hpp"

Player::Player(char symbol) {
  this->symbol = symbol;
}

// Αρχικοποίηση θέσεων του στόχου
void Player::generateLocations(int max_row, int max_col) {
  // Αρχικοποίηση τυχαίου αριθμού
  time_t n_time;
  srand((unsigned) time(&n_time));

  // Επανάληψη μέχρι να βρεθεί έγκυρη θέση στον χάρτη
  for (;;) {
    // Επιλογή τυχαίας θέσης
    int row = rand() % max_row;
    int col = rand() % max_col;

    if (mvinch(row, col) == '.') {
      current_poss[0] = row;
      current_poss[1] = col;
      mvaddch(row, col, this->symbol);
      break;
    }
  }
}