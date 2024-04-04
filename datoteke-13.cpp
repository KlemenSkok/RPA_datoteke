#include <iostream>
#include <fstream>

using namespace std;

int main() {

    ifstream dat;

    cout << "Vnesi ime datoteke: ";
    string ime;
    cin >> ime;

    dat.open(ime);
    if(dat.is_open()) {
        int cnt = 0;
        char c;
        while(dat >> c)
            if(c >= 'a' && c <= 'z') 
                cnt++;

        cout << "Stevilo malih crk: " << cnt << endl;
        dat.close();
    }
    else {
        cout << "Napaka pri odpiranju datoteke: " << ime << endl;
    }

    return 0;
}