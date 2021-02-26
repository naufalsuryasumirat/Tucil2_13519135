// NIM/Nama: 13519135/Naufal Alexander Suryasumirat
// Tugas Kecil 2 STIMA (Strategi Algoritma) Algoritma Decrease and Conquer

#ifndef FILEHANDLER_HPP
#define FILEHANDLER_HPP
#include <iostream>
#include <string>
#include <vector>
#include "GraphVertices.hpp"

#define TEST cout << "TEST" << endl;
#define LINE cout << "---------------------------" << endl;

using namespace std;

class fileHandler {
    private:
        string filename;
    public:
        vector<Vertex*> fromFile; // Public Attribute vector yang berisi Vertex soal
        fileHandler(string filename); // Konstruktor
        int inList(string name); // Mencari Vertex dengan nama name, jika tidak ditemukan dikembalikan -1
        void showFromFile(); // Method untuk menunjukkan isi vector fromFile
};

#endif