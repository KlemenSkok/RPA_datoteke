#include <iostream>
#include <fstream>
#include <ctime>

using namespace std;

int main() {
    srand(time(NULL));

    ofstream datao;
    datao.open("stevila.txt");

    if(datao.is_open()) {
        for(int i = 0; i < 30; i++) {
            datao << rand() % 113 + 15 << " ";
        }
        datao.close();
    } 
    else {
        cout << "Napaka pri odpiranju datoteke!" << endl;
    }
 

    return 0;
}