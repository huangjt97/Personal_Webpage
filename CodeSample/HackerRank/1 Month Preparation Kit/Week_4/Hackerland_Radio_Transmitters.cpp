#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

int hackerlandRadioTransmitters(vector<int> x, int k) {
    sort(x.begin(),x.end());
    vector<vector<int>> dp = {};
    int n = x.size();
    int j = 0;
    dp.push_back({1,1});
    for (int i = 1; i<n; i++) {
        dp.push_back({i+1, dp[i-1][0]+1});
        while (x[i]-x[j]>k) {
            j ++;
        }
        dp[i][0] = min(dp[i][0],dp[j][1]);
        if (j>0) {
            dp[i][1] = min(dp[i][1],min(dp[j-1][0]+1,dp[j-1][1]+1));
        } else {
            dp[i][1] = 1;
        }
    }
    
    return min(dp[n-1][0],dp[n-1][1]);
}