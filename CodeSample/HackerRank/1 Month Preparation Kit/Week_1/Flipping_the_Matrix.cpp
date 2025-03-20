#include<iostream>
#include<vector>

using namespace std;

int flippingMatrix(vector<vector<int>> matrix) {
    int n = matrix.size();
    int half_n = n/2;
    int result = 0;
    for (int i = 0; i < half_n; i++) {
        for (int j = 0; j < half_n; j++) {
            result += max(max(max(matrix[i][j],matrix[i][n-j-1]),matrix[n-i-1][j]),matrix[n-i-1][n-j-1]);
        }
    }

    return result;
}


int main() {
    cout << flippingMatrix({{1,2},{3,4}}) << endl;
    return 0;
}