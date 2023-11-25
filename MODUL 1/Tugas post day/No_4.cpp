// Nama : Abrar Abhirama Widyadhana
// Nim  : 19623023
// Fakultas : STEI-K

#include <iostream>
using namespace std;

int main() {
    int tahun;
    cout << "Masukkan tahun: ";
    cin >> tahun;
    if ((tahun % 400 == 0) || ((tahun % 100 != 0) && (tahun % 4 == 0))) {
        cout << tahun << " adalah tahun kabisat." << endl;
    } else {
        cout << tahun << " bukan tahun kabisat." << endl;
    }

    return 0;
}