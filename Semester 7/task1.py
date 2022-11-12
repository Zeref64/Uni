from nltk.book import *

class WORD_STATS:        #? Creating an object in order to return two attributes
    wordCounter = 0
    percentageFound = 0

    def __init__(self, wordCounter, percentageFound):       #? Constructor
        self.wordCounter = wordCounter
        self.percentageFound = percentageFound


def calculateWordAppearance(text, word):
    dictionary = len(set(text))
    wordCounter = text.count(word)
    percentageFound = wordCounter / dictionary
    L1 = WORD_STATS(wordCounter, percentageFound)
    return L1 


def lexicalRichness(text):
        richness = (len(set(text)) / len(text))
        return richness


def main():
#! Task 1)
    #! Task 1α)
        #! i)
    print("\n================(i)================\n")
    print("Λεξικός πλούτος του κειμένου 'Monty Python and the Holy Grail' είναι -> ", lexicalRichness(text6))
    #? Creating an object that contains the counter and the percentage 
    LAUNCELOT_Appearance = calculateWordAppearance(text6, "LAUNCELOT") #? Calculate the word appearance and the percentage for the word 'LAUNCELOT' in text6
    print("Η λέξη: 'LAUNCELOT' βρέθηκε -> [",LAUNCELOT_Appearance.wordCounter, "]φορές\nμε συχνότητα: [",LAUNCELOT_Appearance.percentageFound,"] στο κείμενο 'Monty Python and the Holy Grail'")

        #! ii)
    print("\n================(ii)================\n")
    print("Λεξικός πλούτος του κειμένου 'Chat Corpus' is -> ", lexicalRichness(text5))

    omg_Appearance = calculateWordAppearance(text5, "omg")  #? Same logic as above
    print("Η λέξη: 'omg' βρέθηκε -> [", omg_Appearance.wordCounter, "]φορές\nμε συχνότητα: [",omg_Appearance.percentageFound,"] στο κείμενο: 'Monty Python and the Holy Grail'")

    OMG_Appearance = calculateWordAppearance(text5, "OMG")
    print("Η λέξη: 'OMG' βρέθηκε -> [",OMG_Appearance.wordCounter, "] φορές\nμε συχνότητα: [",OMG_Appearance.percentageFound,"] στο κείμενο 'Monty Python and the Holy Grail'")

    lol_Appearance = calculateWordAppearance(text5, "lol")
    print("Η λέξη: 'lol' βρέθηκε -> [",lol_Appearance.wordCounter, "] φορές\nμε συχνότητα: [",lol_Appearance.percentageFound,"] στο κείμενο 'Monty Python and the Holy Grail'")

    #! Task 1β)
    # print("\n================(1β Α)================\n")
    # wordsList = ["and", "", ""]
    # for word in wordsList:
        # word_Appearance = calculateWordAppearance(text6, "and")
    # and_Appearance = calculateWordAppearance(text6, "and")
    # print("The word: 'OMG' is found -> [",coder_Appearance.wordCounter, "] times\nat the frequency [",coder_Appearance.percentageFound,"] inside the book 'Monty Python and the Holy Grail'")

#! Task 2)
    print("\n================(2)================\n")
    print ("Δεν μπορεί να βγει συμπέρασμα για αυτό το αντικείμενο γιατί οι λέξεις (samples) που υπάρχουν είναι μη-αντιπροσωπευτικές.\nΟπότε δεν είναι εφικτό να κατανοήσουμε από ποιό κείμενο είναι.")

#! Task 3)

    print("\n================(3)================\n")
    fdist6 = text6
    fdist6.plot(50) #? graph
    ARTHUR_Appearance = calculateWordAppearance(text6, "ARTHUR")
    print("""Με βάση τα παραπάνω αποτελέσματα, η λέξη 'LAUNCELOT' εμφανίζεται στο κείμενο 'Monty Python and the Holy Grail' [""", LAUNCELOT_Appearance.wordCounter, """]φορές.\n
    Η λέξη 'ARTHUR' εμφανίζεται: [""", ARTHUR_Appearance.wordCounter ,"""] φορές, όπου είναι περισσότερες από την 'LAUNCELOT' """)



    return 0

if __name__ == "__main__":
    main()