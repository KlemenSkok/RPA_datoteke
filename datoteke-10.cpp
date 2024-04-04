#include <iostream>
#include <fstream>

using namespace std;

int main() {

    ifstream dat("besedilo.txt");
    char vnos;
    int n = 0;
    cout << "Vnesite znak za iskanje: ";
    cin >> vnos;

    if(dat.is_open()) {
        char c;
        while(dat >> c) {
            if(c == vnos) {
                n++;
            }
        }
    }
    else {
        cout << "Napaka pri odpiranju datoteke!" << endl;
    }

    cout << "Stevilo najdenih znakov \'" << vnos << "\':" << n << endl;

    return 0;
}