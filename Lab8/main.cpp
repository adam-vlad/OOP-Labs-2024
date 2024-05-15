#include <iostream>
#include <fstream>
#include <string>
#include <map>
#include <queue>
#include <cctype>
using namespace std;

class Compare {
public:
    bool operator()(pair<string, int> a, pair<string, int> b) {
        if (a.second > b.second)
            return false;
        if (a.second < b.second)
            return true;
        if (a.first < b.first)
            return false;

        return true;
    }
};

int main() {
    string inputRaw;
    ifstream myFile("input.txt");
    if (!myFile)
    {
        printf("error la deschiderea fisierului: input.txt");
        return 0;
    }

    if (!getline(myFile, inputRaw)) {
        printf("error la citirea din fisier: input.txt");
        return 0;
    }
    map<string, int> myMap;
    string cuv;

    for (size_t i = 0; i < inputRaw.size(); ++i) {
        char car = inputRaw[i];
        if (car == ' ' || car == ',' || car == '.' || car == '?' || car == '!') {
            if (!cuv.empty()) {
                for (size_t i = 0; i < cuv.size(); ++i) {
                    char& ch = cuv[i];
                    ch = std::tolower(ch);
                }
                myMap[cuv]++;
                cuv.clear();
            }
        }
        else {
            cuv += car;
        }
    }

    if (!cuv.empty()) {
        for (size_t i = 0; i < cuv.size(); ++i) {
            char& ch = cuv[i];
            ch = std::tolower(ch);
        }

        myMap[cuv]++;
    }

    priority_queue<pair<string, int>, vector<pair<string, int>>, Compare> myQueue;

    for (auto it = myMap.begin(); it != myMap.end(); ++it) {
        auto& pair = *it;
        myQueue.push(pair);
    }

    while (!myQueue.empty()) {
        cout << myQueue.top().first << " => " << myQueue.top().second << endl;
        myQueue.pop();
    }

    return 0;
}