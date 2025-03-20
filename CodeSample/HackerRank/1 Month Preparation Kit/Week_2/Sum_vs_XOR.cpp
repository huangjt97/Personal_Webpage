#include<iostream>
using namespace std;

long sumXor(long n) {
    long answer = 1;
    while (n>1) {
        if (n % 2 == 0) {
            answer = answer * 2;
        }
        n = n / 2;
    }
    return answer;
}

int main() {
    cout << sumXor(4) << endl;
    return 0;
}