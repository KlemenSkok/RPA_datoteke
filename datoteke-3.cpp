#include <iostream>
#include <fstream>

using namespace std;

int main() {

    ifstream datai;
    ofstream datao;

    datai.open("stevila.txt");
    datao.open("stevila1.txt");

    if(datai.is_open() && datao.is_open()) {
        int st;
        while(datai >> st) {
            if(st < 'a' || st > 'z') {
                datao << st << " ";
            }
        }

        datai.close();
        datao.close();
    } 
    else {
        cout << "Napaka pri odpiranju datoteke!" << endl;
    }


    return 0;
}