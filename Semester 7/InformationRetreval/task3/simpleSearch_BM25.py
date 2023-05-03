from rank_bm25 import BM25Okapi
import nltk.tokenize
import string
import time
from urllib.request import urlopen


# -----------------------------------------------

def removePunctuations (inputString, string):
    return inputString.translate(str.maketrans('', '', string.punctuation)).lower()

# -----------------------------------------------

print("\n---BM25---\n")

# ? Tutorial Video: https://www.youtube.com/watch?v=ysvpxiPAHLg
# ? Tutorial Repo: https://github.com/wjbmattingly/youtube-bm25

# ? Rank BM25 Repo: https://github.com/dorianbrown/rank_bm25 

corpus =[
    "It's a me, Mario! ",
    "The hero that once saved hyrule from eternal darkness was named Link!",            #? hard-coded document
    "For dinner we have spaghetti with meatballs",
    "Luigi is scared of ghosts ??!",
    "With the use of the Master Sword, Link was able to defeat the pure evil named Ganondorf"
    ]
file = open("/home/zeref/Projects/Uni/Semester 7/InformationRetreval/task3/file1.txt", "r")    # Use this to open file locally

# # url = "https://www.gutenberg.org/cache/epub/345/pg345.txt"
# file = urlopen(url)                  # Use this to open file from url
# file = open("[Insert the Path to file]", "r")    # Use this to open file locally
corpus = []
for line in file:
    corpus.append(line)
# print(len(corpus))


porter = nltk.PorterStemmer()
wnl = nltk.WordNetLemmatizer()

stemmed_corpus = [porter.stem(word) for word in corpus]
preproccesed_corpus = [wnl.lemmatize(t) for t in stemmed_corpus]
#! ask1 preprocessing techniques

tokenized_corpus = []
for doc in preproccesed_corpus:
    clean_doc = nltk.word_tokenize(removePunctuations(doc, string))
    # ! used nltk instead of split() method
    tokenized_corpus.append(clean_doc)
# print(tokenized_corpus)

bm25 = BM25Okapi(tokenized_corpus)

query = "intRusions del icate and fiNely"
stemmed_query = porter.stem(query)
preproccesed_query = wnl.lemmatize(stemmed_query)

tokenized_query = nltk.word_tokenize(removePunctuations(preproccesed_query, string))
# print (tokenized_query)

t0 = time.time()
results = bm25.get_top_n(tokenized_query,corpus,n=1)
doc_scores = bm25.get_scores(tokenized_query)
t1 = time.time()
for i in results:   
    print(i)
print(doc_scores)
print(f'\nSearched in {round(t1-t0,3) } seconds \n')

