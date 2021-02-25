#include <iostream>
#include <string>
#include <list>
#include <vector>
#include <fstream>
#include <iterator>
#include "GraphVertices.hpp"

using namespace std;

int main() {
    // ifstream file("soal.txt");
    // string str;
    // int i = 0;
    // while (getline(file, str)) {
    //     cout << str << endl;
    //     i++;
    // }
    // cout << i << endl;

    list<int> intList;
    intList.push_back(6);
    intList.push_back(6);
    intList.push_back(7);
    intList.push_back(8);
    intList.push_back(10);
    for (list<int>::iterator i = intList.begin(); i != intList.end(); i++) {
        cout << *i << endl;
    }

    vector<int> intVector;
    intVector.push_back(6);
    intVector.push_back(6);
    intVector.push_back(7);
    intVector.push_back(8);
    intVector.push_back(10);
    for (vector<int>::iterator i = intVector.begin(); i != intVector.end(); i++) {
        cout << *i << endl;
    }

    for (vector<int>::iterator i = intVector.begin(); i != intVector.end(); i++) {
        if (*i == 7) {
            intVector.erase(i);
        }
        else {
            cout << *i << endl;
        }
    }

    Vertex a("C1");
    Vertex b("C2");
    a.printInfo();
    b.printInfo();

    a>>(&b);
    a.printInfo();
    b.printInfo();

    a.removeVertices();
    a.printInfo();
    b.printInfo();
    
    return 0;
}