#include<iostream>
#include<vector>
#include<string>

using namespace std;

void simple_text_editor() {
    int q,t,k;
    string W,temp;
    vector<string> s = {""};
    cin >> q;
    for (int i = 0; i<q; i++) {
        cin >> t;
        temp = s.back();
        switch (t) {
            case 1:
                cin >> W;
                s.push_back(temp+W);
                break;
            case 2:
                cin >> k;
                s.push_back(temp.substr(0,temp.size()-k));
                break;
            case 3:
                cin >> k;
                cout << temp[k-1] << endl;
                break;
            case 4:
                s.pop_back();
                break;
        }
    }
}

int main() {
    simple_text_editor();
    return 0;
}