#include<iostream>
#include<vector>
#include<string>
using namespace std;

int anagram(string s) {

    int n = s.size();
    if (n % 2 != 0) {
        return -1;
    }

    vector<int> count_l(26,0);
    vector<int> count_r(26,0);
    string sl = s.substr(0,n/2);
    string sr = s.substr(n/2,n/2);
    for (char c: sl) {
        count_l[int(c)-int('a')] += 1;
    }
    for (char c: sr) {
        count_r[int(c)-int('a')] += 1;
    }

    int answer = 0;
    for (int i = 0; i < 26; i++) {
        answer += abs(count_l[i]-count_r[i]);
    }

    return answer / 2;
}


int main() {
    cout << anagram("aaabbb") << endl;
    cout << anagram("ab") << endl;
    cout << anagram("abc") << endl;
    cout << anagram("mnop") << endl;
    cout << anagram("xyyx") << endl;
    cout << anagram("xaxbbbxx") << endl;
    return 0;
}