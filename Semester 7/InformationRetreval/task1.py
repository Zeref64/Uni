from nltk.book import *
import nltk.tokenize
import nltk 
import string

class WORD_STATS:        #? Creating an object in order to return two attributes at once
    wordCounter = 0
    percentageFound = 0

    def __init__(self, wordCounter, percentageFound):       #? Constructor
        self.wordCounter = wordCounter
        self.percentageFound = percentageFound

# -----------------------------------------------

def lexicalRichness(text):
        return (len(set(text)) / len(text))


def calculateWordAppearance(text, word):
    dictionary = len(text)
    wordCounter = text.count(word)
    percentageFound = 100 * wordCounter / dictionary
    L1 = WORD_STATS(wordCounter, percentageFound)
    return L1 #? Creating an object in order to return two attributes at once


def cleanText (tokenList, language):
    
    stopwords = nltk.corpus.stopwords.words(language)
    cleanedTokens = []
    for token in tokenList:
        if token not in string.punctuation and token not in stopwords:
            cleanedTokens.append(token)
    return cleanedTokens

# -----------------------------------------------

def main():
#! Task 1)
    #! Task 1α)
        #! i)
    print("\n================(i)================\n")
    # print("Λεξικός πλούτος του κειμένου 'Monty Python and the Holy Grail' είναι -> ", lexicalRichness(text6))
    #? Creating an object that contains the counter and the percentage 
    LAUNCELOT_Appearance = calculateWordAppearance(text6, "LAUNCELOT") #? Calculate the word appearance and the percentage for the word 'LAUNCELOT' in text6
    # print("Η λέξη: 'LAUNCELOT' βρέθηκε -> [",LAUNCELOT_Appearance.wordCounter, "]φορές\nμε συχνότητα: [",LAUNCELOT_Appearance.percentageFound,"] στο κείμενο 'Monty Python and the Holy Grail'")

        #! ii)
    print("\n================(ii)================\n")
    # print("Λεξικός πλούτος του κειμένου 'Chat Corpus' is -> ", lexicalRichness(text5))

    omg_Appearance = calculateWordAppearance(text5, "omg")  #? Same logic as above
    # print("Η λέξη: 'omg' βρέθηκε -> [", omg_Appearance.wordCounter, "]φορές\nμε συχνότητα: [",omg_Appearance.percentageFound,"] στο κείμενο: 'Chat Corpus'")

    OMG_Appearance = calculateWordAppearance(text5, "OMG")
    # print("Η λέξη: 'OMG' βρέθηκε -> [",OMG_Appearance.wordCounter, "] φορές\nμε συχνότητα: [",OMG_Appearance.percentageFound,"] στο κείμενο 'Chat Corpus'")

    lol_Appearance = calculateWordAppearance(text5, "lol")
    # print("Η λέξη: 'lol' βρέθηκε -> [",lol_Appearance.wordCounter, "] φορές\nμε συχνότητα: [",lol_Appearance.percentageFound,"] στο κείμενο 'Chat Corpus'")

    #! Task 1β)
    print("\n================(1β Α)================\n")
    
    wordList1 = ["ok","lmao","hi"]

    for word in wordList1:
        wordAppearance = calculateWordAppearance(text5, word)  
        # print("Η λέξη: ",word," βρέθηκε -> [",wordAppearance.wordCounter, "] φορές\nμε συχνότητα: [",wordAppearance.percentageFound,"] στο κείμενο 'Monty Python and the Holy Grail'")
    print("\n-----------------\n")
    wordList2 = ["GALAHAD","KNIGHT","FATHER"]
    wordAppearance2 = calculateWordAppearance(text6, word) 
    for word in wordList2:
        wordAppearance2 = calculateWordAppearance(text6, word)  
        # print("Η λέξη: ",word," βρέθηκε -> [",wordAppearance2.wordCounter, "] φορές\nμε συχνότητα: [",wordAppearance2.percentageFound,"] στο κείμενο 'Monty Python and the Holy Grail'")


    # print("""Το συμπέρασμα που βγάζω από το πρώτο πείραμα είναι πως εφόσον η λέξη 'LAUNCELOT' εμφανίζεται 76 φορές που σημαίνει πως στο κείμενο αναφέρθηκαν οι ιππότες τόσες φορές,
    # δηλαδή οι ιππότες αναφέρονται στο ~0.44% του συνόλου των λέξεων μέσα στο συγκεκριμένο κείμενο.""")

    # print("""Για τα επόμενα δύο πειράματα, παρατηρώ ότι η λέξη 'lol' αποτελεί το ~1,5% το οποίο είναι ένα σχετικά μεγάλο ποσοστό και αυτό
    # το στοιχείο οδηγεί την σκέψη μου σε ένα κείμενο που έχει σχέση με διαδυκτιακές συνομιλίες μεταξύ ανθρώπων 'chat' γιατί συνήθως τέτοιες λέξεις χρησιμοποιύνται εκεί
    # σαν αντίδραση η σχόλιο. Το ίδιο θα μπορούσαμε να πούμε και για τις λέξεις 'omg' & 'OMG' αλλά εκείνες εμφανίζονται πολύ λιγότερες φορές.""")

    # print("""Το ίδιο καταλαβαίνουμε και με τις λέξεις που πρόσθεσα. Η λέξη 'GALAHAD' που είναι το όνομα ενός ιππότη π.χ. εμφανίζεται και πάλι πολλές φορές """)
    # print("""Και στο κείμενο με τα chat βλέπουμε πάλι λέξεις που συνήθως χρησιμοποιούνται εκεί όπως το hi  """)
#! Task 2)
    print("\n================(2)================\n")
    fdist1 = FreqDist(text1)
    # print(fdist1.most_common(50))
    # fdist1.plot(50)
    # print ("""Το συμπέρασμα που μπορουμε να βγάλουμε απο το γραφήμα είναι ότι το συγκεκριμένο κείμενο έχει μάλλον κάποια σχέση με τις φάλαινες και τον ωκεανό 
    # διοτι παραηρούμε ότι η λέξη 'whale' εμφανίζεται 906 φορές. Επιπλέον, από τα κείμενα που έχουμε στην διάθεση μας, το κείμενο 1 είναι αυτό που έχει στον τίτλο του το όνομα 'Moby Dick' όπου αναφέρεται στο όνομα μιας φάλαινας.""")

#! Task 3)
    print("\n================(3)================\n")
    fdist6 = FreqDist(text6)
    #print(fdist6.most_common(50))
    # fdist6.plot(50) #? graph
    ARTHUR_Appearance = calculateWordAppearance(text6, "ARTHUR")
    # print("""Με βάση τα παραπάνω αποτελέσματα, η λέξη 'LAUNCELOT' εμφανίζεται στο κείμενο 'Monty Python and the Holy Grail' [""", LAUNCELOT_Appearance.wordCounter, """]φορές.
# Η λέξη 'ARTHUR' εμφανίζεται: [""", ARTHUR_Appearance.wordCounter ,"""] φορές, όπου είναι περισσότερες από την 'LAUNCELOT' """)

#! Task 4)
    print("\n================(4)================\n")
# print ("""Παρατηρώ ότι η παραπάνω κανονικοποίηση της πρότασης κειμένου ξεχωρίζει όλους τους χαρακτήρες σε μια πρόταση ύστερα τους μετατρέπει σε πεζούς.
# Η επίπτωση που μπορώ να σκεφτώ έίναι το γεγονός ότι εαν μετατρέψουμε όλες τις λέξεις σε πεζούς χαρακτήρες τότε δεν θα είναι εφικτή η 
# εύρεση λέξεων με κεφαλάια που σημαίνει πως θα μειωθεί ο λεκτικός πλούτος του κειμένου μας άρα τα δεδομένα μας δεν θα είναι ακριβείς διοτι
# οι λέξεις που υπάρχουν και σε κεφαλαία αλλα και σε πεζά θα αναγνωρίζονται μόνο ως πεζά.""")

    tokens9=sent9 
    normalized_sent9=[x.upper() for x in tokens9]
    # print (normalized_sent9)

#! Task 5)
    print("\n================(5α)================\n")
    mytext1 = "A wonderful serenity has taken possession of my entire soul like these sweet mornings of spring which I enjoy with my whole heart. I am alone and feel the charm of existence in this spot  which was created for the bliss of souls like mine. I am so happy  my dear friend  so absorbed in the exquisite sense of mere tranquil existence  that I neglect my talents. I should be incapable of drawing a single stroke at the present moment; and yet I feel that I never was a greater artist than now  When  while the lovely valley teems with vapour around me  and the meridian sun strikes the upper surface of the impenetrable foliage of my trees  and but a few stray gleams steal into the inner sanctuary  I throw myself down among the tall grass by the trickling stream; and  as I lie close to the earth  a thousand unknown plants are noticed by me: when I hear the buzz of the little world among the stalks  and grow familiar with the countless indescribable forms of the insects and flies  then I feel the presence of the Almighty  who formed us in his own image and the breath"
    mytokens1 = mytext1.split(" ")
    porter = nltk.PorterStemmer()
    stemmedToken = [porter.stem(word) for word in mytokens1]
    # print (stemmedToken)

    print("\n================(5β)================\n")
    mytext2 = "Στην αρχή υπήρχε μόνο το Χάος Πυκνό σκοτάδι σκέπαζε τα πάντα ώσπου από το χάος γεννήθηκε η Γη κι από τη Γη τα βουνά η θάλασσα και μετά ο Ουρανός με τον ήλιο το φεγγάρι και τ' αστέρια Τότε ο Ουρανός και η Γη ενώθηκαν και γέννησαν τους Τιτάνες Μα ο Ουρανός φοβόταν πως κάποιο από τα παιδιά του θα έπαιρνε το θρόνο του Γι αυτό τα έκλεισε όλα στα βάθη της Γης Όµως ο γιος του ο Κρόνος ο πιο δυνατός απ’ τους Τιτάνες τον νίκησε κι έγινε αυτός όλου του κόσµου αρχηγός Παντρεύτηκε τη Ρέα και γέννησαν τρεις θεές και τρεις θεούς: την Ήρα την Εστία και τη Δήµητρα τον Πλούτωνα τον Ποσειδώνα και το Δία Μα κι ο Κρόνος φοβόταν πως κάποιο απ τα παιδιά του θα έπαιρνε το θρόνο του Γι αυτό όταν γεννιόνταν τα κατάπινε Απελπισµένη η Ρέα πήγε και γέννησε το έκτο της παιδί το Δία σε µια σπηλιά σ’ ένα βουνό της Κρήτης Έκρυψε το παιδί εκεί Το φρόντιζαν οι Νύµφες κι έπινε το γάλα µιας κατσίκας της Αµάλθειας Στον Κρόνο έδωσε να καταπιεί µια φασκιωµένη πέτρα"
    mytokens2 = mytext2.split(" ")
    porter = nltk.PorterStemmer()
    stemmedToken2 = [porter.stem(word) for word in mytokens2]
    #print (stemmedToken2)

    print("\n================(5γ)================\n")
    wnl = nltk.WordNetLemmatizer()
    lemmatizedText1 = [wnl.lemmatize(t) for t in mytokens1]
    # print(lemmatizedText1)

    print("\n================(5δ)================\n")
    wnl = nltk.WordNetLemmatizer()
    lemmatizedText2 = [wnl.lemmatize(t) for t in mytokens2]
    # print(lemmatizedText2)
    # οταν είναι ελληνικα το stem βγάζει λάθη και το λεμ δεν παιζει  καν

    print("\n================(6α)================\n")
    mytoken3 = [] 
    for i in range(200):
        mytoken3.append(text2[i])

    mytoken3 = " ".join(text2[0:200])
    # print (mytoken3)

    splitList = mytoken3.split()
    # print (splitList)

    tokenizedList = nltk.word_tokenize(mytoken3)
    # print(tokenizedList)

    print("\n================(6β)================\n")
    mysentence64 = "I think I hear someone calling. What secrets does this painting hold?"
    splitList64 = mysentence64.split()
    # print(splitList64)

    tokenizedList64 = nltk.word_tokenize(mysentence64)
    # print(tokenizedList64)

    print("\n================(6γ)================\n")

    greeksentence64 = "Το αληθινό σου πρόσωπο, Τι είδους; Πρόσωπο είναι; Αναρωτιέμαι... Το πρόσωπο κάτω από τη μάσκα; Είναι αυτό, το αληθινό σου πρόσωπο;"
    splitGreekList64 = greeksentence64.split()
    # print(splitGreekList64)

    tokenizedGreekList64 = nltk.word_tokenize(greeksentence64)
    # print(tokenizedGreekList64)

    print("\n================(7)================\n")

    # print(string.punctuation)
    # cleaned_tokens=[]
    # for token in tokenizedList64:
        # if token not in string.punctuation:
            # cleaned_tokens.append(token)
    # print (tokenizedList64)
    # print (cleaned_tokens)

    englishStopwords = nltk.corpus.stopwords.words('english')
    # print(englishStopwords)
    # print ("Το Αγγλικό αλφάβητο αποτελείται από ->[", len(englishStopwords), "]λέξεις.")

    greekStopwords = nltk.corpus.stopwords.words('greek')
    # print(greekStopwords)
    # print ("Το Ελληνικό αλφάβητο αποτελείται από ->[", len(greekStopwords), "]λέξεις.")
    # 
    # print (cleanText(tokenizedList64, "english"))

    print("\n================(8)================\n")

    text2First200w = []
    for i in range(200):
        text2First200w.append(text2[i])

    print(len(text2First200w))
    print(len(cleanText(text2First200w, "english")))

    


    return 0

if __name__ == "__main__":
    main()