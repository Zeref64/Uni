#!/bin/python3

from nltk.book import *
import nltk.tokenize

import numpy as np
import pandas as pd

import string
import gc

# -----------------------------------------------

def UnionList(lst1, lst2):
    union_list = list(set(lst1) | set(lst2))        #* Union of 2 lists using sets
    return union_list

# -----------------------------------------------

def cleanText (tokenList, language):
    
    cleanedTokens = []
    stopwords = nltk.corpus.stopwords.words(language)
    for token in tokenList:
        if token not in string.punctuation and token not in stopwords:
            cleanedTokens.append(token)
    return cleanedTokens

# -----------------------------------------------


def removePunctuation (tokenList):
    
    cleanedTokens = []
    for token in tokenList:
        if token not in string.punctuation:
            cleanedTokens.append(token)
    return cleanedTokens

# -----------------------------------------------

def mostCommon3(text):
    
    tokenized_first50Words = text[:50]
    cleaned_text = cleanText(tokenized_first50Words, "english")     #* Without Stopwords
    # cleaned_text = removePunctuation(tokenized_first50Words)      #* With Stopwords
    normalized_text =[x.lower() for x in cleaned_text]     
    
    fdistText = FreqDist(normalized_text)
    
    # fdistText.plot (50)
    wordList_Tuple = fdistText.most_common(3)
    
    wordList_final = []
    for i in range(len(wordList_Tuple)):
        wordList_final.append(str(wordList_Tuple[i][0]))    #* Create a list of strings with the 3 most common words
    return wordList_final

# -----------------------------------------------

def postingList(text):
    
    normalized_text =[x.lower() for x in text]
    pos_index = {}      #*  dictionary initialization 
    tokenList = mostCommon3(normalized_text)       #* mostCommon3 returns the 3 most common 
                                                #* words of the text in the parameter in a list of strings.
    word_counter = 0
    
    for pos, term in enumerate(normalized_text):      #* For each word of the whole text
        if term in tokenList:       #* If the word is one of the 3 most common then add it and its position 
                                    # *on the posting list.
            
            if term in pos_index:       #* If the word has already been found once

                pos_index[term][0] = pos_index[term][0] + 1     #* Increment the frequency
                if word_counter in pos_index[term][1]:
                    pos_index[term][1][word_counter].append(pos)    #* Map the word location based on the counter
                else:
                    pos_index[term][1][word_counter] = [pos]

            # (first encounter).
            else:
                pos_index[term] = []       #* Create the list for that word
                pos_index[term].append(1)
                pos_index[term].append({})      #* Initiallize the list
                pos_index[term][1][word_counter] = [pos]
                word_counter += 1
    return pos_index

# -----------------------------------------------
    
def SentenceCos(sent_x, sent_y):
        
    tokenized_sent_x = nltk.word_tokenize(sent_x)   #* Tokeinzing both sentences
    tokenized_sent_y = nltk.word_tokenize(sent_y)
    
    cleanSent_x = cleanText(tokenized_sent_x, "english")
    cleanSent_y = cleanText(tokenized_sent_y, "english")    #* Removing punctuation and stopwords
    
    #* Creating a binary vector with only '1' or '0' as values for example binaryVec_X [0,0,1,0]
    #* Both vectors have the same length similar to one-hot vectors.
    #* Whenever a value of a vector is '1' that means that the word in that position is found in the sentece
    #* So the logic here is to map all the words that are contained in both sentences
    
    binaryVec_X = []
    binaryVec_Y = []      
    
    final = 0
    
    allTokens = UnionList(cleanSent_x, cleanSent_y) 
    for i in allTokens:
        if i in cleanSent_x:
            binaryVec_X.append(1)   #* Initialize binary Vector X
        else: 
            binaryVec_X.append(0)
        if i in cleanSent_y:
            binaryVec_Y.append(1)   #* Initialize binary Vector Y
        else:
            binaryVec_Y.append(0)
    
    for i in range(len(allTokens)):
        final += binaryVec_X[i] * binaryVec_Y[i]    #? If the word is contained in both texts final variable increments by 1
        
    cosSimilarity = final / float((sum(binaryVec_X) * sum(binaryVec_Y)) ** 0.5)
    print("The cos similarity between the two sentences is: ", cosSimilarity)
    
# -----------------------------------------------

def main():
    
#! Task 1)
    print("\n================(1.1)================\n")
    
    print("---------------[ Onehot-Vector 1 with split() ]---------------\n")
    
    sentence1 = "Thomas Jefferson began building Monticello at the age of 26."
    
        #? Data initialization for split() sentence1
    split_sentence1 = sentence1.split()    #* Tokenizing sentence1 with Python's split() method
    split_vocabulary1 = sorted(set(split_sentence1))      #* Initializing unique tokens of sentence1 then sorting them
    split_tokens1_len = len(split_sentence1)      #* Total number of tokens in our sentence
    split_vocabulary1_size = len(split_vocabulary1)     #* Total number of unique tokens in our sentence
    print (', '.join(split_vocabulary1), "\n")
    
        #? Creating onehot-vector for split() sentence1
    split_onehot_vector1 = np.zeros((split_tokens1_len, split_vocabulary1_size), int)     #* Onehot vector initialization with '0'
    for i, word in enumerate(split_sentence1):
        split_onehot_vector1 [i, split_vocabulary1.index(word)] = 1      #* Changing 0 into 1 if that word is in the correct index
    print (' '.join(split_vocabulary1))
    print (split_onehot_vector1)
    
    print("\n---------------[ Onehot-Vector 1 with ntlk.word_tokenize() ]---------------\n")
    
    tokenize_sentence1 = nltk.word_tokenize(sentence1)
    
    tokenize_vocabulary1 = sorted(set(tokenize_sentence1))      
    tokenize_tokens1_len = len(tokenize_sentence1)      
    tokenize_vocabulary1_size = len(tokenize_vocabulary1)     
    print (', '.join(tokenize_vocabulary1), "\n")
    
        #? Creating onehot-vector for tokenize sentence2
    tokenize_onehot_vector1 = np.zeros((tokenize_tokens1_len, tokenize_vocabulary1_size), int)    
    for i, word in enumerate(tokenize_sentence1):
        tokenize_onehot_vector1 [i, tokenize_vocabulary1.index(word)] = 1   
    print (' '.join(tokenize_vocabulary1))
    print (tokenize_onehot_vector1)
    
    print("\n================(1.2)================\n")
    
    print("\n---------------[ Onehot-Vector 2 with split() ]---------------\n")
    
    sentence2 = "A sword wields no strength, unless the hand that holds it has courage."
    
        #? Data initialization for split() sentence2
    split_sentence2 = sentence2.split()    #* Tokenizing sentence2 with Python's split() method
    
    split_vocabulary2 = sorted(set(split_sentence2))      
    split_tokens2_len = len(split_sentence2)      
    split_vocabulary2_size = len(split_vocabulary2)     
    print (', '.join(split_vocabulary2), "\n")
    
        #? Creating onehot-vector for split() sentence2
    split_onehot_vector2 = np.zeros((split_tokens2_len, split_vocabulary2_size), int)    
    for i, word in enumerate(split_sentence2):
        split_onehot_vector2 [i, split_vocabulary2.index(word)] = 1   
    print (' '.join(split_vocabulary2))
    print (split_onehot_vector2)
    
    print("\n---------------[ Onehot-Vector 2 with ntlk.word_tokenize() ]---------------\n")
    
        #? Data initialization for tokenize sentence2
    tokenize_sentence2 = nltk.word_tokenize(sentence2)
    
    tokenize_vocabulary2 = sorted(set(tokenize_sentence2))      
    tokenize_tokens2_len = len(tokenize_sentence2)      
    tokenize_vocabulary2_size = len(tokenize_vocabulary2)     
    print (', '.join(tokenize_vocabulary2), "\n")
    
        #? Creating onehot-vector for tokenize sentence2
    tokenize_onehot_vector2 = np.zeros((tokenize_tokens2_len, tokenize_vocabulary2_size), int)    
    for i, word in enumerate(tokenize_sentence2):
        tokenize_onehot_vector2 [i, tokenize_vocabulary2.index(word)] = 1   
    print (' '.join(tokenize_vocabulary2))
    print (tokenize_onehot_vector2)
    
    
    #! Task 2)
    print("\n================(2.1)================\n")
    
    print("---------------[ Pandas DataFrame 1 with split() ]---------------\n")
    print (pd.DataFrame(split_onehot_vector1, columns=split_vocabulary1))
    
    print("\n---------------[ Pandas DataFrame 1 with ntlk.word_tokenize() ]---------------\n")
    print (pd.DataFrame(tokenize_onehot_vector1, columns=tokenize_vocabulary1))
    
    print("\n================(2.2)================\n")
    
    print("---------------[ Pandas DataFrame 2 with split() ]---------------\n")
    print (pd.DataFrame(split_onehot_vector2, columns=split_vocabulary2))
    
    print("\n---------------[ Pandas DataFrame 2 with ntlk.word_tokenize() ]---------------\n")
    print (pd.DataFrame(tokenize_onehot_vector2, columns=tokenize_vocabulary2))
    
    
    #! Task 3)
    print("\n================(3.α)================\n")

    #? sentence2 = "A sword wields no strength, unless the hand that holds it has courage."
    sentence3 = "The kid was a prodigy on sword mastery."
    sentence4 = "The villain used his strength to kill the kid."
    sentence5 = "The kid had the courage to fight."
    
    same_words_array1 = {}
    
    same_words_array1['sentence2'] = dict((tok.strip('.'), 1) for tok in nltk.word_tokenize(sentence2))
    same_words_array1['sentence3'] = dict((tok.strip('.'), 1) for tok in nltk.word_tokenize(sentence3))
    same_words_array1['sentence4'] = dict((tok.strip('.'), 1) for tok in nltk.word_tokenize(sentence4))
    same_words_array1['sentence5'] = dict((tok.strip('.'), 1) for tok in nltk.word_tokenize(sentence5))
    
    dataFrame1 = pd.DataFrame.from_records(same_words_array1).fillna(0).astype(int).T
    print (dataFrame1)
    
    dataFrame1 = dataFrame1.T
    print (dataFrame1.sentence2.dot(dataFrame1.sentence2))  #? Num of the same words sentence2 has with itself
    print (dataFrame1.sentence2.dot(dataFrame1.sentence3))  #? Num of the same words sentence2 has with sentence3
    # print (dataFrame1.sentence4.dot(dataFrame1.sentence4))
    print (dataFrame1.sentence5.dot(dataFrame1.sentence5))

    print("\n================(3.β)================\n")
    
    same_words_array2 = {}
    same_words_array2['text4'] = dict((tok, 1) for tok in nltk.word_tokenize(" ".join(text4[0:50])))
    same_words_array2['text7'] = dict((tok, 1) for tok in nltk.word_tokenize(" ".join(text7[0:50])))
    
    dataFrame2 = pd.DataFrame.from_records(same_words_array2).fillna(0).astype(int).T
    print(dataFrame2)
    print("\nMutual words example: (word, found)\n", [(token, count) for (token, count) in (dataFrame2.T.text4 & dataFrame2.T.text7).items() if count])
    
    
    #! Task 4)
    print("\n================(4)================\n")
    
    print("---------------[ Text4 ]---------------\n")
    text4_PostingList = postingList(text4[:50])
    print ("3 most common words in Posting list format:\n ",text4_PostingList,"\n")
    
    print("\n---------------[ Text7 ]---------------\n")
    text7_PostingList = postingList(text7[:50])
    print ("3 most common words in Posting list format:\n ",text7_PostingList,"\n")


    #! Task 5)
    print("\n================(5)================\n")     
    
    # print(" ".join(text4[620:660]))
    # print(" ".join(text7[570:660]))

    text4Sentence = "These reflections, arising out of the present crisis, have forced themselves too strongly on my mind to be suppressed."
    text7Sentence = "More common chrysotile fibers are curly and are more easily rejected *-1 by the body, Dr. Mossman explained 0 *T*-2."
    
    SentenceCos(text4Sentence, text7Sentence)


    #! Task 6)
    print("\n================(6)================\n")

    allText4 = " ".join(text4[:])
    allText7 = " ".join(text7[:])
    
    SentenceCos(allText4, allText7)
    
    return 0

if __name__ == "__main__":
    main()