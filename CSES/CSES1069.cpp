// CSES 1069 Longest repetition
// TODO make faster - currently TLEs but is functionally correct

#include <iostream>
#include <string>
int main() {
    std::string seq;
    std::getline(std::cin, seq);
    int ws = 1;
    std::string c;
    bool inc;
    for (int i = 0; i < seq.length(); i += (!inc)){
        inc = false;
        c = seq.substr(i, 1);
        for (int j = 1; j <= ws; j++) {
            inc = (c == seq.substr(i+j, 1));
            if (!inc) break;
        }
        ws = ws + inc;
    }
    std::cout << ws;
}
