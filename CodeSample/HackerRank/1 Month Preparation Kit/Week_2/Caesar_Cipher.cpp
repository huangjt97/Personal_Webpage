#include<iostream>
#include<string>
using namespace std;

string caesarCipher(string s, int k) {
    string result = "";
    for (char c: s) {
        if ((c>='a') && (c<='z')) {
            result += char((int(c)-int('a')+k) % 26 + int('a'));
        } else if ((c>='A') && (c<='Z')) {
            result += char((int(c)-int('A')+k) % 26 + int('A'));
        } else {
            result += c;
        }
    }

    return result;
}

int main() {
    cout << caesarCipher("middle-Outz", 2) << endl;
    return 0;
}