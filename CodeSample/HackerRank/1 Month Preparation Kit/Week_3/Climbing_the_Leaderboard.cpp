#include<iostream>
#include<vector>

using namespace std;

vector<int> climbingLeaderboard(vector<int> ranked, vector<int> player) {
    vector<int> rank_num;
    rank_num.push_back(ranked[0]);
    int n = ranked.size();
    int m = player.size();
    for (int i = 1; i < n; i++) {
        if (ranked[i] != ranked[i-1]) {
            rank_num.push_back(ranked[i]);
        }
    }

    vector<int> answer;
    for (int k: player) {
        int l = 0;
        int r = rank_num.size()-1;
        while (l<r) {
            m = (l+r) / 2;
            if (rank_num[m]<=k) {
                r = m;
            } else {
                l = m+1;
            }
        }
        
        if (k>=rank_num[l]) {
            answer.push_back(l+1);
        } else {
            answer.push_back(l+2);
        }
    }

    return answer;
}

int main() {
    vector<int> answer = climbingLeaderboard({100,100,50,40,40,20,10},{5,25,50,120});
    for (int a: answer) {
        cout << a << " ";
    }
    cout << endl;

    answer = climbingLeaderboard({100,90,90,80,75,60},{50,65,77,90,102});
    for (int a: answer) {
        cout << a << " ";
    }
    cout << endl;
    return 0;
}