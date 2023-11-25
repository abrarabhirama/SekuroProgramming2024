// Nama : Abrar Abhirama Widyadhana
// Fakultas : STEI-K

#include <iostream>
using namespace std;

const float PI = 3.14159265359;

float luas(float r) {
    return PI * r * r;
}

int main() {
    std::cout << "Luas lingkaran dengan radius 3: " << luas(3) << std::endl;
    std::cout << "Luas lingkaran dengan radius 5.5: " << luas(5.5) << std::endl;

    return 0;
}