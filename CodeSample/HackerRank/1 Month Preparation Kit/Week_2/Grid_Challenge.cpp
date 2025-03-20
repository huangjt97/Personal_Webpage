#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
using namespace std;

string gridChallenge(vector<string> grid) {
    vector<string> temp_grid = grid;
    int n = grid.size();
    int m = grid[0].size();

    for (int i = 0; i < n; i++) {
        sort(temp_grid[i].begin(),temp_grid[i].end());
    }

    for (int j = 0; j < m; j++) {
        for (int i = 1; i < n; i++) {
            if (temp_grid[i][j]<temp_grid[i-1][j]) {
                return "NO";
            }
        }
    }
    return "YES";
}

int main() {
    cout << gridChallenge({"kc","iu"}) << endl;
    //cout << gridChallenge({"ebacd","fghij","olmkn","trpqs","xywuv"}) << endl;
    return 0;
}