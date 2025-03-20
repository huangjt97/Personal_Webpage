#include<iostream>
#include<string>
#include<vector>

using namespace std;

string isValid(string s) {
    vector<int> count(26);
    for (char c : s) {
        count[int(c)-int('a')] += 1;
    }

    vector<int> count_2(100001);
    for (int i:count) {
        count_2[i] += 1;
    }

    vector<int> count_3;
    vector<int> num;
    for (int i = 1; i < count_2.size(); i++) {
        if (count_2[i]>0) {
            count_3.push_back(count_2[i]);
            num.push_back(i);
        }
    }

    cout << endl;
    for (int i:count_3) {
        cout << i << " ";
    }
    cout << endl;

    if (count_3.size()>1) {
        if (count_3.size() == 2) {
            if ((count_3[0] == 1) && (num[0] == 1)) {
                return "YES";
            };
            if ((count_3[1] == 1) && (num[1] == num[0]+1)) {
                return "YES";
            }
            return "NO";
        }
        return "NO";
    } else {
        return "YES";
    }
}

int main() {
    cout << isValid("aaabbbc") << endl;
    return 0;
}