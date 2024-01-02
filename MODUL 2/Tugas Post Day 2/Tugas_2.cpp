// Nama : Abrar Abhirama Widyadhana
// Fakultas : STEI-K

#include <iostream>
#include <vector>
using namespace std;

// Struktur untuk history
struct History {
    int x;
    int y;
};

// Fungsi untuk melakukan undo
void undo(vector<History> &history, int &x, int &y, int matrix[][11]) {
    if (history.size() > 1) {
        history.pop_back();
        x = history.back().x;
        y = history.back().y;
        matrix[x][y] = 0; 
    } else {
        cout << "Undo tidak dapat dilakukan. Sudah berada di history awal." << endl;
    }
}

// Fungsi untuk melakukan redo
void redo(vector<History> &history, int &x, int &y, int matrix[][11]) {
    if (!history.empty()) {
        x = history.back().x;
        y = history.back().y;
        matrix[x][y] = 0;
        history.pop_back();
    } else {
        cout << "Redo tidak dapat dilakukan. Tidak ada yang diundo." << endl;
    }
}

// Fungsi untuk memindahkan angka 0 di dalam matriks
void gerak(int matrix[][11], int &x, int &y, int moveX, int moveY, vector<History> &history) {
    if (x + moveX >= 0 && x + moveX < 11 && y + moveY >= 0 && y + moveY < 11) {
        History posBefore = {x, y};
        history.push_back(posBefore);
        swap(matrix[x][y], matrix[x - moveX][y + moveY]);
        x = x - moveX;
        y = y + moveY;
    } else {
        cout << "Perpindahan diluar batas matriks!" << endl;
    }
}

// PROGRAM UTAMA
int main() {
    int n = 11;
    int matrix[11][11];
    int x, y;
    vector<History> history; // Histori pergerakan

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            matrix[i][j] = 1;
        }
    }
    int mid = (n + 1) / 2;
    x = mid - 1;
    y = mid - 1;
    matrix[x][y] = 0;

    do {
        cout << "Matriks:" << endl;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                cout << matrix[i][j] << " ";
            }
            cout << endl;
        }
        cout << "Posisi Drone: (" << x << ", " << y << ")" << endl;

        // Menampilkan menu
        cout << "Menu:\n";
        cout << "1. Gerak\n";
        cout << "2. Undo\n";
        cout << "3. Redo\n";
        cout << "0. Keluar\n";
        cout << "Pilih: ";

        int choice;
        cin >> choice;

        switch (choice) {
            case 1: {
                int moveX, moveY;
                cout << "Masukkan perpindahan (moveX moveY): ";
                cin >> moveX >> moveY;
                gerak(matrix, x, y, moveY, moveX, history);
                break;
            }
            case 2: {
                undo(history, x, y, matrix);
                break;
            }
            case 3: {
                redo(history, x, y, matrix);
                break;
            }
            case 0: {
                cout << "Program berakhir." << endl;
                return 0;
            }
            default:
                cout << "Pilihan tidak valid." << endl;
        }

    } while (true);

    return 0;
}
