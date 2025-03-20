#include<iostream>
#include<vector>
using namespace std;

int gcd(int x, int y) {
    if (x % y == 0) {
        return y;
    } else {
        return gcd(y, x % y);
    }
}

long long getTotalX(vector<int> a, vector<int> b) {
    int n = a.size();
    int m = b.size();
    long long a_lcm = a[0];
    for (int i = 1; i < n; i++) {
        a_lcm = a_lcm*a[i] / gcd(a_lcm,a[i]);
    }

    long long b_gcd = b[0];
    for (int i = 1; i < m; i++) {
        b_gcd = gcd(b_gcd,b[i]);
    }

    if (b_gcd % a_lcm != 0) {
        return 0;
    } else {

        long long t = b_gcd / a_lcm;
        
        if (t == 1) {
            return 1;
        }

        vector<int> prime;
        vector<int> prime_count;

        int j = 2;
        int k = -1;
        while ((t>1) && (j*j<=t)) {
            if (t % j == 0) {
                k += 1;
                prime.push_back(j);
                prime_count.push_back(0);
                while (t % j == 0) {
                    t = t / j;
                    prime_count[k] += 1;
                }
            }
            j += 1;
        }

        if (t>1) {
                k += 1;
                prime.push_back(t);
                prime_count.push_back(1);
        }

        long long answer = prime_count[0]+1;
        for (int i = 1; i <= k; i++) {
            answer = answer * (prime_count[i]+1);
        } 
        return answer;
    }

}

int main() {
    cout << getTotalX({3},{81}) << endl;
    return 0;
}