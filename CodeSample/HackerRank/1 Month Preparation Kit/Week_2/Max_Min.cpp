#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int maxMin(int k, vector<int> arr) {
    vector<int> a = arr;
    sort(a.begin(),a.end());
    int n = a.size();
    int result = a[n-1];
    for (int i = 0; i <= n-k; i++) {
        result = min(result,a[i+k-1]-a[i]);
    }

    return result;
}

int main() {
    cout << maxMin(2,{1,4,7,2}) << endl;
    cout << maxMin(4, {1,2,3,4,10,20,30,40,100,200}) << endl;
    return 0;
}