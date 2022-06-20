#ifndef GAME_HPP
#define GAME_HPP

#include <string>
#include "player.hpp"

// Κλάση παιχνιδιού
class Game {
private:
  Player* players[3]; // Πίνακας παιχνιδιού για τους παίχτες
  std::string file_path; // Το path του αρχείου που περιέχει το χάρτη
  int max_row, max_col; // Τα όρια που έχουν οριστεί από τον χάρτη

  // Φόρτωση πίστας
  void loadLevel();

public:
  // Κατασκευαστής παιχνιδιού
  Game(std::string file_path);

  // Καταστροφέας παιχνιδιού
  ~Game();

  // Μέθοδοι παιχνιδιού
  // Αρχικοποίηση μεταβλητών παιχνιδιού
  void initGame();
  // Εκτέλεση παιχνιδιού
  void run();
};

#endif
