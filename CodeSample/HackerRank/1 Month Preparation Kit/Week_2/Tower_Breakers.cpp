#include<iostream>
using namespace std;

int towerBreakers(int n, int m) {

    if (m == 1) {
        return 2;
    }
    if (n % 2 ==0) {
            return 2;
    } else {
        return 1;
    }
}

int main() {
    cout << towerBreakers(2,2) << endl;
    cout << towerBreakers(1,4) << endl;
    return 0;
}