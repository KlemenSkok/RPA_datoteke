#include <iostream>
#include <fstream>
#include <cstring>

#include "vaje_datoteke.h"

using namespace std;


bool enako(struct Oseba a, struct Oseba b) {
    return (
        !strcmp(a.priimek, b.priimek) &&
        a.starost == b.starost && 
        a.visina == b.visina
    );
}

void napolni_osebo(struct Oseba &a) {
    fgets(a.priimek, 20, stdin);
    cin >> a.starost;
    cin >> a.visina;
    cin.ignore();
}

void uredi(string file_name) {

}

void brisi(string file_name, struct Oseba a) {
    ifstream in(file_name, ios::binary);
    if(in.is_open()) {
        ofstream out("tmp.bin", ios::binary);
        struct Oseba b;
        while(in.read((char*) &b, sizeof(b))) {
            if(!enako(a, b)) {
                out.write((char*) &b, sizeof(b));
            }
            else {
                cout << "brisem\n";
            }
        }
        in.close();
        out.close();
        remove(file_name.c_str());
        rename("tmp.bin", file_name.c_str());
    }
    else {
        cout << "Napaka pri odpiranju datoteke " << file_name << endl;
    }
}

int st_structov(string file_name) {
    fstream f(file_name, ios::binary | ios::in | ios::out | ios::ate);
    if(f.is_open()) {
        return f.tellg() / sizeof(struct Oseba);
    }
    return -1;
}

int main() {

    /* struct Oseba a;
    napolni_osebo(a);
    brisi("dijaki2.bin", a);
 */

    cout << "V datoteki je " << st_structov("dijaki2.bin") << " dijakov\n";

    return 0;
}