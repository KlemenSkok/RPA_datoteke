#include <iostream>
#include <fstream>

using namespace std;

int main() {

    ofstream dat("stevile.txt", ios::app);

    if(dat.is_open()) {
        for(int i = 1; i <= 10; i++) {
            int x;
            do {
                cin >> x;
                if(x < 60 || x > 80) {
                    cout << "Napacno stevilo! Vnesi ponovno: ";
                }
            } while(x < 60 || x > 80);
            dat << x << endl;
        }
        dat.close();
    }
    else {
        cout << "Napaka pri odpiranju datoteke!" << endl;
    }


    return 0;
}