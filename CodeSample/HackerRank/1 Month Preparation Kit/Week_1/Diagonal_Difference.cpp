#include<iostream>
#include<vector>
using namespace std;

int diagonalDifference(vector<vector<int>> arr) {

    int n = arr.size();
    int m = arr[0].size();
    int sum_A = 0;
    int sum_B = 0;
    for (int i = 0; i < n; i++) {
        sum_A += arr[i][i];
        sum_B += arr[i][m-i-1];
    }
    return abs(sum_A-sum_B);

}

int main() {
    cout << diagonalDifference({{11,2,4},{4,5,6},{10,8,-12}}) << endl;
    return 0;
}