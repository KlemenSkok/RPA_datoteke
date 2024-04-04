#include <iostream>
#include <fstream>
#include <cstring>
#include "vaje_datoteke.h"

#define FILE_NAME "dijaki.bin"

using namespace std;


/* void napolni_osebo(struct Oseba &a) {
    fgets(a.priimek, 20, stdin);
    cin >> a.starost;
    cin >> a.visina;
    cin.ignore();
}
 */
void izpisi_osebo(struct Oseba &a) {
    cout << a.priimek << a.starost << " " << a.visina << "\n\n";
}

void urejen_vpis(struct Oseba &a, string file_name) {
    ifstream in(file_name, ios::binary);
    
    if(in.is_open()) {

        ofstream out("dijaki-tmp.bin", ios::binary);
        struct Oseba b;
        bool je_vpisan = false;

        while(in.read((char*) &b, sizeof(b))) {
            if(!je_vpisan && strcmp(a.priimek, b.priimek) < 0) {
                out.write((char*) &a, sizeof(a));
                je_vpisan = true;
            }
            out.write((char*) &b, sizeof(b));
        }
        if(!je_vpisan) {
            out.write((char*) &a, sizeof(a));
        }

        in.close();
        out.close();

        remove(file_name.c_str());
        rename("dijaki-tmp.bin", file_name.c_str());
    }
    else {
        cout << "Delam nov file\n";
        ofstream out(file_name, ios::binary);
        out.write((char*) &a, sizeof(a));
        out.close();
    }
    
}

void  neurejen_vpis(struct Oseba &a, string file_name) {

    ofstream out(file_name, ios::binary | ios::app| ios::ate);
    out.write((char*) &a, sizeof(a));
    out.close();

}

void izpis_dat(string file_name) {
    ifstream in(file_name, ios::binary);
    if(in.is_open()) {
        struct Oseba a;
        while(in.read((char*) &a, sizeof(a))) {
            izpisi_osebo(a);
        }
        in.close();
    }
}

// nardi datoteko, jo napolni
int main() {

/*     for(int i = 0; i < 5; i++) {
        struct Oseba a;
        napolni_osebo(a);
        neurejen_vpis(a, "osebe.bin");
    } */

    izpis_dat("dijaki3.bin");


    return 0;
}