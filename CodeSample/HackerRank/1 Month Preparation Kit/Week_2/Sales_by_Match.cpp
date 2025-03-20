#include<iostream>
#include<vector>
using namespace std;

int sockMerchant(int n, vector<int> ar) {
    vector<int> count(101);
    for (int i : ar) {
        count[i] += 1;
    }

    int result = 0;
    for (int i : count) {
        result += i / 2;
    }

    return result;
}

int main() {
    cout << sockMerchant(9, {10,20,20,10,10,30,50,10,20}) << endl;
    return 0;
}