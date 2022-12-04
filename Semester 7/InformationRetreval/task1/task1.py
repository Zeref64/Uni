from nltk.book import *
import nltk.tokenize
import string
import gc

# -----------------------------------------------

class WORD_STATS:        #? Creating an object in order to return two attributes at once
    wordCounter = 0
    percentageFound = 0

    def __init__(self, wordCounter, percentageFound):       #? Constructor
        self.wordCounter = wordCounter
        self.percentageFound = percentageFound

# -----------------------------------------------

def lexicalRichness(text):
        return (len(set(text)) / len(text))

# -----------------------------------------------

def calculateWordAppearance(text, word):
    dictionary = len(text)
    wordCounter = text.count(word)
    percentageFound = 100 * wordCounter / dictionary
    L1 = WORD_STATS(wordCounter, percentageFound)
    return L1 #? Creating an object in order to return two attributes at once

# -----------------------------------------------

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
    print("\n================(i)================\n")
    print("Λεξικός πλούτος του κειμένου 'Monty Python and the Holy Grail' είναι -> ", lexicalRichness(text6))

    #? Creating an object that contains the counter and the percentage 
    LAUNCELOT_Appearance = calculateWordAppearance(text6, "LAUNCELOT") #? Calculate the word appearance and the percentage for the word 'LAUNCELOT' in text6
    print("Η λέξη: 'LAUNCELOT' βρέθηκε -> [",LAUNCELOT_Appearance.wordCounter, "]φορές\nμε συχνότητα: [",LAUNCELOT_Appearance.percentageFound,"] στο κείμενο 'Monty Python and the Holy Grail'")

    print("\n================(ii)================\n")
    print("Λεξικός πλούτος του κειμένου 'Chat Corpus' is -> ", lexicalRichness(text5))

    omg_Appearance = calculateWordAppearance(text5, "omg")  #? Same logic as above
    print("Η λέξη: 'omg' βρέθηκε -> [", omg_Appearance.wordCounter, "]φορές\nμε συχνότητα: [",omg_Appearance.percentageFound,"] στο κείμενο: 'Chat Corpus'")

    OMG_Appearance = calculateWordAppearance(text5, "OMG")
    print("Η λέξη: 'OMG' βρέθηκε -> [",OMG_Appearance.wordCounter, "] φορές\nμε συχνότητα: [",OMG_Appearance.percentageFound,"] στο κείμενο 'Chat Corpus'")

    lol_Appearance = calculateWordAppearance(text5, "lol")
    print("Η λέξη: 'lol' βρέθηκε -> [",lol_Appearance.wordCounter, "] φορές\nμε συχνότητα: [",lol_Appearance.percentageFound,"] στο κείμενο 'Chat Corpus'")

    print("\n================(1β Α)================\n")
    
    wordList1 = ["ok","lmao","hi"]

    for word in wordList1:
        wordAppearance = calculateWordAppearance(text5, word)  
        print("Η λέξη: ",word," βρέθηκε -> [",wordAppearance.wordCounter, "] φορές\nμε συχνότητα: [",wordAppearance.percentageFound,"] στο κείμενο 'Chat Corpus'")

    print("\n-----------------\n")
    wordList2 = ["GALAHAD","KNIGHT","FATHER"]
    wordAppearance2 = calculateWordAppearance(text6, word) 
    for word in wordList2:
        wordAppearance2 = calculateWordAppearance(text6, word)  
        print("Η λέξη: ",word," βρέθηκε -> [",wordAppearance2.wordCounter, "] φορές\nμε συχνότητα: [",wordAppearance2.percentageFound,"] στο κείμενο 'Monty Python and the Holy Grail'")

#! Task 2)
    print("\n================(2)================\n")
    
    fdist1 = FreqDist(text1)
    print(fdist1.most_common(50))
    fdist1.plot(50)

#! Task 3)
    print("\n================(3)================\n")
    
    fdist6 = FreqDist(text6)
    print(fdist6.most_common(50))
    fdist6.plot(50) #? graph


    ARTHUR_Appearance = calculateWordAppearance(text6, "ARTHUR")
    print("""Με βάση τα παραπάνω αποτελέσματα, η λέξη 'LAUNCELOT' εμφανίζεται στο κείμενο 'Monty Python and the Holy Grail' [""", LAUNCELOT_Appearance.wordCounter, """]φορές,
# Η λέξη 'ARTHUR' εμφανίζεται: [""", ARTHUR_Appearance.wordCounter ,"""] φορές, όπου είναι περισσότερες από την 'LAUNCELOT' """)

#! Task 4)
    print("\n================(4)================\n")

    tokens9=sent9 
    normalized_sent9=[x.lower() for x in tokens9]
    print (normalized_sent9)

#! Task 5)
    # print("\n================(5α)================\n")
    englishText1 = "A wonderful Serenity has taken possession of my entire Soul like these sweet mornings of spring which I enjoy with my whole heart. I am alone and feel the charm of existence in this spot  which was created for the bliss of souls like mine. I am so happy  my dear friend  so absorbed in the exquisite sense of mere tranquil existence  that I neglect my talents. I should be incapable of drawing a single stroke at the present moment; and yet I feel that I never was a greater artist than now  When  while the lovely valley teems with vapour around me  and the meridian sun strikes the upper surface of the impenetrable foliage of my trees  and but a few stray gleams steal into the inner sanctuary  I throw myself down among the tall grass by the trickling stream; and  as I lie close to the earth  a thousand unknown plants are noticed by me: when I hear the buzz of the little world among the stalks  and grow familiar with the countless indescribable forms of the insects and flies  then I feel the presence of the Almighty  who formed us in his own image and the breath"
    englishText1_split = englishText1.split(" ")
    print ("\n[English text]:\n", englishText1)
    
    normalizedEnglishText1=[x.lower() for x in englishText1_split]
    print ("\n[Normalized Text]:\n", normalizedEnglishText1,"\n")

    porter = nltk.PorterStemmer()
    stemmedEnglishText2 = [porter.stem(word) for word in englishText1_split]
    print ("\n[Stemmed Text]:\n",stemmedEnglishText2,"\n")

    wnl = nltk.WordNetLemmatizer()
    lemmatizedEnglishText3 = [wnl.lemmatize(t) for t in englishText1_split]
    print("\n[Lemmatized Text]:\n",lemmatizedEnglishText3,"\n")
    

    print("\n================(5β)================\n")
    greekText1 = "Στην αρχή υπήρχε μόνο το Χάος Πυκνό σκοτάδι σκέπαζε τα πάντα ώσπου από το χάος γεννήθηκε η Γη κι από τη Γη τα βουνά η θάλασσα και μετά ο Ουρανός με τον ήλιο το φεγγάρι και τ' αστέρια Τότε ο Ουρανός και η Γη ενώθηκαν και γέννησαν τους Τιτάνες Μα ο Ουρανός φοβόταν πως κάποιο από τα παιδιά του θα έπαιρνε το θρόνο του Γι αυτό τα έκλεισε όλα στα βάθη της Γης Όµως ο γιος του ο Κρόνος ο πιο δυνατός απ’ τους Τιτάνες τον νίκησε κι έγινε αυτός όλου του κόσµου αρχηγός Παντρεύτηκε τη Ρέα και γέννησαν τρεις θεές και τρεις θεούς: την Ήρα την Εστία και τη Δήµητρα τον Πλούτωνα τον Ποσειδώνα και το Δία Μα κι ο Κρόνος φοβόταν πως κάποιο απ τα παιδιά του θα έπαιρνε το θρόνο του Γι αυτό όταν γεννιόνταν τα κατάπινε Απελπισµένη η Ρέα πήγε και γέννησε το έκτο της παιδί το Δία σε µια σπηλιά σ’ ένα βουνό της Κρήτης Έκρυψε το παιδί εκεί Το φρόντιζαν οι Νύµφες κι έπινε το γάλα µιας κατσίκας της Αµάλθειας Στον Κρόνο έδωσε να καταπιεί µια φασκιωµένη πέτρα"
    greekText1_split = greekText1.split(" ")
    print ("\n[Greek Text]:\n", greekText1)
    
    normalizedGreekText1=[x.lower() for x in greekText1_split]
    print ("\n[Normalized Text]:\n", normalizedGreekText1,"\n")

    porter = nltk.PorterStemmer()
    stemmedGreekText2 = [porter.stem(word) for word in greekText1_split]
    print ("\n[Stemmed Text]:\n",stemmedGreekText2,"\n")

    wnl = nltk.WordNetLemmatizer()
    lemmatizedGreekText3 = [wnl.lemmatize(t) for t in greekText1_split]
    print("\n[Lemmatized Text]:\n",lemmatizedGreekText3,"\n")

    print("\n================(6α)================\n")
#! Task 6)
    text2_First200Words = text2[:200]
    
    text2_First200WordsJoined = " ".join(text2[0:200])
    print("\n[First 200 words of text2]\n",text2_First200WordsJoined)
    
    text2_First200Words_split = text2_First200WordsJoined.split()
    print ("\n[First 200 words of text2 with split()]\n",text2_First200Words_split)

    text2_First200Words_tokenized = nltk.word_tokenize(text2_First200WordsJoined)
    print("\n[First 200 words of text2 with word_tokenize()]\n",text2_First200Words_tokenized)

    print("\n================(6β)================\n")
    
    myEnglishSentence = "..I think I hear someone calling. What secrets does this painting hold?"
    myEnglishSentence_split = myEnglishSentence.split()
    print("\n[English Sentence with split()]\n", myEnglishSentence_split)

    myEnglishSentence_tokenized = nltk.word_tokenize(myEnglishSentence)
    print("\n[English Sentence with tokenize()]\n", myEnglishSentence_tokenized)

    print("\n================(6γ)================\n")

    myGreekSentence = "Το αληθινό σου πρόσωπο, Τι είδους; Πρόσωπο είναι; Αναρωτιέμαι... Το πρόσωπο κάτω από τη μάσκα; Είναι αυτό, το αληθινό σου πρόσωπο;"
    myGreekSentence_split = myGreekSentence.split()
    print("\n[Greek Sentence with split()]\n", myGreekSentence_split)

    myGreekSentence_tokenized = nltk.word_tokenize(myGreekSentence)
    print("\n[Greek Sentence with tokenize()]\n", myGreekSentence_tokenized)

#! Task 7)
    print("\n================(7)================\n")

    englishStopwords = nltk.corpus.stopwords.words('english')
    print(englishStopwords)
    print ("Το Αγγλικό αλφάβητο αποτελείται από ->[", len(englishStopwords), "]λέξεις.")

    greekStopwords = nltk.corpus.stopwords.words('greek')
    print(greekStopwords)
    print ("Το Ελληνικό αλφάβητο αποτελείται από ->[", len(greekStopwords), "]λέξεις.")
    
    print(myEnglishSentence_tokenized)
    print (cleanText(myEnglishSentence_tokenized, "english"))

#! Task 8)
    print("\n================(8)================\n")

    print("[First 200 words of:", text2, "]\n")
    
    print("Word Count: ", len(text2_First200Words))
    print ("Individual Word count: ",len(set(text2_First200Words)))
    print ("Richness: ",lexicalRichness(text2_First200Words), "\n")
    
    
    cleanedText2_First200Words = cleanText(text2_First200Words, "english") #? Already tokenized text
    print("Cleaned Word Count: ", len(cleanedText2_First200Words))
    print ("Cleaned Individual Word count: ",len(set(cleanedText2_First200Words)))
    print ("Cleaned Richness: ",lexicalRichness(cleanedText2_First200Words))
    
    print("\n-------------------------------\n")
    
    print("[English text]: \n")
    englishText1_tokenized = nltk.word_tokenize(englishText1)

    print("Word Count: ", len(englishText1_tokenized))
    print ("Individual Word count: ",len(set(englishText1_tokenized)))
    print ("Richness: ",lexicalRichness(englishText1_tokenized), "\n")
    
    
    cleanedEnglishText = cleanText(englishText1_tokenized, "english")
    print("Cleaned Word Count: ", len(cleanedEnglishText))
    print ("Cleaned Individual Word count: ",len(set(cleanedEnglishText)))
    print ("Cleaned Richness: ",lexicalRichness(cleanedEnglishText))
    
    print("\n-------------------------------\n")
    
    print("[Greek text]: \n")
    greekText1_tokenized = nltk.word_tokenize(greekText1)

    print("Word Count: ", len(greekText1_tokenized))
    print ("Individual Word count: ",len(set(greekText1_tokenized)))
    print ("Richness: ",lexicalRichness(greekText1_tokenized), "\n")
    
    
    cleanedGreekText = cleanText(greekText1_tokenized, "english")
    print("Cleaned Word Count: ", len(cleanedGreekText))
    print ("Cleaned Individual Word count: ",len(set(cleanedGreekText)))
    print ("Cleaned Richness: ",lexicalRichness(cleanedGreekText))
    
#! Task 9)
    print("\n================(9)================\n")
    
    fdistText2_200Words = FreqDist(text2_First200Words_split)
    print(text2_First200Words_split)
    fdistText2_200Words.plot(50)
    print(fdistText2_200Words.most_common(50))
    
    print("\n-------------------------------\n")
    
    fdistText2_200Words_cleaned = FreqDist(cleanedText2_First200Words)
    fdistText2_200Words_cleaned.plot(50)
    print (fdistText2_200Words_cleaned.most_common(50))
    
    return 0
if __name__ == "__main__":
    main()