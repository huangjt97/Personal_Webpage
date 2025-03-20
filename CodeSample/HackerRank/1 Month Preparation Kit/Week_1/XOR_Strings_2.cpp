#include<iostream>
#include<vector>
using namespace std;

string strings_xor(string s, string t) {
    int n = s.size();
    string answer = "";
    for (int i = 0; i < n; i++) {
        answer += char( (s[i] != t[i]) + int('0'));
    }
    return answer;
}

int main() {
    cout << strings_xor("10101", "00101") << endl;
    return 0;
}