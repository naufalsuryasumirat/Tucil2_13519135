#include <iostream>
#include <string>
// #include <list>
#include <vector>
#include <fstream>
#include <iterator>
#include "GraphVertices.hpp"

#define TEST cout << "TEST" << endl;
#define LINE cout << "---------------------" << endl;

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

    

    Vertex c1("C1");
    Vertex c2("C2");
    Vertex c3("C3");
    Vertex c4("C4");
    Vertex c5("C5");
    // a.printInfo();
    // b.printInfo();

    // a>>(&b);
    // a.printInfo();
    // b.printInfo();

    // a.removeVertices();
    // a.printInfo();
    // b.printInfo();
    c3 >> &c1;

    c1 >> &c2;
    c4 >> &c2;

    c1 >> &c4;
    c3 >> &c4;

    c2 >> &c5;
    c4 >> &c5;

    c1.printInfo();
    cout << "----" << endl;
    c2.printInfo();
    cout << "----" << endl;
    c3.printInfo();
    cout << "----" << endl;
    c4.printInfo();
    cout << "----" << endl;
    c5.printInfo();
    cout << "----" << endl;

    Vertex* c1p = &c1;
    Vertex* c2p = &c2;
    Vertex* c3p = &c3;
    Vertex* c4p = &c4;
    Vertex* c5p = &c5;

    Graph g = Graph();
    cout << g.getCount() << endl;

    g << c1p;
    g << c2p;
    g << c3p;
    g << c4p;
    g << c5p;

    // cout << g.getCount() << endl;
    // g.checkVList();
    // cout << "removing vertices for c1" << endl;
    // c1.removeVertices();
    // c1.printInfo();
    // cout << "alsdfasldkfalsdkfj" << endl;
    // g.checkVList();
    // LINE
    // g.removeVertex(c1.getName());
    // g.checkVList();
    // cout << g.getCount() << endl;

    g.topoSort();
    g.print();
    // cout << g.getCount() << endl;



    return 0;
}