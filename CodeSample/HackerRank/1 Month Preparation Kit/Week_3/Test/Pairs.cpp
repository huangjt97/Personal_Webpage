#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int pairs(int k, vector<int> arr) {
    sort(arr.begin(),arr.end());
    int n = arr.size();
    int answer = 0;
    int l,r,target,mid;
    for (int i = 0; i<n-1; i++) {
        l = i+1;
        r = n-1;
        target = arr[i]+k;
        while (l<r) {
            mid = (l+r) / 2;
            if (target<=arr[mid]) {
                r = mid;
            } else {
                l = mid+1;
            }
        }
        if (arr[l] == target) {
            answer += 1;
        }
    }
    return answer;
}

int main() {
    cout << pairs(1,{1, 1, 2, 2, 3, 3}) << endl;
}