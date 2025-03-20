#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int binary_search(int n, int m, vector<int>& nums1, vector<int>& nums2) {
        int center = (n+m+1)/2;
        if ((center == n) && (nums1[n-1]<nums2[0])) {   //check if the lower half is not in nums2
            return n;
        } else if (nums1[0]>nums2[m-1]) {               //check if the lower half is not in nums1
            return 0;
        }
        int l = 1;
        int r = n-1;
        while (l<r) {
            int mid = (l+r)/2;
            if (nums1[mid]<nums2[center-mid-1]) {
                f
            } else {
                f
            }
        }
        return l;
    }
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int n = nums1.size();
        int m = nums2.size();

        int median;
        if (n<m) {
            median = binary_search(n, m, nums1, nums2);
        } else {
            median = n+m-binary_search(m, n, nums2, nums1);
        }

        int solution;
        if ((n+m)%2 == 1) {
            if (nums1[median] < nums2[median]) {

            }
        }
        return 0;
    }
};

int main() {
    Solution s;
    vector<int> nums1 = {1,3};
    vector<int> nums2 = {2};
    double answer = s.findMedianSortedArrays(nums1, nums2);
    cout << "The Median of The Two Sorted Arrays is: " << answer;
    return 0;
}
