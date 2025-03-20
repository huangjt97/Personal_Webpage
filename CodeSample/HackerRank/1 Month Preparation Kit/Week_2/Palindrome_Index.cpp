#include<iostream>
using namespace std;

bool check(string s) {
    int n = s.size();
    for (int i = 0; i < n/2; i++ ) {
        if (s[i] != s[n-1-i]) {
            return false;
        }
    }
    return true;
}

int palindromeIndex(string s) {
    if (check(s)) {
        return -1;
    }

    int i = 0;
    int n = s.size();
    int j = n-1;
    while (s[i] == s[j]) {
        i += 1;
        j -= 1;
        if (i>j) {
            break;
        }
    }

    string temp_s = "";
    if (i>0) {
        temp_s = s.substr(0,i);
    }
    temp_s = temp_s + s.substr(i+1,n-i-1);

    if (check(temp_s)) {
        return i;
    }
    temp_s = s.substr(0,j);
    if (j<n-1) {
        temp_s = temp_s + s.substr(j+1,n-j-1);
    }

    if (check(temp_s)) {
        return j;
    }

    return -1;
}

int main() {
    cout << palindromeIndex("bacbab") << endl;
    return 0;
}