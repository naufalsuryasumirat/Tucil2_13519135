#include <iostream>
#include <string>
#include <list>
#include <vector>
#include <iterator>
#include "GraphVertices.hpp"

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
        if (i != this->outVectors.end()) {
            cout << ", ";
        }
        else {
            cout <<".";
        }
    }
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

int Vertex::getInDegree() {
    return this->inDegree;
}

int Vertex::getOutDegree() {
    return this->outDegree;
}

Graph::Graph() {
    this->verticesCount = 0;
}

void Graph::operator<<(Vertex* vertex) {
    this->VList.push_back(vertex);
    this->verticesCount += 1;
}

void Graph::topoSort() {

}

int Graph::getCount() {
    return this->verticesCount;
}