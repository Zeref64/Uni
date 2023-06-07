#include <iostream>
#include <locale>
#include <ncurses.h>
#include "game.h"


void ncursesSetup();

int main(int argc, char** argv) {

    std::string studentInfo("Αντικειμενοστρεφής Προγραμματισμός Τελική εργασία εξαμήνου Θεωρίας 2022-23 Κόυμανης Βασίλειος - 19390104");

    ncursesSetup();

    Game gameObject(argv[1]);
    gameObject.startScreen(studentInfo);
    clear();
    gameObject.initializeGame();

    refresh();
    getch();

    clear();
    gameObject.endScreen("haha");
    refresh();

    endwin(); 

    return 0;
}

void ncursesSetup() {
    //* Αρχικοποίηση του ncurses
    setlocale(LC_ALL, "el_GR.UTF-8");
    initscr();
    noecho(); // Απενεργοποίηση εμφάνισης συμβολοσειράς
    cbreak(); // Απενεργοποίηση line buffering
    curs_set(0); // Απενεργοποίηση κίνησης κατά την εισαγωγή χαρακτήρα
    intrflush(stdscr, FALSE); // Απενεργοποίηση κίνησης κατά την εισαγωγή πλήκτρου
    keypad(stdscr, TRUE); // Ενεργοποίηση πλήκτρων που είναι συνδεδεμένα στο πληκτρολόγιο
}

// clear && g++ -std=c++11 -Wall -Wextra main.cpp game.cpp player.cpp -o game -lncursesw && ./game level.txt
// clear && make clean && make && ./game level.txt
