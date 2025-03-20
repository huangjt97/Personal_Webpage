void miniMaxSum(vector<int> arr) {
    int n = arr.size();
    int minVal = arr[0];
    int maxVal = arr[0];
    long sum = arr[0];
    for (int i = 1; i < n; i++) {
        if (arr[i] < minVal) {
            minVal = arr[i];
        }
        if (arr[i] > maxVal) {
            maxVal = arr[i];
        }
        sum += arr[i];
    }
    cout << sum-maxVal << " " << sum-minVal;
    return ;
}