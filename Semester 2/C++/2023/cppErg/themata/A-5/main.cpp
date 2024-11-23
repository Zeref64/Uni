
#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include <sstream>

class Entry
{
private:
    std::string term;
    std::string meaning;

public:
    Entry();
    Entry(std::string, std::string);
    ~Entry();
    std::string getTerm() const;
    std::string getMeaning() const;
    bool operator==(const Entry &) const;
    std::ostream &print(std::ostream &) const;
};

Entry::Entry() {}

Entry::Entry(std::string t, std::string m) : term(t), meaning(m) {}

Entry::~Entry() {}

std::string Entry::getTerm() const { return term; }

std::string Entry::getMeaning() const { return meaning; }

bool Entry::operator==(const Entry &entry) const
{
    return term == entry.term && meaning == entry.meaning;
}

std::ostream &Entry::print(std::ostream &os) const
{
    os << "Term: " << term << ", Meaning: " << meaning;
    return os;
}

std::ostream &operator<<(std::ostream &os, const Entry &entry)
{
    return entry.print(os);
}

class Dictionary
{
private:
    std::vector<Entry> entries;

public:
    Dictionary();
    ~Dictionary();
    void Add(const Entry &);
    void Remove(const std::string &);
    Entry Find(const std::string &) const;
    void Save() const;
    void Load();
    std::vector<std::string> Sort() const;
};

Dictionary::Dictionary() {}

Dictionary::~Dictionary() {}

void Dictionary::Add(const Entry &entry)
{
    entries.push_back(entry);
}

void Dictionary::Remove(const std::string &term)
{
    std::vector<Entry>::iterator itr = entries.begin();
    while (itr != entries.end())
    {
        if ((*itr).getTerm() == term)
        {
            itr = entries.erase(itr);
        }
        else
        {
            ++itr;
        }
    }
}

Entry Dictionary::Find(const std::string &term) const
{
    for (const Entry &entry : entries)
    {
        if (entry.getTerm() == term)
        {
            return entry;
        }
    }
    return Entry();
}

void Dictionary::Save() const
{
    std::ofstream ofile("dictionary.txt");
    if (ofile.is_open())
    {
        for (const Entry &entry : entries)
        {
            ofile << entry.getTerm() << "," << entry.getMeaning() << std::endl;
        }
        ofile.close();
    }
}

void Dictionary::Load()
{
    std::ifstream ifile("dictionary.txt");
    std::string line;
    std::string term, meaning;
    if (ifile.is_open())
    {
        while (std::getline(ifile, line))
        {
            std::istringstream iss(line);
            std::getline(iss, term, ',');
            std::getline(iss, meaning, ',');
            entries.push_back(Entry(term, meaning));
        }
        ifile.close();
    }
}

std::vector<std::string> Dictionary::Sort() const
{
    std::vector<std::string> terms;
    for (const Entry &entry : entries)
    {
        terms.push_back(entry.getTerm());
    }
    for (int i = 0; i < terms.size(); i++)
    {
        for (int j = i + 1; j < terms.size(); j++)
        {
            if (terms[j] < terms[i])
            {
                std::string tmp = terms[j];
                terms[j] = terms[i];
                terms[i] = tmp;
            }
        }
    }
    return terms;
}

int main()
{
    Dictionary dict;
    dict.Add(Entry("one", "the number one"));
    dict.Add(Entry("two", "the number two"));
    dict.Add(Entry("three", "the number three"));
    dict.Add(Entry("four", "the number four"));
    dict.Save();

    std::vector<std::string> sortedTerms = dict.Sort();
    for (const std::string &term : sortedTerms)
    {
        std::cout << term << std::endl;
    }

    return 0;
}

//? Θέμα (A-5). Να δημιουργηθεί κλάση η οποία θα
//? παριστά την οντότητα “Λήμμα
//? Λεξικού”. Κάθε λήμμα θα περιέχει μόνο τον όρο
//? και τη σημασία του.
//? Να δημιουργηθεί κλάση η οποία θα παριστά την
//? οντότητα “Λεξικό” η οποία θα
//? περιέχει μία συλλογή λημμάτων και θα έχει τις εξής
//? δυνατότητες:

//? ● Θα προσθέτει ένα λήμμα στο λεξικό.
//? ● Θα διαγράφει ένα λήμμα από το λεξικό.
//? ● Θα επιστρέφει ένα λήμμα από το λεξικό
//? (αναζήτηση με βάση τον όρο).
//? ● Θα αποθηκεύει το λεξικό σε text αρχείο με
//? γραμμογράφηση που επιλέγεται
//? από τον εξεταζόμενο φοιτητή.
//? ● Θα διαβάζει το λεξικό από text αρχείο (με την
//? προηγούμενη γραμμογράφηση)
//? ● Θα επιστρέφει μία ταξινομημένη “λίστα” των
//? όρων που περιέχονται στο λεξικό
//? (σε δομή επιλογής του εξεταζόμενου φοιτητή).
//? Να επιδειχθεί η λειτουργία των παραπάνω μέσω
//? κατάλληλης main συνάρτησης.
