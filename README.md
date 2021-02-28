# Tucil2_13519135

by Naufal Alexander Suryasumirat - 13519135 (Author)

## Algoritma Decrease and Conquer

### Topological Sort

Topological Sort menggunakan pendekatan decrease and conquer varian decrease by a constant. Topological Sort yang kali ini diimplementasikan bertujuan untuk mengurutkan urutan pengambilan mata kuliah. Secara umum, setelah dibuat instansi-instansi dari kelas Vertex beserta dengan tiap edge yang dimiliki tiap vertexnya, simpul-simpul tersebut kemudian dimasukkan ke dalam suatu instansi dari kelas Graph.
Kemudian digunakan metode topoSort yang bekerja dengan mencari simpul yang memiliki in-degree berjumlah 0, kemudian menambahkan simpul tersebut ke dalam atribut sortedVertex pada kelas Graph. Setelah ditambahkan, tiap edge yang mengarah keluar dari simpul tersebut dihilangkan, akibatnya in-degree dari simpul-simpul yang terhubung berkurang dan simpul yang ditambahkan ke sortedVertex tersebut pun dihilangkan setelah iterasi tersebut dari permasalahan dan didapat permasalahan dalam bentuk yang lebih kecil untuk diselesaikan.
Proses tersebut dijalankan sampai ditemukan solusi atau ditemukan siklus, lalu solusi diperlihatkan.

### Requirement

g++

### Cara menggunakan program

Gunakan program (.exe) pada folder bin yang bernamakan NolerTopoSort.exe atau kompilasi program dengan menuliskan g++ -o NolerTopoSort 13519135-main.cpp 13519135-GraphVertices.cpp 13519135-fileHandler.cpp pada CMD/terminal dalam directory src dan menjalankan hasil kompilasi tersebut.
