#include <iostream>
#include <string>
#include <vector>
#include <iterator>
#include "GraphVertices.hpp"
#include "fileHandler.hpp"

using namespace std;

// Fungsi untuk meng-construct tiap objek yang dibutuhkan:
// 		fileHandler (membaca file), Vertex (untuk di sort), 
// 			Graph (menyimpan Vertices dan algoritma topo sort)
void sortAndShow(string filename) {
	fileHandler f(filename);
	Graph graph = Graph();
	for (vector<Vertex*>::iterator i = f.fromFile.begin(); i != f.fromFile.end(); i++) {
		graph << (*i);
	}
	graph.topoSort();
	graph.print();
}

// Main program
int main() {
	string input;
	while (input != "exit") {
		cout << "Input soal/file yang ingin dikerjakan (tanpa '.txt') atau exit untuk keluar:" << endl;
		cin >> input;
		if (input != "exit") {
			sortAndShow(input);
		}
	}

    return 0;
}