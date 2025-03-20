#include<iostream>
#include<string>
#include<vector>

using namespace std;

string isBalanced(string s) {
    vector<int> arr = {};
    int n = s.length();
    for (int i = 0; i<n; i++) {
        switch(s[i]) {
            case '(':
                arr.push_back(1);
                break;
            case '[':
                arr.push_back(2);
                break;
            case '{':
                arr.push_back(3);
                break;
            case ')':
                if (arr.size()<1) {
                    return "NO";
                }
                if (arr.back() != 1) {
                    return "NO";
                } else {
                    arr.pop_back();
                }
                break;
            case ']':
                if (arr.size()<1) {
                    return "NO";
                }
                if (arr.back() != 2) {
                    return "NO";
                } else {
                    arr.pop_back();
                }
                break;
            case '}':
                if (arr.size()<1) {
                    return "NO";
                }
                if (arr.back() != 3) {
                    return "NO";
                } else {
                    arr.pop_back();
                }
                break;
        }

    }
    if (arr.size()>0) {
        return "NO";
    } else {
        return "YES";
    }
}

int main() {
    int t;
    string s;
    cin >> t;
    for (int i = 0; i<t; i++) {
        cin >> s;
        cout << isBalanced(s) << endl;
    }

    return 0;
}