#include <ncurses.h>
#include <fstream>
#include "game.hpp"
#include "mpampis.hpp"
#include "loukas.hpp"

// Κατασκευαστής παιχνιδιού
Game::Game(std::string file_path): file_path(file_path) {
  // Εμφάνιση μηνύματος καλωσορίσματος
  int row, col;
  std::string welcome_message = "Βασίλης Κούμανης - 19390104";
  getmaxyx(stdscr, row, col);
  mvprintw(row / 2, (col - welcome_message.length()) / 2, welcome_message.c_str());
  mvprintw(row - 1, 0, "Πατήστε οποιοσδήποτε κουμπί για να συνεχίσετε...", row, col);
  refresh();
  getch();

  // Αρχικοποίηση παιχτών
  players[0] = new Mpampis(); // Παίχτης, συμβολίζεται με M
  players[1] = new Loukas(); // Αντίπαλος του παίχτη, συμβολίζεται με L
  players[2] = new Player('G'); // Στόχος παιχνιδιού
}

// Καταστροφέας παιχνιδιού
Game::~Game() {
  for (auto &player : players)
    delete player;
}

// Φόρτωση του χάρτη από το αρχείο
void Game::loadLevel() {
  std::ifstream file(file_path); // Άνοιγμα αρχείου
  std::string line;
  max_row = 0;

  // Σάρωση αρχείου γραμμή - γραμμή
  while (std::getline(file, line)) {
    max_col = 0;

    // Σάρωση γραμμής χαρακτήρα - χαρακτήρα
    for (char c : line) {
      // Στις συγκεκριμένες συντεταγμένες
      // προσθέτει τον χαρακτήρα που διάβασε
      mvaddch(max_row, max_col, c);
      max_col++;
    }

    max_row++;
  }

  // Κλείσιμο αρχείου
  file.close();
  refresh();
}

// Αρχικοποίηση παιχνιδιού
void Game::initGame() {
  loadLevel();
  for (auto &player : players)
    player->generateLocations(max_row, max_col);

  // Ο αλγόριθμος του Λουκά για την κίνηση πρέπει να γνωρίζει που βρίσκετε ο στόχος
  players[1]->getGoalLocations(players[2]->getCurrentPoss());
}

// Εμφάνιση μηνύματος στο χάρτη όταν κάποιος παίχτης φτάσει στον στόχο
void showEndGameMessage(std::string message) {
  int row, col;
  getmaxyx(stdscr, row, col);
  clear();
  mvprintw(row / 2, (col - message.length()) / 2, message.c_str());
  mvprintw(row - 1, 0, "Πατήστε οποιοσδήποτε κουμπί για να τερματίσει το παιχνίδι...", row, col);
  getch();
  refresh();
  clear();
}

// Εκτέλεση παιχνιδιού
void Game::run() {
  int row, col;
  getmaxyx(stdscr, row, col);
  mvprintw(row - 1, 0, "Κάντε την κίνηση σας", row, col);

  // Αρχικοποίηση τυχαίου αριθμού κινήσεων
  time_t n_time;
  srand((unsigned) time(&n_time));
  int max_moves = rand() % 3 + 5;

  for (int current_move = 1;; current_move++) {
    if (players[0]->move()) {
      showEndGameMessage("Νίκησε ο Μπάμπης Ποτερίδης!");
      break;
    } else if (players[1]->move()) {
      showEndGameMessage("Νίκησε ο Λουκάς Μαλφόυ!");
      break;
    }

    // Κάθε πέντε γύρους, αλλάζει θέση ο στόχος και ενημερώνεται ο Λουκάς κατάλληλα
    if (current_move % max_moves == 0) {
      int *poss = players[2]->getCurrentPoss();
      mvaddch(poss[0], poss[1], '.');

      players[2]->generateLocations(max_row, max_col);
      players[1]->getGoalLocations(players[2]->getCurrentPoss());

      max_moves = rand() % 3 + 5;
      current_move = 1;
    }
  }
}
