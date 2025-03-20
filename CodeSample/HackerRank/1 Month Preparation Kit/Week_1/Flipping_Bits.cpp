#include<iostream>

using namespace std;

long long flippingBits(long long n) {
    long long m = 1;
    for (int i = 0; i<32; i++) {
        m = m << 1;
    }
    return m-n-1;
}

int main() {
    cout << flippingBits(2147483647) << endl;
    cout << flippingBits(1) << endl;
    cout << flippingBits(0) << endl;
    return 0;
}