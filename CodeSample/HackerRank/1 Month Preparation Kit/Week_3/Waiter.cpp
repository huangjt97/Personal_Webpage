#include<iostream>
#include<vector>

using namespace std;

vector<int> waiter(vector<int> number, int q) {
    int j;
    bool flag;
    vector<int> prime = {2};
    int p = 3;
    for (int i = 1; i<q; i++) {
        flag = true;
        while (flag) {
            j = 0;
            flag = false;
            while ((prime[j]*prime[j]<=p) && (j<prime.size())) {
                if (p%prime[j]==0) {
                    p+=2;
                    flag = true;
                    break;
                }
                j+=1;
            }
        }
        prime.push_back(p);
        p+=2;
    }

    vector<int> c = number;
    vector<int> a = {};
    vector<int> b = {};
    vector<int> answer = {};
    for (int i = 0; i<q; i++) {
        while (c.size()>0) {
            if (c.back() % prime[i] == 0) {
                b.push_back(c.back());
            } else {
                a.push_back(c.back());
            }
            c.pop_back();
        }
        while (b.size()>0) {
            answer.push_back(b.back());
            b.pop_back();
        }
        c = a;
        a = {};
    }

    while (c.size()>0) {
        answer.push_back(c.back());
        c.pop_back();
    }
    return answer;
}

int main() {
    vector<int> arr = {2,3,4,5,6,7};
    vector<int> answer = waiter(arr,3);
    cout << answer[0];
    for (int i = 1; i< answer.size(); i++) {
        cout << ' ' << answer[i];
    }
    cout << endl;

    return 0;
}