#include <iostream>
#include <locale>
#include <ncurses.h>
#include "game.h"


void ncursesSetup();

int main(int argc, char** argv) {

    std::string studentInfo("Αντικειμενοστρεφής Προγραμματισμός Τελική εργασία εξαμήνου Θεωρίας 2022-23 Κόυμανης Βασίλειος - 19390104");

    std::string gameStory = "Στο Μαγικό Εκπαιδευτικό Ίδρυμα (Μ.Ε.Ι.) Δυτικής Αττικής, "
                                "στο οποίο φοιτούν μαθητευόμενοι μάγοι, κάθε χρόνο διοργανώνεται "
                                "ένας αγώνας μεταξύ των δύο καλύτερων μαθητών. "
                                "Με ευθύνη των καθηγητών του σχολείου, δημιουργείται ένας λαβύρινθος "
                                "Ο λαβύρινθος δεν έχει έξοδο και για να βγει κάποιος από αυτόν "
                                "πρέπει να βρει το μαγικό πετράδι τηλεμεταφοράς, "
                                "το οποίο τοποθετείται στον λαβύρινθο για το σκοπό αυτό. "
                                "Ο μαθητής ο οποίος θα αγγίξει πρώτος το πετράδι κερδίζει.\n"
                                "Φέτος, στον αγώνα συμμετέχουν:\n"
                                "Ο Μπάμπης Ποτερίδης (Μ) ο οποίος αγωνίζεται με την κόκκινη φορεσιά και"
                                "O Λουκάς Μαλφόης (L) ο οποίος αγωνίζεται με πράσινη φορεσιά.";

    ncursesSetup();

    Game gameObject(argv[1]);
    gameObject.startScreen(studentInfo, gameStory);
    clear();

    gameObject.initializeGame();
    refresh();

    clear();

    endwin(); 

    return 0;
}

void ncursesSetup() {
    //* Αρχικοποίηση του ncurses
    setlocale(LC_ALL, "el_GR.UTF-8");
    initscr();
    noecho();
    cbreak();
    curs_set(0);
    intrflush(stdscr, FALSE);
    keypad(stdscr, TRUE);
}
