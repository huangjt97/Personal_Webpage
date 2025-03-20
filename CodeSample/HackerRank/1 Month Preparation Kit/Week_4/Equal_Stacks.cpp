#include<iostream>
#include<vector>
#include<numeric>
using namespace std;

int equalStacks(vector<int> h1, vector<int> h2, vector<int> h3) {
    vector<int> a = h1;
    vector<int> b = h2;
    vector<int> c = h3;
    a.push_back(0);
    b.push_back(0);
    c.push_back(0);
    int sum_1 = accumulate(h1.begin(),h1.end(),0);
    int sum_2 = accumulate(h2.begin(),h2.end(),0);
    int sum_3 = accumulate(h3.begin(),h3.end(),0);
    int i = 0,j = 0,k = 0;
    while ((sum_1 != sum_2) || (sum_2!= sum_3)) {
        if ((sum_1>=sum_2) && (sum_1>=sum_3)) {
            sum_1 -= a[i];
            i++;
        } else {
            if ((sum_2>=sum_1) && (sum_2>=sum_3)) {
                sum_2 -= b[j];
                j++;
            } else {
                sum_3 -= c[k];
                k++;
            }
        }
    }
    return sum_1;
}

int main() {
    cout << equalStacks({3,2,1,1,1},{4,3,2},{1,1,4,1}) << endl;
    cout << equalStacks({1,2,1,1},{1,1,2},{1,1}) << endl;
}