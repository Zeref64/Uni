#include <iostream>
#include <ncurses.h>
#include <time.h>
#include <random>
#include "player.h"
#include "LoukasP1.h"

#define X first
#define Y second

#define SPACE 32
#define ESC 27

LoukasP1::LoukasP1() :  Player('L', COLOR_GREEN, -1, 1) {} 

LoukasP1::~LoukasP1() {}

void LoukasP1::endScreen() {
    setlocale(LC_ALL, "");

    int row, column = 0;
    getmaxyx(stdscr, row, column);  //* Βρίσκει την τελευτάια γραμμή και στήλη 
    clear();
    mvprintw(1, 0, "Ο Λουκάς Μαλφόης άγγιξε πρώτος το μαγικό πετράδι και με την δύναμη του,\nτηλεμεταφέρθηκε επιτυχώς εκτός του λαβυρίνθου.");
    mvprintw(3, 0, "Όσο για τον Μπάμπη Ποτερίδη... Τα πράγματα δείχνουν άσχημα καθώς θα μείνει παγιδευμένος δίχως έξοδο ελπίζοντας να μην τον ξεχάσουν.");
    mvprintw(row - 1 , 0, "Το παιχνίδι ολοκληρώθηκε!! [Εισάγετε οποιοδήποτε χαρακτήρα για τερματισμό]");

    refresh();
    getch();
}

void LoukasP1::getGemLocation(std::pair <int, int> gemLocation_) {
    this->gemLocation.X = gemLocation_.X;
    this->gemLocation.Y = gemLocation_.Y;
}

bool LoukasP1::action() {

    int row, column = 0;
    getmaxyx(stdscr, row, column);
    
    char characterAbove, characterBelow, characterLeft, characterRight;         //* Αρχικοποιεί μεταβλητές που θα κρατούν τις γειτονικές θέσεις
    int input = getch();                                                           //? (Τρόπος σκέψης μου στο κάτω μέρος του αρχείου)
    
    switch (input) {
        case ESC:
            clear();
            mvprintw(0, 0, "%s", "Χαρακτήρας [ESC]!!\n Τερματισμός Παιχνιδιού κανένας Μάγος δεν βρήκε το πετράδι.");
            mvprintw(row - 1 , 0, "[Εισάγετε οποιοδήποτε χαρακτήρα για τερματισμό]");
            getch();
            endwin();
            exit(0);
            return false;

        case SPACE:
            break;

        case KEY_DOWN:
            move(currentPosition.X + 1, currentPosition.Y);        //* Μετακινέι τον κέρσορα στο απο κάτω σημείο με σκοπό να ελέγξει αν βρήκε το πετράδι
            characterBelow = inch();
            if (characterBelow == 'X')
                return true;
            else if (characterBelow == '.') {
                mvaddch(currentPosition.X, currentPosition.Y, '.');
                currentPosition.X++;
                showPlayer(this->colorID);
            }
            break;
        case KEY_LEFT:
            move(currentPosition.X, currentPosition.Y - 1);
            characterLeft = inch();
            if (characterLeft == 'X')
                return true;
            else if (characterLeft == '.') {
                mvaddch(currentPosition.X, currentPosition.Y, '.');
                currentPosition.Y--;
                showPlayer(this->colorID);
            }
            break;
        case KEY_RIGHT:
            move(currentPosition.X, currentPosition.Y + 1);
            characterRight = inch();
            if (characterRight == 'X')
                return true;
            else if (characterRight == '.') {
                mvaddch(currentPosition.X, currentPosition.Y, '.');
                currentPosition.Y++;
                showPlayer(this->colorID);
            }
            break;
        case KEY_UP:
            move(currentPosition.X - 1, currentPosition.Y);
            characterAbove = inch();
            if (characterAbove == 'X')
                return true;
            else if (characterAbove == '.') {
                mvaddch(currentPosition.X, currentPosition.Y, '.');
                currentPosition.X--;
                showPlayer(this->colorID);
            }
            break;
        default:
            break;
    }

    return false;
}

//? Τρόπος σκέψης: αρχικά έκανα τον έλεγχο με μια mvinch(currentPosition.X (first) + 1, currentPosition.Y (second)) == 'X' ωστόσο επειδή το αντικείμενο'Χ'
//? έχει χρώμα, δεν ήταν το ίδιο και δεν έμπαινε ποτέ στο if για να επιστρέψει true και το κατάλαβα μόλις άλλαξα το 'X' για ένα '*'. 
//? Έφαγα πολλές ώρες για να το βρώ και ξέρω πως δεν είναι τόσο πρακτικό αλλά δεν βρήκα κάτι άλλο και ήθελα να βάλω χρώμα και στο 'πετράδι'.