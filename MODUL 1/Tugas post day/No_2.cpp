// Nama : Abrar Abhirama Widyadhana
// Nim  : 19623023
// Fakultas : STEI-K

#include <iostream>
using namespace std;

int main() {
    int N;
    cout << "Jumlah bilangan : ";
    cin >> N;
    // Harus lebih dari 0
     if (N <= 0) {
        cout << "Jumlah bilangan harus lebih dari 0.\n";
        return 1;
    }

    float total = 0, bilangan;
    for (int i = 1; i <= N; ++i) {
        cout << "Bilangan " << i << " : ";
        cin >> bilangan;
        total += bilangan;
    }

    float rata_rata = total / N;
    cout << "RATA-RATA : " << fixed << rata_rata << endl;

    return 0;
}


