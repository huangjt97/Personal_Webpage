#include<iostream>
#include<vector>
using namespace std;

vector<int> countingSort(vector<int> arr) {
    vector<int> count(100,0);
    for (int i: arr) {
        count[i] += 1;
    }
    return count;
}

int main() {
    vector<int> answer = countingSort({2,3,6,9});
    for (int a: answer) {
        cout << a << " ";
    }
    cout << endl;
    return 0;
}