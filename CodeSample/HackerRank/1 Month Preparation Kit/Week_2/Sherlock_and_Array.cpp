#include<iostream>
#include<vector>
#include<string>
using namespace std;

string balancedSums(vector<int> arr) {

    int n = arr.size();
    vector<int> sum_l(n+2,0);
    vector<int> sum_r(n+2,0);

    for (int i = 1; i < n; i++) {
        sum_l[i] = sum_l[i-1]+arr[i-1];
    }

    for (int i = n-2; i >= 0; i--) {
        sum_r[i] = sum_r[i+1]+arr[i+1];
    }

    for (int i = 0; i < n; i++) {
        if (sum_l[i]==sum_r[i]) {
            return "YES";
        }
    }

    return "NO";
}

int main() {

    cout << balancedSums({5,6,8,11});

    return 0;

}