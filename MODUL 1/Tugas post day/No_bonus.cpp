// Nama : Abrar Abhirama Widyadhana
// Nim  : 19623023
// Fakultas : STEI-K

#include <iostream>
using namespace std;

int main() {
    int N;
    cout << "Masukkan N: ";
    cin >> N;

    int counter = 0;

    for (int i = 1; i <= N; ++i) {
        for (int k = 1; k < i; ++k) {cout << "  ";}

        for (int j = 0; j < i; ++j) {
            cout << counter;
            counter = (counter + 1) % 10;
            if (j < i - 1) {cout << " ";}
        }
        cout << endl;
    }

    return 0;
}