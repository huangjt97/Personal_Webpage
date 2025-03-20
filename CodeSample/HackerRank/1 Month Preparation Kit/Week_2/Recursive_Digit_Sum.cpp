#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int superDigit(string n, int k) {

    long long sum = 0;
    for (char c: n) {
        sum += (int(c)-int('0'));
    }

    sum = sum * k;

    long long temp, temp_sum;

    while (sum>9) {
        temp = sum;
        temp_sum = 0;
        while (temp>0) {
            temp_sum += temp % 10;
            temp = temp / 10;
        }

        sum = temp_sum;

    }

    return sum;

}

int main() {
    cout << superDigit("9875", 4) << endl;
    return 0;
}