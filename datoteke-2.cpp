#include <iostream>
#include <fstream>

using namespace std;

int main() {
    ifstream datai;
    datai.open("stevila.txt");

    int st;
    if(datai.is_open()) {
        while(datai >> st) {
            if(st >= 'A' && st <= 'Z')
                cout << (char)st << " ";
        }
        datai.close();
    }

    return 0;
}