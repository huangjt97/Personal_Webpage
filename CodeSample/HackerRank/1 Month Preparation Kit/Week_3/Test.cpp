#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

int main() {
    int threshold = 5;
    auto filtered = remove_if(nums.begin(), nums.end(),
        [threshold](int x) { return x < threshold; });
}