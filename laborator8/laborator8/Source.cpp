#include <fstream>
#include <string>
#include <map>
#include <queue>
#include <iostream>
using namespace std;

class Compare {
  public:
    bool operator()(pair<string, int> p1, pair<string, int> p2) {
        if (p1.second < p2.second)
            return true;
        if (p1.second > p2.second)
            return false;
        if (p1.first < p2.first)
            return false;
        return true;
    }
};

int main() {
    string myString;
    ifstream myFile("input.txt");
    if (!myFile) {
        printf("error la deschiderea fisierului: input.txt");
        return 0;
    }
    if (!getline(myFile, myString)) {
        printf("error la citirea din fisier: input.txt");
        return 0;
    }
    map<string, int> myMap;
    printf("Sirul de caractere citit este: %s\n", myString.c_str());

    int n = 0;
    auto index = 0;

    auto index_nou = myString.find_first_of(" .,!?", 1);
    while (index_nou != string::npos) {
        auto temp = myString.substr(index + 1, index_nou - index - 1);

        if (index == 0) {
            temp.clear();
            temp = myString.substr(index, index_nou);
        }
        if (index_nou - index > 1 || index == 0 && (myString[0] != ' ' && myString[0] != ',' && myString[0] != '!' &&
                                                    myString[0] != '?' && myString[0] != '.')) {
            for (char& c : temp) {
                transform(temp.begin(), temp.end(), temp.begin(), ::tolower);
            }
            if (temp != ".") {
                myMap[temp]++;
            }
        }

        index = index_nou;
        index_nou = myString.find_first_of(" .,!?  ", index + 1);
    }

    priority_queue<pair<string, int>, vector<pair<string, int>>, Compare> myQueue;
    for (auto mapIterator = myMap.begin(); mapIterator != myMap.end(); mapIterator++) {
        myQueue.push(pair<string, int>(mapIterator->first, mapIterator->second));
    }

    while (!myQueue.empty()) {
        cout << myQueue.top().first << " => " << myQueue.top().second << endl;
        myQueue.pop();
    }

    myFile.close();
    return 0;
}