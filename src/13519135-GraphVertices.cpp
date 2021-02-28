// NIM/Nama: 13519135/Naufal Alexander Suryasumirat
// Tugas Kecil 2 STIMA (Strategi Algoritma) Algoritma Decrease and Conquer

#include <iostream>
#include <string>
#include <vector>
#include <iterator>
#include "13519135-GraphVertices.hpp"

#define TEST cout << "TEST" << endl;
#define LINE cout << "---------------------------" << endl;

using namespace std;

// Konstruktor dari Vertex untuk membentuk vertex yang memiliki nama, 
//      inDegree sebanyak 0, dan vector yang berisi pointer ke vertex lain yang belum diisi
Vertex::Vertex(string name) {
    this->name = name;
    this->inDegree = 0;
}

// Method operator overload yang berfungsi untuk menambahkan pointer pada atribut outVectors
// Untuk menambahkan tujuan vector sehingga jika a >> b maka a menuju b atau a --> b
void Vertex::operator>>(Vertex* vertex) {
    this->outVectors.push_back(vertex);
    vertex->increaseInDegree();
}

// Method untuk menampilkan info suatu Vertex
// Name menandakan nama (sekaligus ID) dari Vertex tersebut
// InC merupakan jumlah in degree (edge yang masuk dari vertices lainnya)
// outV memperlihatkan isi vector yang berisi pointer ke objek (vertex lainnya) 
//      yang dituju oleh edge yang mengarah keluar dari vertex tersebut
void Vertex::printInfo() {
    cout << "Name : " << this->name << endl;
    cout << "InC  : " << this->inDegree << endl;
    cout << "outV : ";
    for (vector<Vertex*>::iterator i = this->outVectors.begin(); i != this->outVectors.end(); i++) {
        cout << (*i)->getName();
        if (i != this->outVectors.end() - 1) {
            cout << ", ";
        }
        else {
            cout <<".";
        }
    }
    cout << endl;
}

// Method yang berfungsi untuk menambah inDegree dari suatu vertex sebanyak satu
void Vertex::increaseInDegree() {
    this->inDegree += 1;
}

// Method yang berfungsi untuk mengurangi inDegree dari suatu vertex sebanyak satu
void Vertex::decreaseInDegree() {
    this->inDegree -= 1;
}

// Method yang berfungsi untuk menghilangkan edge yang mengarah keluar menuju vertex lain 
//        pada suatu vertex
// Method juga sekaligus mengurangi inDegree pada vertex yang edge-nya diputuskan
void Vertex::removeVertices() {
    for (vector<Vertex*>::iterator i = this->outVectors.begin(); i != this->outVectors.end(); i++) {
        (*i)->decreaseInDegree();
    }
    this->outVectors.clear();
}

// Method operator overload yang berfungsi untuk menentukan kesamaan dua vertex
bool Vertex::operator==(Vertex const& V) {
    return this->name == V.name; ///// check later
}

// Getter pada Vertex untuk mendapatkan inDegree (integer)
int Vertex::getInDegree() {
    return this->inDegree;
}

// Getter pada Vertex untuk mendapatkan nama (string)
string Vertex::getName() {
    return this->name;
}

// Konstruktor dari Graph yang 
Graph::Graph() {
    this->verticesCount = 0;
}

// Method yang berfungsi untuk memperlihatkan isi vector VList (vector of Vertex pointers)
void Graph::checkVList() {
    for (vector<Vertex*>::iterator i = this->VList.begin(); i != this->VList.end(); i++) {
        (*i)->printInfo();
        LINE
    }
}

// Method operator overload << yang berfungsi untuk menambahkan suatu pointer menuju vertex
//      pada suatu Graph (dalam atribut vector<Vertex*> VList) yang berisi vertex yang
//      terdapat pada Directed Graph tersebut
void Graph::operator<<(Vertex* vertex) {
    bool found = false; //// check lagi ntar
    for (vector<Vertex*>::iterator i = this->VList.begin(); i != this->VList.end(); i++) {
        if (*i == vertex) {
            found = true;
            break;
        }
    } 
    // Jika belum ada, maka ditambahkan vertex tersebut
    if (!found) {
        this->VList.push_back(vertex);
        this->verticesCount += 1;
    }
}

// Method yang befungsi untuk menghilangkan suatu vertex dari Graph
void Graph::removeVertex(string name) {
    for (vector<Vertex*>::iterator i = this->VList.begin(); i != this->VList.end(); i++) {
        if (name == (*i)->getName()) {
            this->VList.erase(i);
            this->verticesCount -= 1;
            break;
        }
    }
}

// Algoritma topological sort pada Graph untuk mengurutkan vertex pada graph
void Graph::topoSort() {
    while (this->verticesCount > 0) {
        bool a_zero = false; 
            // indikator minimal terdapat satu vertex dengan edge masuk ke simpul tersebut = 0
        vector<Vertex*> toAdd;
            // vector yang berisi pointer ke Vertex yang akan dimasukkan pada sortedVertex
        for (vector<Vertex*>::iterator i = this->VList.begin(); i != this->VList.end(); i++) {
            if ((*i)->getInDegree() == 0) {
                toAdd.push_back(*i);
                a_zero = true;
            }
        }
        if (a_zero) { // Jika terdapat minimal satu Vertex dengan inDegree 0 pada iterasi ini
            for (vector<Vertex*>::iterator i = toAdd.begin(); i != toAdd.end(); i++) {
                (*i)->removeVertices();
                removeVertex((*i)->getName());
            }
            this->sortedVertex.push_back(toAdd);
        }
        else { // Kasus jika terdeteksi Directed Graph tidak Acyclic
            toAdd.clear();
            this->sortedVertex.clear();
            break;
        }
    }
}

// Method untuk menampilkan hasil dari topological sort Graph
void Graph::print() {
    int count = 1;
    if (this->sortedVertex.empty()) {
        cout << "Input tidak valid atau Graph bukan merupakan Graph acyclic." << endl;
    }
    else {
        cout << endl;
        cout << "Mata kuliah yang diambil:" << endl;
        for (vector<vector<Vertex*>>::iterator i = this->sortedVertex.begin(); i != this->sortedVertex.end(); i++) {
            if (count > 8) {
                cout << "Mata kuliah yang diambil lebih dari 8 semester, diperlihatkan hanya sampai semester 8" << endl;
                break;
            }
            cout << "Semester " << count << ": ";
            for (vector<Vertex*>::iterator j = i->begin(); j != i->end(); j++) {
                if (j < i->end() - 1) {
                    cout << (*j)->getName() << ", ";
                }
                else {
                    cout << (*j)->getName() << "." << endl;
                }
            }
            count++;
        }
        cout << endl;
    }
}

// Getter jumlah vertices pada Graph
int Graph::getCount() {
    return this->verticesCount;
}