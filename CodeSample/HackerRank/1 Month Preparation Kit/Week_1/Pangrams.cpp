#include<iostream>
#include<string>
#include <vector>

using namespace std;

string pangrams(string s) {
    vector<bool> letterMap(26,false);
    int val;
    for (char c: s) {
        if ((c>='a') && (c<='z')) {
            val = int(c) - int('a');
        } else if ((c>='A') && (c<='Z')) {
            val = int(c) - int('A');
        }
        letterMap[val] = true;
    }
    
    for (int i = 0; i < 26; i++) {
        if (!letterMap[i]) {
            return "not pangram";
        }
    }

    return "pangram";
}

int main() {
    cout << pangrams("We promptly judged antique ivory buckles for the next prize") << endl;
    return 0;
}