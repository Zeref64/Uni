#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <random>
#include <time.h>

using namespace std;
class Map {
    private:
        vector<string> map;

    public:
        Map();
        Map(string fileName);
        void readMap(string fileName);
        void showMap(int id);

        string getMap(int id);
        string randomMap();
        ~Map();
};

Map::Map() {}

Map::Map(string fileName) {}

Map::~Map() {}

void Map::readMap(string fileName) {
    try
    {
        ifstream file(fileName);
        string contents;
        string line;
        //* Για κάθε γραμμή του αρχείου
        while (getline(file, line)) {
            contents += line + "\n";
        }
        map.push_back(contents);
        file.close();
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }
}

void Map::showMap(int id) {
    
    cout << map[id] << endl;
}


string Map::getMap(int id) {
    return map[id];
}

string Map::randomMap() {

    srand(time(NULL));
    int limit = map.size();
    int id = rand() % limit;
    return map[id];
}

int main(int argc, char const *argv[])
{
    Map mapobj("level.txt");
    mapobj.readMap("level.txt");
    
    mapobj.readMap("level2.txt");
    mapobj.readMap("level3.txt");

    cout << mapobj.randomMap() << endl;

    // mapobj.showMap(0);

    // cout << "\n\n\n";
    // // mapobj.showMap(1);
    // string map2;
    // map2 = mapobj.getMap(1);
    // cout << map2 <<endl;




    return 0;
}
