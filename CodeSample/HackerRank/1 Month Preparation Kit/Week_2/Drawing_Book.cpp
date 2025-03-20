#include<iostream>
using namespace std;

int pageCount(int n, int p) {
    if (n % 2 == 1) {
        return min(p/2,(n-p)/2);
    } else {
        return min(p/2,(n-p+1)/2);
    }
}


int main() {
    cout << pageCount(6,5) << endl;
    return 0;
}