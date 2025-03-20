#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

vector<int> maxSubarray(vector<int> arr) {
    vector<int> sum = {arr[0]};
    int min_sum = min(arr[0],0);

    int answer_1 = arr[0];
    int answer_2 = arr[0];
    for (int i = 1; i<arr.size(); i++) {
        sum.push_back(sum.back() + arr[i]);
        answer_1 = max(answer_1,arr[i]);
        if (arr[i]>0) {
            answer_1 = max(answer_1, sum.back()-min_sum);
        }
        min_sum = min(sum.back(),min_sum);

        answer_2 = max(answer_2, max(answer_2+arr[i],arr[i]));
    }

    return {answer_1, answer_2};
}

int main() {
    int q,n,k;
    cin >> q;
    vector<int> answer;
    for (int i =0; i<q; i++) {
        cin >> n;
        vector<int> a = {};
        for (int j =0 ;j<n;j++) {
            cin >> k;
            a.push_back(k);
        }
        answer = maxSubarray(a);
        cout << answer[0] << ' ' << answer[1] << endl;
    }
    return 0;
}