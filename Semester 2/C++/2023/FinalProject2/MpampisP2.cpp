#include <iostream>
#include <ncurses.h>
#include <time.h>
#include <random>
#include "player.h"
#include "MagicGem.h"
#include "MpampisP2.h"

#define X first
#define Y second

MpampisP2::MpampisP2() :  Player('M', COLOR_RED, -1, 2) {} 

MpampisP2::~MpampisP2() {}

void MpampisP2::getGemLocation(std::pair <int, int> gemLocation_) {
    this->gemLocation.X = gemLocation_.X;
    this->gemLocation.Y = gemLocation_.Y;
}

//TODO ελεγχος ορθότητας
bool MpampisP2::action() {

    //? Αποθηκευέι τους γειτονικούς χαρακτήρες από τις 4 κατευθύνσεις για τον ίδιο λόγο με τον Λούκα 'το Χ έχει χρώμα'  
    char characterAbove, characterBelow, characterLeft, characterRight;

    move(currentPosition.X - 1, currentPosition.Y); //* Μετακινεί τον κέρσορα Πάνω
    characterAbove = inch();

    move(currentPosition.X + 1, currentPosition.Y); //* Κάτω
    characterBelow = inch();

    move(currentPosition.X, currentPosition.Y - 1); //* Αριστερά
    characterLeft = inch();

    move(currentPosition.X, currentPosition.Y + 1); //* και Δεξιά 
    characterRight = inch();

    //? Επεξεργάσια στο που επιτρέπεται να κινηθεί
    bool canMoveUp = (characterAbove == '.' || characterAbove == 'X' || characterAbove != '*');
    bool canMoveDown = (characterBelow == '.' || characterBelow == 'X' || characterBelow != '*');
    bool canMoveLeft = (characterLeft == '.' || characterLeft == 'X' || characterLeft != '*');
    bool canMoveRight = (characterRight == '.' || characterRight == 'X' || characterRight != '*');

    // Ελέγχει για το άν μπορεί να μετακινηθεί προς κάποια κατεύθυνση, αν όχι επιστρέφει false
    if (!(canMoveUp || canMoveDown || canMoveLeft || canMoveRight)) {
        return false; 
    }

    //? Μετακίνιση με βάση το που βρίσκεται το μαγικό πετράδι
    if (currentPosition.X < gemLocation.X && canMoveDown) {
        //* Αν το πετράδι είναι από κάτω:
        if (characterBelow == 'X') {
            gemLocation.X = currentPosition.X + 1;
            gemLocation.Y = currentPosition.Y;
            return true;
        } else if (characterLeft != '*' || 'L') {
            mvaddch(currentPosition.X, currentPosition.Y, '.');
            currentPosition.X++;
            showPlayer(this->colorID);
        }

    } else if (currentPosition.X > gemLocation.X && canMoveUp) {
        //* Αν το πετράδι είναι από πάνω:
        if (characterAbove == 'X') {
            gemLocation.X = currentPosition.X - 1;
            gemLocation.Y = currentPosition.Y;
            return true;
        } else if (characterLeft != '*' || 'L') {
            mvaddch(currentPosition.X, currentPosition.Y, '.');
            currentPosition.X--;
            showPlayer(this->colorID);
        }

    } else if (currentPosition.Y < gemLocation.Y && canMoveRight) {
        //* Αν το πετράδι είναι πιο δεξιά:
        if (characterRight == 'X') {
            gemLocation.X = currentPosition.X;
            gemLocation.Y = currentPosition.Y + 1;
            return true;
        } else if (characterLeft != '*' || 'L') {
            mvaddch(currentPosition.X, currentPosition.Y, '.');
            currentPosition.Y++;
            showPlayer(this->colorID);
        }

    } else if (currentPosition.Y > gemLocation.Y && canMoveLeft) {
        //* Αν το πετράδι είναι πιο αριστερά:
        if (characterLeft == 'X') {
            gemLocation.X = currentPosition.X;
            gemLocation.Y = currentPosition.Y - 1;
            return true;
        } else if (characterLeft != '*' || 'L') {
            mvaddch(currentPosition.X, currentPosition.Y, '.');
            currentPosition.Y--;
            showPlayer(this->colorID);
        }
        
    }
    return false; 
}


void MpampisP2::endScreen() {
    setlocale(LC_ALL, "");

    int row, column = 0;
    getmaxyx(stdscr, row, column);  //* Βρίσκει την τελευτάια γραμμή και στήλη 
    clear();
    mvprintw(10, 50, "Ο Μπάμπης Ποττερίδης βρήκε το μαγικό πετράδι");
    mvprintw(row - 1 , 0, "Το παιχνίδι ολοκληρώθηκε!! [Εισάγετε οποιοδήποτε χαρακτήρα για τερματισμό]");

    refresh();
    getch();
}