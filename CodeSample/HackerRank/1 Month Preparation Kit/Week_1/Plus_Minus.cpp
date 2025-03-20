void plusMinus(vector<int> arr) {
    int n = arr.size();
    int pos = 0;
    int neg =0;
    int zero = 0;
    for (int i = 0; i < n; i++) {
        if (arr[i] > 0) {
            pos++;
        } else if (arr[i] < 0) {
            neg++;
        } else {
            zero++;
        }
    }
    
    cout << fixed;
    cout << setprecision(6);
    cout << float(pos)/n << endl;
    cout << float(neg)/n << endl;
    cout << float(zero)/n << endl;
}