#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int findMedian(vector<int> arr) {
    vector<int> a = arr;
    sort(a.begin(),a.end());
    int n = a.size();
    return a[n /2];
}

int main() {
    cout << findMedian({0,1,2,4,6,5,3}) << endl;
    return 0;
}