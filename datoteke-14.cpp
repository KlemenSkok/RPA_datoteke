#include <iostream>
#include <fstream>
#include <cstring>

using namespace std;

struct Oseba {
    char ime[21];
    char priimek[31];
    int starost;
    float visina;
};

void brisi_strukturo(struct Oseba a, string ime_dat) {
    ifstream stara;
    stara.open(ime_dat, ios::binary);
    if(stara.is_open()) {
        struct Oseba tmp;
        ofstream nova("nova.bin", ios::binary);
        while(stara.read((char*) &tmp, sizeof(tmp))) {
            if(strcmp(tmp.ime, a.ime) || strcmp(tmp.priimek, a.priimek) || tmp.starost != a.starost || tmp.visina != a.visina) {
                nova.write((char*) &tmp, sizeof(tmp));
            }
        }
        stara.close();
        nova.close();
        remove(ime_dat.c_str());
        rename("nova.bin", ime_dat.c_str());
    }
    else {
        cout << "Napaka pri odpiranju datoteke: " << ime_dat << endl;
    }
}

void removeNewline(char* str) {
    // Remove the newline character if present
    char* newlinePos = strchr(str, '\n');
    if (newlinePos != nullptr) {
        *newlinePos = '\0'; // Replace newline with null terminator
    }
}

void vnos_osebe(Oseba& a) {
    cout << "Vnesi ime: ";
    cin.getline(a.ime, 21);
    cout << "Vnesi priimek: ";
    cin.getline(a.priimek, 31);
    cout << "Vnesi starost: ";
    cin >> a.starost;
    cout << "Vnesi visino: ";
    cin >> a.visina;
    cin.ignore(); // Clear input buffer
}


void izpis_osebe(struct Oseba a) {
    cout << a.ime << " " << a.priimek << endl << a.starost << " " << a.visina << endl << endl;
}

void beri_bin(string ime_dat) {
    ifstream dat;
    dat.open(ime_dat, ios::binary);
    if(dat.is_open()) {
        struct Oseba tmp;
        while(dat.read((char*) &tmp, sizeof(tmp))) {
            izpis_osebe(tmp);
        }
        dat.close();
    }
    else {
        cout << "Napaka pri odpiranju datoteke: " << ime_dat << endl;
    }
}

int main() {

    struct Oseba a;
    /* 
    ofstream out("oseba.bin", ios::binary);

    for(int i = 0; i < 3; i++) {
        cout << "\nVnesi podatke:\n";
        vnos_osebe(a);
        out.write((char*) &a, sizeof(a));
    }
*/
    cout << "Vnesi osebo za izbris:\n";
    vnos_osebe(a);

    //beri_bin("oseba.bin");


    return 0;
}