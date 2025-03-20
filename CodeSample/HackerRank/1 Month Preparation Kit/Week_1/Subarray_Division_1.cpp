#include<iostream>
#include<vector>
using namespace std;

int birthday(vector<int> s, int d, int m) {
    int n = s.size();
    int answer = 0;
    vector<int> sum_s(n+1,0);
    for (int i = 1; i <= n; i++) {
        sum_s[i] = sum_s[i-1] + s[i-1];
        if (sum_s[i]-sum_s[i-m] == d) {
            answer += 1;
        }
    }

    return answer;
}

int main() {
    cout << birthday({1,2,1,3,2},3,2) << endl;
    return 0;
}