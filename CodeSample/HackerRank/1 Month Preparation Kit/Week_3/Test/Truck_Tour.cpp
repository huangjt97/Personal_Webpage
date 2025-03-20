#include<iostream>
#include<vector>

using namespace std;


int truckTour(vector<vector<int>> petrolpumps) {
    int n = petrolpumps.size();
    long long pet = petrolpumps[0][0];
    long long dis = petrolpumps[0][1];
    bool flag = (pet>=dis);
    for (int i = 1; i<n; i++) {
        pet += petrolpumps[i][0];
        dis += petrolpumps[i][1];
        if (pet<dis) {
            flag = false;
        }
    }

    if (flag) {
        return 0;
    }

    //begin tour
    int ed;
    for (int st = 1; st<n;st++) {
        ed = (st+1) % n;
        pet = petrolpumps[st][0];
        dis = petrolpumps[st][1];
        flag = (pet>=dis);
        while ((ed!=st) && (flag)) {
            pet += petrolpumps[ed][0];
            dis += petrolpumps[ed][1];
            flag = (pet>=dis);
            ed = (ed+1) % n;
        }
        if (flag) {
            return st;
        }

    }
    return -1;
}

int main() {
    cout << truckTour({{1,5},{10,3},{3,4}}) << endl;
}