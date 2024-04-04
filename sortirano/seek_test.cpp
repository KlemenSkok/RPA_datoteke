#include <iostream>
#include <fstream>
#include <cstring>

#include "vaje_datoteke.h"

using namespace std;

// poveca starost za 1
void update(string file_name, struct Oseba a) {

    fstream f(file_name, ios::binary | ios::in | ios::out);
    struct Oseba b;

    if(f.is_open()) {
        while(f.read((char*) &b, sizeof(b))) {
            if(enako(a, b)) {
                f.seekp(-sizeof(b), ios::cur);
                b.starost++;
                f.write((char*) &b, sizeof(b));
                cout << "update uspesen\n";
                break;
            }
            f.seekp(sizeof(b), ios::cur);
        }
        f.close();
    }
    else {
        cout << "Tezava pri odpiranju\n";
    }
}

int main() {

    struct Oseba a;
    napolni_osebo(a);

    update("dijaki3.bin", a);


    return 0;
}