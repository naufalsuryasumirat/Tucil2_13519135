#include <iostream>
#include <string>
// #include <list>
#include <vector>
#include <iterator>
#include "GraphVertices.hpp"

#define TEST cout << "TEST" << endl;

using namespace std;

Vertex::Vertex(string name) {
    this->name = name;
    this->inDegree = 0;
    this->outDegree = 0;
    // this->outVectors = new vector<Vertex*>;
}

// Vertex::~Vertex() {
//     this->outVectors.clear();
// }

void Vertex::operator>>(Vertex* vertex) {
    this->outVectors.push_back(vertex);
    increaseOutDegree();
    vertex->increaseInDegree();
}

void Vertex::printName() {
    cout << this->name;
}

void Vertex::printInfo() {
    cout << "Name : " << this->name << endl;
    cout << "InC  : " << this->inDegree << endl;
    cout << "outC : " << this->outDegree << endl;
    cout << "outV : ";
    for (vector<Vertex*>::iterator i = this->outVectors.begin(); i != this->outVectors.end(); i++) {
        (*i)->printName();
        if (i != this->outVectors.end() - 1) {
            cout << ", ";
        }
        else {
            cout <<".";
        }
    }
    cout << endl;
}

void Vertex::increaseOutDegree() {
    this->outDegree += 1;
}

void Vertex::increaseInDegree() {
    this->inDegree += 1;
}

void Vertex::decreaseOutDegree() {
    this->outDegree -= 1;
}

void Vertex::decreaseInDegree() {
    this->inDegree -= 1;
}

void Vertex::removeVertices() {
    for (vector<Vertex*>::iterator i = this->outVectors.begin(); i != this->outVectors.end(); i++) {
        (*i)->decreaseInDegree();
        decreaseOutDegree();
    }
    this->outVectors.clear();
}

bool Vertex::operator==(Vertex const& V) {
    return this->name == V.name; ///// check later
}

int Vertex::getInDegree() {
    return this->inDegree;
}

int Vertex::getOutDegree() {
    return this->outDegree;
}

string Vertex::getName() {
    return this->name;
}

Graph::Graph() {
    this->verticesCount = 0;
}

void Graph::checkVList() {
    for (vector<Vertex*>::iterator i = this->VList.begin(); i != this->VList.end(); i++) {
        (*i)->printInfo();
        cout << "------" << endl;
    }
}

void Graph::operator<<(Vertex* vertex) {
    bool found = false; //// check lagi ntar
    for (vector<Vertex*>::iterator i = this->VList.begin(); i != this->VList.end(); i++) {
        if ((*i)->getName() == vertex->getName()) {
            found = true;
            break;
        }
    }
    if (!found) {
        this->VList.push_back(vertex);
        this->verticesCount += 1;
    }
}

void Graph::removeVertex(string name) {
    for (vector<Vertex*>::iterator i = this->VList.begin(); i != this->VList.end(); i++) {
        if (name == (*i)->getName()) {
            this->VList.erase(i);
            this->verticesCount -= 1;
            break;
        }
    }
}
///// GIMANA KASUS BUKAN ACYCLIC GRAPH???
void Graph::topoSort() {
    while (this->verticesCount > 0) {
        bool a_zero = false; // indikator ada satu vertex dengan edge masuk ke simpul tersebut = 0
        vector<Vertex*> toAdd;
        for (vector<Vertex*>::iterator i = this->VList.begin(); i != this->VList.end(); i++) {
            if ((*i)->getInDegree() == 0) {
                toAdd.push_back(*i);
                a_zero = true;
                // TEST
            }
        }
        if (a_zero) {
            for (vector<Vertex*>::iterator i = toAdd.begin(); i != toAdd.end(); i++) {
                (*i)->removeVertices();
                removeVertex((*i)->getName());
                this->sortedVertex.push_back(toAdd); //////CHECK
                // TEST
            }
        }
        else { //// KASUS ACYCLIC GRAPPH BEGINI???
            toAdd.clear();
            this->sortedVertex.clear();
            // TEST
            break;
        }
    }
}

void Graph::print() {
    int count = 1;
    if (this->sortedVertex.empty()) {
        cout << "Input tidak valid atau Graph bukan merupakan Graph acyclic." << endl;
    }
    else {
        for (vector<vector<Vertex*>>::iterator i = this->sortedVertex.begin(); i != this->sortedVertex.end(); i++) {
            cout << "S" << count << endl;
            for (vector<Vertex*>::iterator j = i->begin(); j != i->end(); j++) {
                cout << (*j)->getName() << endl;
                // TEST
            }
            count++;
        }
    }
}

int Graph::getCount() {
    return this->verticesCount;
}