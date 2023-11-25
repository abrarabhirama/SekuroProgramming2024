// Nama : Abrar Abhirama Widyadhana
// Fakultas : STEI-K

#include <iostream>
using namespace std;

int main() {
    const int size = 10;
    int arr[size];
    int arr2[size];
    int result[size];

std::cout << "Masukkan nilai untuk array pertama (10 angka dipisahkan spasi): ";
    for (int i = 0; i < size; ++i) {
        std::cin >> arr[i];
    }

    std::cout << "Masukkan nilai untuk array kedua (10 angka dipisahkan spasi): ";
    for (int i = 0; i < size; ++i) {
        std::cin >> arr2[i];
    }

    for (int i = 0; i < size; ++i) {
        result[i] = arr[i] + arr2[i];
    }

    std::cout << "Hasil penjumlahan array:\n";
    for (int i = 0; i < size; ++i) {
        std::cout << result[i] << " ";
    }

    return 0;
}