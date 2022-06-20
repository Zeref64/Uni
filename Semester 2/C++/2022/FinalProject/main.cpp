#include <ncurses.h>
#include <clocale>
#include "game.hpp"

int main(int argc, char** argv) {
  // Αρχικοποίηση του ελληνικού locale
  setlocale(LC_ALL, "");

  // Αρχικοποίηση του ncurses
  initscr();
  noecho(); // Απενεργοποίηση εμφάνισης συμβολοσειράς
  cbreak(); // Απενεργοποίηση line buffering
  curs_set(0); // Απενεργοποίηση κίνησης κατά την εισαγωγή χαρακτήρα
  intrflush(stdscr, FALSE); // Απενεργοποίηση κίνησης κατά την εισαγωγή πλήκτρου
  keypad(stdscr, TRUE); // Ενεργοποίηση πλήκτρων που είναι συνδεδεμένα στο πληκτρολόγιο

  // Αρχικοποίηση παιχνιδιού
  // Δέχεται ως όρισμα το path του αρχείου που περίεχει τις οδηγίες
  // για την δημιουργία του χάρτη
  Game game(argv[1]);
  clear(); // Καθαρισμός οθόνης
  game.initGame(); // Αρχικοποίηση μεταβλητών παιχνιδιού
  refresh();
  game.run(); // Εκτέλεση παιχνιδιού

  endwin(); // Καταστροφή ncurses

  return 0;
}
