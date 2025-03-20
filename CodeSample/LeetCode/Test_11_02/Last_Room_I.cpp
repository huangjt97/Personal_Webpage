class Solution {
public:
    int minTimeToReach(vector<vector<int>>& moveTime) {
        int n = moveTime.size();
        int m = moveTime[0].size();
        vector<int> stack_x = {0};
        vector<int> stack_y = {0};
        vector<int> stack_time = {0};
        vector<vector<int>> arrTime;
        for (int i = 0; i < n-1; i++) {
            arrTime.push_back({});
            for (int j = 0; j < m-1; j++) {
                arrTime[i].push_back(1000010000);
            }
        }
        int k = 0;
        int p = 0;
        int l,r,q;
        while ((stack_x[k]<n-1) or (stack_y[k]<n-1)) {
            if (stack_x[k]>0) {
                l = stack_x[k]-1;
                r = stack_y[k];
                q = stack_time[k]+1;
                if (moveTime[l][r]>q) {
                    q = moveTime[l][r];
                }
                if (q<arrTime[l][r]) {
                    stack_x.push_back(l);
                    stack_x.push_back(r);
                    stack_time.push_back(q);
                    arrTime[l][r] = q;
                    p += 1;
                }
            }
            if (stack_x[k]<n-1) {
                l = stack_x[k]+1;
                r = stack_y[k];
                q = stack_time[k]+1;
                if (moveTime[l][r]>q) {
                    q = moveTime[l][r];
                }
                if (q<arrTime[l][r]) {
                    stack_x.push_back(l);
                    stack_x.push_back(r);
                    stack_time.push_back(q);
                    arrTime[l][r] = q;
                    p += 1;
                }
            }
            if (stack_y[k]>0) {
                l = stack_x[k];
                r = stack_y[k]-1;
                q = stack_time[k]+1;
                if (moveTime[l][r]>q) {
                    q = moveTime[l][r];
                }
                if (q<arrTime[l][r]) {
                    stack_x.push_back(l);
                    stack_x.push_back(r);
                    stack_time.push_back(q);
                    arrTime[l][r] = q;
                    p += 1;
                }
            }
            if (stack_y[k]<m-1) {
                l = stack_x[k];
                r = stack_y[k]+1;
                q = stack_time[k]+1;
                if (moveTime[l][r]>q) {
                    q = moveTime[l][r];
                }
                if (q<arrTime[l][r]) {
                    stack_x.push_back(l);
                    stack_x.push_back(r);
                    stack_time.push_back(q);
                    arrTime[l][r] = q;
                    p += 1;
                }
            }
            k+=1;
        }
        return arrTime[n-1][m-1];
    }
};

int main() {
    Solution s;
    
    cout << s.minTimeToReach([[0,4],[4,4]]);
    return 0;
}

