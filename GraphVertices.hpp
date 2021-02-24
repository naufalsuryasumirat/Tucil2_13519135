// NIM/Nama: 13519135/Naufal Alexander Suryasumirat
// Tugas Kecil 1 STIMA (Strategi Algoritma)

#ifndef GRAPHVERTICES_HPP
#define GRAPHVERTICES_HPP
#include <iostream>
#include <string>
#include <list>
#include <vector>

using namespace std;

// Graph berarah
class Vertex {
    private:
        string name;
        int inDegree; // default 0
        int outDegree; // default 0, check later if needed, if using array definitely needed
        vector<Vertex*> outVectors; // Definitely use pointers
    public:
        Vertex(string name); // Konstruktor
        // ~Vertex();
        void operator>>(Vertex* vertex); // Menambahkan outDegree
        void printName(); // Menampilkan nama
        void printInfo(); // Menampilkan info
        void increaseOutDegree();
        void increaseInDegree();
        void decreaseOutDegree(); // Menghilangkan out degree
        void decreaseInDegree(); // Mengurangkan inDegree sebanyak 1
        void removeVertices();
        int getInDegree();
        int getOutDegree();
};

class Graph {
    private:
        int verticesCount;
        list<Vertex*> VList; // Maybe use pointers?
        vector<vector<Vertex*>> sortedVertex;
    public:
        Graph();
        // Graph(int inDegree, int outDegree, vector<Vertices> outVertices);
        void operator<<(Vertex* vertex);
        void topoSort();
        int getCount();
};

#endif