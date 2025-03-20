#include<iostream>
#include<vector>

using namespace std;

int legoBlocks(int n, int m) {
    
    vector<long long> arr = {1};
    long long Mod = 1000000007;
    for (int i = 1; i<=m; i++) {
        arr.push_back(0);
        for (int j = 1; j<=4; j++) {
            if (i-j>-1) {
                arr[i] = (arr[i] + arr[i-j]) % Mod;
            }
        }
    }
    
    vector<long long> block = {1};
    for (int i = 1; i<=m; i++) {
        block.push_back(arr[i]);
        for (int j = 1; j<n; j++) {
            block[i] = (block[i] * arr[i]) % Mod;
        }
    }
    
    vector<long long> invalid = {};
    for (int i = 0; i<=m; i++) {
        invalid.push_back(0);
        for (int j = 1;j<i;j++) {
            invalid[i] = (invalid[i] + (block[j]-invalid[j])*block[i-j]+ Mod) % Mod;
        }
    }
    
    return (block[m]-invalid[m] + Mod) % Mod;
    
}

int main() {
    cout << legoBlocks(1,4) << endl;
    return 0;
}
