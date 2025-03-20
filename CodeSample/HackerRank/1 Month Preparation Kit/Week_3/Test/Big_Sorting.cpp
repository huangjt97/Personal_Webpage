#include<iostream>
#include<vector>
#include<string>
#include<algorithm>
using namespace std;


vector<string> bigSorting(vector<string> unsorted) {
    vector<string> result = unsorted;
    sort(result.begin(), result.end(), 
    [](const string& a, const string& b) {
        return (a.size() != b.size()) ? a.size() < b.size() : a < b;
    });
    return result;
}

int main() {
    vector<string> answer = bigSorting({"31415926530346235613161","1","3","10","3","5"});
    
    while (answer.size()>0) {
        cout << answer.front() << endl;
        answer.erase(answer.begin());
    }

}