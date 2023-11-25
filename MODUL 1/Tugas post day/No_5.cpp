// Nama : Abrar Abhirama Widyadhana
// Nim  : 19623023
// Fakultas : STEI-K

#include <iostream>
using namespace std;

bool isPrime(int n) {
    if (n <= 1) {
        return false;
    }
    for (int i = 2; i * i <= n; ++i) {
        if (n % i == 0) {
            return false;
        }
    }
    return true;
}
int main() {
    int angka;
    cout << "Masukkan sebuah integer: ";
    cin >> angka;
    if (isPrime(angka)) {
        cout << angka << " adalah bilangan prima." << endl;
    } else {
        cout << angka << " bukan bilangan prima." << endl;
    }

    return 0;
}