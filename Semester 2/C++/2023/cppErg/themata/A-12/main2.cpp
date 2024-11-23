#include <iostream>
#include <vector>
#include <utility>

using namespace std;

class Cell {
private:
    string type;
    string content;

public:
    Cell(const string& type, const string& content) : type(type), content(content) {}
    // Getters and other member functions for Cell
    unsigned int Size() const;
};

class Excel {
private:
    vector<pair<Cell*, pair<int, int>>> cells;

public:
    Excel(const vector<pair<Cell*, pair<int, int>>>& cellVector);
    // Other member functions for Excel
};

Excel::Excel(const vector<pair<Cell*, pair<int, int>>>& cellVector) {
    if (cellVector[0].second.first > 10000 || cellVector[0].second.second > 200) {
        cout << "Invalid cell dimensions." << endl;
    }
    this->cells = cellVector;

// unsigned int Excel::Size() const {
    // return cells.size();

// }
}

int main() {
    vector<pair<Cell*, pair<int, int>>> cellVector;
    cellVector.push_back(make_pair(new Cell("int", "I am a cell"), make_pair(1, 2)));

    // Create an instance of Excel using the cellVector
    Excel excel(cellVector);

    // Demonstrate the usage of Excel
    cout << "Excel object created with " << excel.Size() << " cells." << endl;

    // Clean up memory
    for (auto& cellPair : cellVector) {
        delete cellPair.first;
    }
    cellVector.clear();

    return 0;
}
