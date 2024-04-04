#include <iostream>
#include <fstream>
#include <vector>
#include <string>

using namespace std;

vector<string> parse(string s) {
    vector<string> v;
    string word;
    for(int i = 0; i < s.size(); i++) {
        if(s[i] == ' ') {
            v.push_back(word);
            word.clear();
        }
        else {
            word += s[i];
        }
    }
    v.push_back(word);
    
    return v;
}

// KOPIRAJ besedilo.txt novobesedilo.txt

int main() {

    string vnos;
    getline(cin, vnos);

    vector<string> command = parse(vnos);

    if(command.size() == 3 && command[0] == "KOPIRAJ") {
        ifstream stara(command[1]);

        if(stara.is_open()) {
            ofstream nova(command[2]);
            char c;
            while(stara >> noskipws >> c) {
                if(c >= 'a' && c <= 'z') {
                    c -= 32;
                }
                nova << c;
            }
            nova.close();
            stara.close();
        }
        else {
            cout << "Napaka pri odpiranju datoteke: " << command[1] << endl;
        }
    }
    else {
        cout << "Napaka pri vnosu\n";
    }

    return 0;
}