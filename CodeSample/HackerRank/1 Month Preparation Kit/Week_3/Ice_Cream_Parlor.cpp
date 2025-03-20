#include<iostream>
#include<vector>

using namespace std;

vector<int> icecreamParlor(int m, vector<int> arr) {
    vector<vector<int>> hash = {};
    for (int i = 0; i<10001; i++) {
        hash.push_back({});
    }

    for (int i = 0; i<arr.size(); i++) {
        if (hash[arr[i]].size() <2) {
            hash[arr[i]].push_back(i);
        }
    }
    
    for (int i = 0; i<arr.size(); i++) {
        if (arr[i]>m) continue;
        if (arr[i] != m-arr[i]) {
            if (hash[m-arr[i]].size()>0) {
                return {i+1,hash[m-arr[i]][0]+1};
            }
        } else {
            if (hash[m-arr[i]].size()>1) {
                return {i+1,hash[m-arr[i]][1]+1};
            }
        }
    }

    return {0,0};
}

int main() {
    int m = 789;
    vector<int> arr = {591,955,829,805,312,83,764,841,12,744,104,773,627,306,731,539,349,811,662,341,465,300,491,423,569,405,508,802,500,747,689,506,129,325,918,606,918,370,623,905,321,670,879,607,140,543,997,530,356,446,444,184,787,199,614,685,778,929,819,612,737,344,471,645,726};
    vector<int> answer = icecreamParlor(m,arr);
    cout << answer[0] << " " << answer[1] << endl;
}