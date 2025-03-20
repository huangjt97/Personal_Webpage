#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class SilkClothOptimizer {
private:
    // Function to find maximum between two numbers
    int max(int a, int b) {
        return (a > b) ? a : b;
    }

public:
    // Function to find the maximum value possible from the silk cloth
    int getMaxValue(vector<int>& parts) {
        int n = parts.size();
        
        // If there are no parts, return 0
        if (n == 0) return 0;
        
        // If there's only one part, return that part's value if positive, else 0
        if (n == 1) return max(parts[0], 0);

        // Initialize variables for Kadane's algorithm
        int maxEndingHere = parts[0];
        int maxSoFar = parts[0];
        
        // Traverse through the array
        for (int i = 1; i < n; i++) {
            // Calculate maximum value ending at current position
            maxEndingHere = max(parts[i], maxEndingHere + parts[i]);
            
            // Update maximum value found so far
            maxSoFar = max(maxSoFar, maxEndingHere);
        }
        
        // Return maximum of maxSoFar and 0 (in case all values are negative)
        return max(maxSoFar, 0);
    }

    // Function to print the parts that should be selected
    void printSelectedParts(vector<int>& parts) {
        int n = parts.size();
        int maxEndingHere = parts[0];
        int maxSoFar = parts[0];
        int start = 0;
        int end = 0;
        int s = 0;

        // Find the start and end indices of maximum subarray
        for (int i = 1; i < n; i++) {
            if (parts[i] > maxEndingHere + parts[i]) {
                maxEndingHere = parts[i];
                s = i;
            } else {
                maxEndingHere = maxEndingHere + parts[i];
            }

            if (maxEndingHere > maxSoFar) {
                maxSoFar = maxEndingHere;
                start = s;
                end = i;
            }
        }

        // If all values are negative, don't select any part
        if (maxSoFar <= 0) {
            cout << "No parts should be selected (all values are negative)\n";
            return;
        }

        cout << "Selected parts (indices): ";
        for (int i = start; i <= end; i++) {
            cout << i << " ";
        }
        cout << "\nValues: ";
        for (int i = start; i <= end; i++) {
            cout << parts[i] << " ";
        }
        cout << endl;
    }
};

int main() {
    SilkClothOptimizer optimizer;
    
    // Get input from user
    int N;
    cout << "Enter the number of parts (N): ";
    cin >> N;
    
    vector<int> parts(N);
    cout << "Enter the value for each part:\n";
    for (int i = 0; i < N; i++) {
        cin >> parts[i];
    }
    
    // Calculate and display results
    int maxValue = optimizer.getMaxValue(parts);
    cout << "\nMaximum possible value: " << maxValue << endl;
    
    // Print which parts should be selected
    optimizer.printSelectedParts(parts);
    
    return 0;
}