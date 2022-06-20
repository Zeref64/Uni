#ifndef PLAYER_HPP
#define PLAYER_HPP

#include <iostream>

class Player {
protected:
  int current_poss[2]; // 0 είναι η γραμμή, 1 είναι η στήλη
  char symbol; // Το σύμβολο του παίκτη

public:
  Player(char symbol);
  void generateLocations(int max_row, int max_col); // Αρχικοποίηση των θέσεων του παίκτη

  int* getCurrentPoss() { return current_poss; } // Επιστρέφει τις τρέχουσες θέσεις του παίκτη

  // Μέθοδοι που είναι εικονικές (δεν κάνουν κάτι) στην κλάση Player, αλλά υλοποιούνται στις υποκλάσεις
  virtual bool move() { return false; }
  virtual void getGoalLocations(int goal_poss[2]) { std::cout << ""; }
};

#endif