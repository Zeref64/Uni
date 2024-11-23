#include<string>
#include<iostream>
#include <vector>

using namespace std;
class Cell {

    private:
        string Type;
        string Contents;
    
    public:
        Cell ();
        Cell (string type, string contents) ;
};

Cell::Cell (string type, string contents) : Type(type), Contents(contents){}

class exel{
    
    private:
        vector <pair<Cell*, pair <int, int> > > cells;

    public:
    exel();
    exel(vector <pair<Cell*, pair <int, int> > >);
};

exel::exel(vector <pair<Cell*, pair <int, int> > > cellVector) {
    if (cellVector[0].second.first > 10000 || cellVector[0].second.first > 200) 
    {
        cout << "asdsaddasadsdsa";
    }
    this->cells = cellVector;
}

int main(int argc, char const *argv[])
{
    vector <pair<Cell*, pair <int, int>>> vector;
    vector.push_back(make_pair(Cell("int", "i am a cell"), make_pair(1,2)));

    Cell("int", "i am a cell");
    // exel()
    return 0;
}
