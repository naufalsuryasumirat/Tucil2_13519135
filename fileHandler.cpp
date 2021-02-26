// NIM/Nama: 13519135/Naufal Alexander Suryasumirat
// Tugas Kecil 2 STIMA (Strategi Algoritma) Algoritma Decrease and Conquer

#include <iostream>
#include <string>
#include <vector>
#include <iterator>
#include <fstream>
#include "fileHandler.hpp"
#include "GraphVertices.hpp"

using namespace std;

// Konstruktor dari class fileHandler
// Meng-assign atribut filename dan juga vector dari Vertex pointer (fromFile)
// fromFile berisi vertex yang terdapat pada persoalan dengan informasi
//      yang lengkap dari soal (sudah terisi out-edge tiap vertex)
fileHandler::fileHandler(string name) {
    this->filename = name;
    ifstream file("./test/" + this->filename + ".txt");
    string str;
    vector<string> lines;
    while (getline(file, str)) { // Membaca tiap line pada file
        // Mengambil seluruh vertex unik pada persoalan
        string vertex;
        vertex = "";
        if (str == "") {continue;} // Melewati line yang kosong pada file
        for (int i = 0; i < str.length(); i++) {
            if (str[i] == ',' || str[i] == '.') {
                Vertex* a = new Vertex(vertex);
                this->fromFile.push_back(a);
                break;
            }
            else {
                vertex.push_back(str[i]);
            }
        }
        lines.push_back(str);
    }
    for (vector<string>::iterator it = lines.begin(); it != lines.end(); it++) {
        // Mengisi tiap vertex dengan vertex-vertex yang ditujunya
        bool first = true; // indikator jika vertex yang dibaca adalah pertama
        string vertex;
        vertex = "";
        for (int i = 0; i < (*it).length(); i++) {
            if ((*it)[i] == ' ') {
                continue;
            }
            else if ((*it)[i] == ',') {
                if (first) {
                    first = false;
                }
                else {
                    int index = inList(vertex);
                    *(this->fromFile[index]) >> this->fromFile[distance(lines.begin(), it)];
                    vertex = "";
                }
            }
            else if ((*it)[i] == '.') {
                if (!first) {
                    int index = inList(vertex);
                    *(this->fromFile[index]) >> this->fromFile[distance(lines.begin(), it)];
                    vertex = "";
                    break;
                }
            }
            else {
                if (!first) {
                    vertex.push_back((*it)[i]);
                }
            }
        }
    }
}

// Mengembalikan indeks vertex yang ingin dicari pada fromFile
// Jika tidak ditemukan, dikembalikan -1
int fileHandler::inList(string name) {
    for (vector<Vertex*>::iterator i = this->fromFile.begin(); i != this->fromFile.end(); i++) {
        if ((*i)->getName() == name) {
            return distance(this->fromFile.begin(), i);
        }
    }
    return -1;
}

// Memperlihatkan info tiap vertex yang telah dibaca dari file
void fileHandler::showFromFile() {
    for (vector<Vertex*>::iterator i = this->fromFile.begin(); i != this->fromFile.end(); i++) {
        (*i)->printInfo();
    }
}