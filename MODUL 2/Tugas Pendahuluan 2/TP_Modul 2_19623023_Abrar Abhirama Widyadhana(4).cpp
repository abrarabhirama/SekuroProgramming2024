// Nama : Abrar Abhirama Widyadhana
// Fakultas : STEI-K

#include <iostream>
using namespace std;


int jumlah(int arr[], int size) {
    int total = 0;
// hitung array 
    for (int i = 0; i < size; ++i) {total += arr[i];}
// menjulah array
    return total;
}

int main() {
    int N; cin >> N;
    int arr[N];
    for (int i = 0; i < N; ++i) {cin >> arr[i];}
    cout << jumlah(arr, N) << endl;
// ouput
    return 0;
}
