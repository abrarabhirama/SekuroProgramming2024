// Nama : Abrar Abhirama Widyadhana
// Fakultas : STEI-K

#include <iostream>
using namespace std;

int main(){
    char pesawat;
    cout<< "Masukkan jenis pesawat : ";
    cin >> pesawat;

    while(pesawat != 'o'){
        if(pesawat == 'a'){
            for(int i = 3; i > 0; i--){
                cout << i << "\n";
            }
            cout << "PESAWAT A BEERANGKAT\n";
        }
        else if(pesawat == 'b'){
            for(int i = 5; i > 0; i--){
                cout << i << "\n";
            }
            cout << "PESAWAT B BERANGKAT\n";
        }
        else{
            cout << "INPUT TIDAK VALID\n";
        }
        cout<< "Masukkan jenis pesawat : ";
        cin >> pesawat;
    }

    cout << "PENERBANGAN DITUTUP ";
    

    
    return 0;
}

    