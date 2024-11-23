#include <iostream>
#include <fstream>
#include <ncurses.h>
#include <ctime>

using namespace std;
class Player
{
private:
    char logo;
public:
    Player();
    ~Player();
};

Player::Player()
{
}

Player::~Player(){}



int main(int argc, char const *argv[])
{
    //* Αρχικοποίηση του ncurses
    setlocale(LC_ALL, "el_GR.UTF-8");
    initscr();
    noecho(); // Απενεργοποίηση εμφάνισης συμβολοσειράς
    cbreak(); // Απενεργοποίηση line buffering
    curs_set(0); // Απενεργοποίηση κίνησης κατά την εισαγωγή χαρακτήρα
    intrflush(stdscr, FALSE); // Απενεργοποίηση κίνησης κατά την εισαγωγή πλήκτρου
    keypad(stdscr, TRUE); // Ενεργοποίηση πλήκτρων που είναι συνδεδεμένα στο πληκτρολόγιο

    ifstream file("level3.txt");
    string line;
    int row,column;
    row = 0;
    while (getline(file, line)) {
        column = 0;
        for (char c: line) {     
            mvaddch(row, column, c);
            column++;
        }
        row++;
    }
    refresh();


    std::srand(std::time(NULL));
    int currentX, currentY;

    int maxAttempts = row * column;
    int attempts = 0;

    while (attempts < maxAttempts) {
        currentX = std::rand() % row;
        currentY = std::rand() % column;

        if (mvinch(currentX, currentY) == '.') {

            mvaddch(currentX, currentY, 'P');
            break;
        }
        attempts++;
    }

    refresh();
    getch();
    endwin();
    return 0;
}







//?● Θα διαβάζει από αρχείο και θα τυπώνει στην οθόνη “λαβύρινθο” ο οποίος θα
//? πληροί τις προδιαγραφές της τελικής εργασίας (project) του εργαστηρίου.

//? ● Θα τοποθετεί σε τυχαίο ελεύθερο χώρο ένα ανθρωπάκι και θα το μετακινεί
//? μέχρι να περάσει από όλα τα σημεία του χάρτη που δεν είναι τοίχοι. Η κίνηση
//? θα γίνεται σύμφωνα με τους κανόνες της τελικής εργασίας (project) του
//? εργαστηρίου.
//? Ο χειρισμός της οθόνης θα πραγματοποιείται, επίσης, σύμφωνα με τους κανόνες της
//? τελικής εργασίας του εργαστηρίου. Ο χειρισμός λαθών κατά το διάβασμα του αρχείου
//? θα πραγματοποιείται με την χρήση εξαιρέσεων.