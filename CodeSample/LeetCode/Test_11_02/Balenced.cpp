class Solution {
public:
    bool isBalanced(string num) {
        int n = num.size();
        int even = 0;
        int odd = 0;
        for (int i = 0; i < n; i++) {
            if (i % 2 == 0) {
                odd += int(num[i]);
            } else {
                even += int(num[i])
            }
        }
        return (odd == even);
    }
};