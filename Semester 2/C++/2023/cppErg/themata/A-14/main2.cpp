#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <random>
#include <ctime>

using namespace std;

class Map {

    private:
        vector<string> mapsVector;

    public:

        Map();
        ~Map();
        
        void readMap(string filename);
        void showMap (vector<string> mapsVec, int id);
        void random (vector<string> mapsVec);
        vector<string> getMaps() const;
};


Map::Map(){}
Map::~Map() {}


void Map::readMap(string filename) {

    string line, map;
    ifstream file(filename);
    if (!file.is_open())  {
        throw -1;
    }
    while (getline(file, line))
        map += line + "\n";

    this->mapsVector.push_back(map);
}

vector<string> Map::getMaps() const {
    return this->mapsVector;
}

void Map::showMap (vector <string> mapsVector, int id) {
    cout << mapsVector[id] << endl;
}

void Map::random (vector<string> mapsVec) {

    srand(time(NULL));
    int randomNum = rand() % mapsVector.size();
    cout << mapsVector[randomNum] << endl;
}

int main(int argc, char const *argv[])
{
    try
    {
        Map map1;
        map1.readMap("level.txt");
        map1.readMap("level2.txt");
        map1.readMap("level4.txt");
        map1.readMap("level1.txt");
        map1.showMap(map1.getMaps(), 0);


        cout << "-------------" << endl;
        map1.random(map1.getMaps());

    }
    catch(int ex)
    {
        if (ex == -1)
            cout << "error opening file" << endl;
    }
    
    return 0;
}
