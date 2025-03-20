#include<iostream>
#include<stack>
#include<string>
using namespace std;

int main() {

    int q,j,t;
    cin >> q;
    string s,temp;
    stack<int> arr = {};
    stack<int> arr_2 = {};
    bool flag = true;
    for (int i = 0; i<q; i++) {
        cin >> t;
        if (t == 1) {
            cin >> j;
            if (flag) {
                arr.push(j);
            } else {
                while (arr_2.size()>0) {
                    arr.push(arr_2.top());
                    arr_2.pop();
                }
                arr.push(j);
            }
            flag = true;
        } else if (t == 2) {
            if (flag) {
                while (arr.size()>0) {
                    arr_2.push(arr.top());
                    arr.pop();
                }
                arr_2.pop();
            } else {
                arr_2.pop();
            }
            flag = false;
        } else {
            if (flag) {
                while (arr.size()>0) {
                    arr_2.push(arr.top());
                    arr.pop();
                }
                cout << arr_2.top() << endl;
            } else {
                cout << arr_2.top() << endl;
            }
            flag = false;
        }
    }

    return 0;
}