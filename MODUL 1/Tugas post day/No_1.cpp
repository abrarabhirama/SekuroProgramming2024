// Nama : Abrar Abhirama Widyadhana
// Nim  : 19623023
// Fakultas : STEI-K

#include <iostream>
using namespace std;

int main() {
    int a, b;
    cout << "Masukkan dua bilangan (a dan b dipisah spasi): ";
    cin >> a >> b;
    if (a > b) {
        swap(a, b);
    }
    for (int i = a; i <= b; ++i) {
        if (i % 2 == 0) {
            cout << i << " ";
        }
    }

    return 0;
}