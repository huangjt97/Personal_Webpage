#include<iostream>
#include<vector>

using namespace std;

vector<vector<int>> Decrease_Timer(vector<vector<int>> timer) {

    int n = timer.size();
    int m = timer[0].size();

    vector<vector<int>> temp = timer;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (timer[i][j] == 1) {
                temp[i][j] = 1;
                if (i>0) {
                    temp[i-1][j] = 1;
                }
                if (i<n-1) {
                    temp[i+1][j] = 1;
                }
                if (j>0) {
                    temp[i][j-1] = 1;
                }
                if (j<m-1) {
                    temp[i][j+1] = 1;
                }
            }
        }
    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            temp[i][j] -= 1;
        }
    }

    return temp;
}

vector<vector<int>> Decrease_Timer_2(vector<vector<int>> timer) {

    int n = timer.size();
    int m = timer[0].size();

    vector<vector<int>> temp = timer;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (timer[i][j] == 0) {
                temp[i][j] = 3;
            } else {
                temp[i][j] -= 1;
            }
        }
    }

    return temp;
}

void output_timer(vector<vector<int>> timer) {
    
    for (int i = 0; i < timer.size(); i++) {
        for (int j = 0; j < timer[i].size(); j++) {
            cout << timer[i][j];
        }
        cout << endl;
    }
}

vector<string> bomberMan(int k, vector<string> grid) {
    int t = k;
    
    //Initial
    vector<vector<int>> timer;
    for (int i = 0; i < grid.size(); i++) {
        timer.push_back({});
        for (int j = 0; j < grid[i].size(); j++) {
            if (grid[i][j] != '.') {
                timer[i].push_back(1);
            } else {
                timer[i].push_back(3);
            }
        }
    }

    if (t<2) {
        return grid;
    } else {
        // First Second;
        t -= 2;
        t = t % 4;
        while (t>0) {

            output_timer(timer);
            if (t % 2 ==1) {
                timer = Decrease_Timer(timer);
            } else {
                timer = Decrease_Timer_2(timer);
            }
            t -= 1;
        }

        vector<string> answer;
        for (int i = 0; i < timer.size(); i++) {
            answer.push_back("");
            for (int j = 0; j < timer[i].size(); j++) {
                if (timer[i][j] == 0) {
                    answer[i] += '.';
                } else {
                    answer[i] += 'O';
                }
            }
        }

        return answer;
    }

}

void output_answer(vector<string> answer) {
    
    for (int i = 0; i < answer.size(); i++) {
        cout << answer[i] << endl;
    }
}

int main() {

    vector<string> answer = bomberMan(329973043,{"OOOO.O.O...OOO.O.O........O.OOO.O.....OO..O..O...OOO....O.OOO....O...O....O..O.O.O.....OOOO.O...O....OO.O...........O.O..O.O..O...OO.OOO......O........O...O....O.O..O....O.......OOOO.O..........OO.O"});

    output_answer(answer);

    return 0;
}
