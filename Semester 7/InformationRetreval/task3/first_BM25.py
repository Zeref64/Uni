from tqdm import tqdm
from rank_bm25 import BM25Okapi
import pandas as pd
import spacy
import time

pd.set_option('display.max_colwidth', None)
###link to data:
#https://drive.google.com/file/d/1pJFPa5772JiXWpath_to_dataxZ9pGpwNbO6D0BBCEXZ/view?usp=sharing
df = pd.read_csv('/home/zeref/Projects/Uni/Semester 7/InformationRetreval/task3/test.csv')
nlp = spacy.load("en_core_web_sm")
tok_text=[] # for our tokenised corpus

#Tokenising using SpaCy:
for doc in nlp.pipe(df.Country.str.lower().values, disable=["tagger", "parser","ner"]):
    tok = [t.text for t in doc if t.is_alpha]
    tok_text.append(tok)
    
bm25 = BM25Okapi(tok_text)

query = "Greece"
tokenized_query = query.lower().split(" ")
import time

t0 = time.time()
results = bm25.get_top_n(tokenized_query, df.Country.values, n=3)
t1 = time.time()
print(f'Searched in {round(t1-t0,3) } seconds \n')
for i in results:   
    print(i)