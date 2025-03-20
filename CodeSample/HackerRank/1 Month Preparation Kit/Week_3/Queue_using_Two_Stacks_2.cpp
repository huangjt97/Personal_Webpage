#include<iostream>
#include <fstream>
#include<vector>
#include<string>
using namespace std;

int main() {
    ifstream inputFile("input.txt");
    if (!inputFile) {
        std::cerr << "Error opening file!\n";
        return 1; // Exit with error code
    }
    int q,t,m,j;
    inputFile >> q;
    vector<int> arr;
    vector<int> arr_2;
    bool flag = true;
    for (int p = 0; p < q; p++) {
        inputFile >> t;
        if (t == 1) {
            inputFile >> j;
            if (flag) {
                arr.push_back(j);
            } else {
                while (arr_2.size()>0) {
                    arr.push_back(arr_2.back());
                    arr_2.pop_back();
                }
                arr.push_back(j);
            }
            flag = true;
        } else if (t == 2) {
            if (flag) {
                while (arr.size()>0) {
                    arr_2.push_back(arr.back());
                    arr.pop_back();
                }
                arr_2.pop_back();
            } else {
                arr_2.pop_back();
            }
            flag = false;
        } else {
            if (flag) {
                cout << arr.front() << endl;
            } else {
                cout << arr_2.back() << endl;
            }
        }
    }
    inputFile.close();
    return 0;
}