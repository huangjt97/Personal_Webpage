#include<iostream>
#include<vector>

using namespace std;
int lonelyinteger(vector<int> a) {
    vector<bool> check(101,false);
    for (int i: a) {
        check[i] = !check[i];
    }
    for (int i = 0; i < 100; i++) {
        if (check[i]) {
            return i;
        }
    }

    return -1;
}

int main() {
    cout << lonelyinteger({1,2,3,4,3,2,1}) << endl;
    return 0;
}