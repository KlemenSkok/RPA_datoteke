#include <iostream>
#include <fstream>

using namespace std;

int main() {

    ofstream dat("stevila.dat");
    
    if(dat.is_open()) {
        for(int i = 1; i <= 10; i++) {
            dat << i*4 << endl;
        }
        dat.close();
    }
    else {
        cout << "Napaka pri odpiranju datoteke!" << endl;
    }

    return 0;
}