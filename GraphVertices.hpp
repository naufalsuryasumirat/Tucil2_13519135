// NIM/Nama: 13519135/Naufal Alexander Suryasumirat
// Tugas Kecil 2 STIMA (Strategi Algoritma) Algoritma Decrease and Conquer

#ifndef GRAPHVERTICES_HPP
#define GRAPHVERTICES_HPP
#include <iostream>
#include <string>
#include <vector>

using namespace std;
/// Perlu outDegree jika tidak boleh menggunakan vector
// Graph berarah
class Vertex { // Mencatat inDegree dan Vertex-Vertex yang dituju
    private:
        string name; // Nama dari vertex
        int inDegree; // Jumlah edge yang masuk ke dalam vertex tersebut
        vector<Vertex*> outVectors; // Vector yang berisi pointer yang menuju kepada vertex yang dituju oleh edge yang mengarah keluar
    public:
        Vertex(string name); // Konstruktor dari class Vertex
        void operator>>(Vertex* vertex); // Menambahkan vertex pada outVectors pada suatu vertex
        void printInfo(); // Menampilkan info (Nama/ID, Jumlah InDegree, Tujuan edge yang mengarah keluar)
        void increaseInDegree(); // Menambahkan inDegree sebanyak 1
        void decreaseInDegree(); // Mengurangkan inDegree sebanyak 1
        void removeVertices(); // Menghilangkan Vertex pada outVectors sekaligus mengurangi inDegree pada vertex yang dihilangkan
        bool operator==(Vertex const& V); // Operator overload untuk membandingkan dua vertex
        int getInDegree(); // Getter inDegree
        string getName(); // Getter name
};

class Graph { // Directed Graph
    private:
        int verticesCount; // Jumlah vertices/simpul yang terdapat pada Graph
        vector<Vertex*> VList; // Berisi pointer menuju Vertex yang terdapat pada Graph
        vector<vector<Vertex*>> sortedVertex; // Bentuk Graph yang sudah di sort dengan Topological Sort
    public:
        Graph(); // Konstruktor Graph
        void checkVList(); // Memperlihatkan isi vertex yang terdapat pada Graph
        void operator<<(Vertex* vertex); // Menambahkan vertex ke Graph
        void removeVertex(string name); // Menghilangkan suatu vertex dari Graph
        void topoSort(); // Algoritma Topological Sort pada Directed Graph
        void print(); // Memperlihatkan hasil Topolotical Sort
        int getCount(); // Getter jumlah vertices pada Graph
};

#endif