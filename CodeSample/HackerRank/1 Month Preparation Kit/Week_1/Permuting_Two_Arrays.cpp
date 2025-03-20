#include<iostream>
#include<vector>
#include <algorithm>

using namespace std;

string twoArrays(int k, vector<int> A, vector<int> B) {
    vector<int> sorted_A = A;
    vector<int> sorted_B = B;
    int n = sorted_A.size();
    sort(sorted_A.begin(),sorted_A.end());
    sort(sorted_B.begin(),sorted_B.end(),greater<int>());
    for (int i = 0; i < n; i++) {
        if (sorted_A[i] + sorted_B[i] < k) {
            return "NO";
        }
    }
    return "YES";
}

int main() {
    cout << twoArrays(10,{2,1,3},{7,8,9}) << endl;
    cout << twoArrays(5,{1,2,2,1},{3,3,3,4}) << endl;
    return 0;
}