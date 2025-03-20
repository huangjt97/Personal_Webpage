#include<iostream>
#include<vector>

using namespace std;

void minimumBribes(vector<int> q) {
    int n = q.size();
    vector<int> current;
    vector<int> find;
    for (int i = 0; i < n; i++) {
        q[i] -= 1;
        current.push_back(i);
        find.push_back(i);
    }
    int j, temp;
    int answer = 0;
    for (int i = 0; i < n; i++) {
        j = q[i];
        if (find[j]-i>2) {
            cout << "Too chaotic" << endl;
            return;
        } else {
            while (find[j]-i>0) {
                temp = current[find[j]-1];
                current[find[j]-1] = q[i];
                current[find[j]] = temp;
                find[current[find[j]]] += 1;
                find[j] -= 1;
                answer += 1;
            }
        }
    }

    cout << answer << endl;
    return;
}

int main() {
    minimumBribes({2,1,5,3,4});
    minimumBribes({2,5,1,3,4});
    return 0;
}