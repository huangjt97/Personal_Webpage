#include<iostream>
#include<string>
using namespace std;

bool counter(long n) {
    if (n < 2) {
        return true;
    } else {
        if (n % 2 != 0) {
            long m = 1;
            while (m*2<n) {
                m = m * 2;
            }
            return !counter(n-m);
        } else {
            return !counter(n / 2);
        }
    }
}

string counterGame(long n) {
    if (!counter(n)) {
        return "Louise";
    } else {
        return "Richard";
    }
}

int main() {
    cout << counterGame(6) << endl;
    return 0;
}