#include <ncurses.h>
#include <random>
#include <time.h>
#include "loukas.hpp"

Loukas::Loukas() : Player('L') {
}

// Μέθοδος κίνησης του Λουκά που κληρονομεί από τον Player
// Επιστρέφει true εάν βρει τον στόχο, διαφορετικά επιστρέφει false
bool Loukas::move() {
  // Εάν βρίσκεται σε διαφορετικό ύψος από τον στόχο, τότε κινείται ανάλογα
  if (current_poss[0] > goal_poss[0]) {
    if (mvinch(current_poss[0] - 1, current_poss[1]) == '.') {
      mvaddch(current_poss[0], current_poss[1], '.');
      current_poss[0]--;
      mvaddch(current_poss[0], current_poss[1], this->symbol);
      return false;
    } else if (mvinch(current_poss[0] - 1, current_poss[1]) == 'G') {
      return true;
    }
  } else if (current_poss[0] < goal_poss[0]) {
    if (mvinch(current_poss[0] + 1, current_poss[1]) == '.') {
      mvaddch(current_poss[0], current_poss[1], '.');
      current_poss[0]++;
      mvaddch(current_poss[0], current_poss[1], this->symbol);
      return false;
    } else if (mvinch(current_poss[0] + 1, current_poss[1]) == 'G') {
      return true;
    }
  }

  if (current_poss[1] > goal_poss[1]) {
    if (mvinch(current_poss[0], current_poss[1] - 1) == '.') {
      mvaddch(current_poss[0], current_poss[1], '.');
      current_poss[1]--;
      mvaddch(current_poss[0], current_poss[1], this->symbol);
      return false;
    } else if (mvinch(current_poss[0], current_poss[1] - 1) == 'G') {
      return true;
    }
  } else if (current_poss[1] < goal_poss[1]) {
    if (mvinch(current_poss[0], current_poss[1] + 1) == '.') {
      mvaddch(current_poss[0], current_poss[1], '.');
      current_poss[1]++;
      mvaddch(current_poss[0], current_poss[1], this->symbol);
      return false;
    } else if (mvinch(current_poss[0], current_poss[1] + 1) == 'G') {
      return true;
    }
  }

  return false;
}

void Loukas::getGoalLocations(int goal_poss[2]) {
  this->goal_poss[0] = goal_poss[0];
  this->goal_poss[1] = goal_poss[1];
}
