#include<iostream>
#include<vector>
using namespace std;

vector<int> dynamicArray(int n, vector<vector<int>> queries) {

    vector<vector<int>> arr(n);
    vector<int> result;
    int idx;
    int lastAnswer = 0;
    for (vector<int> q: queries) {
        if (q[0] == 1) {
            idx = ((q[1] ^ lastAnswer) % n);
            arr[idx].push_back(q[2]);
        } else {
            idx = ((q[1] ^ lastAnswer) % n);
            lastAnswer = arr[idx][q[2] % arr[idx].size()];
            result.push_back(lastAnswer);
        }
    }

    return result;
}

int main() {
    vector<int> result = dynamicArray(2,{{1,0,5},{1,1,7},{1,0,3},{2,1,0},{2,1,1}});
    for (int i: result) {
        cout << i << endl;
    }
    return 0;
}