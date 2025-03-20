#include <vector>
#include <iostream>
using namespace std;

int bigNum = 1234567;
int largeNum = 1000000007;

class h {
    private:
        vector<int> hmap_val;
        vector<int> hmap_pos;
        vector<int> arr;
        vector<int> hpos;
    
    public:
        h(): hmap_val(bigNum,largeNum), hmap_pos(bigNum,largeNum), arr(), hpos() {}
        
        void add(int x) {
            arr.push_back(x);
            int n = arr.size()-1;
            int p = add_hashmap(x, n);
            hpos.push_back(p);
            push_up(n);
            return ;
        }
        
        void push_up(int x) {
            int i = x;
            int j = (i-1) / 2;
            while (arr[i]<arr[j]) {
                exchange(i,j);
                i = j;
                j = (i-1) / 2;
            }
            return ;
        }
        
        void exchange(int i, int j) {
            int temp;
            temp = arr[i];
            arr[i] = arr[j];
            arr[j] = temp;
            temp = hmap_pos[hpos[i]];
            hmap_pos[hpos[i]] = hmap_pos[hpos[j]];
            hmap_pos[hpos[j]] = temp;
            temp = hpos[i];
            hpos[i] = hpos[j];
            hpos[j] = temp;
            return ;
        }
        
        void del(int x) {
            int i = hash_find_pos(x);
            int j = arr.size()-1;
            exchange(i,j);
            arr.pop_back();
            hmap_val[hpos[j]] = largeNum;
            hmap_pos[hpos[j]] = largeNum;
            hpos.pop_back();
            
            push_down(i);
            
            return ;
        }
        
        void push_down(int x){
            int n = arr.size();
            int i = x;
            int j = (x+1) * 2-1;
            int k = (x+1) * 2;
            while (((j<n) && (arr[i]>arr[j])) || ((k<n) && (arr[i]>arr[k]))) {
                if ((k<n) && (arr[j]>arr[k])) {
                    exchange(i,k);
                    i = k;
                } else {
                    exchange(i,j);
                    i = j;
                }
                j = (i+1) * 2-1;
                k = (i+1) * 2;
            }
            
            return ;
        }
        
        int add_hashmap(int x, int y){
            int i = (x % bigNum+bigNum) % bigNum;
            
            while (hmap_val[i]!=largeNum) {
                if (hmap_val[i] == x) {
                    return i;
                }
                i = (i+1) % bigNum;
            }
            hmap_val[i] = x;
            hmap_pos[i] = y;
            
            return i;
        }
        
        int hash_find_pos(int x) {
            int i = (x % bigNum+bigNum) % bigNum;
            while (hmap_val[i]!=x) {
                i = (i+1) % bigNum;
            }

            return hmap_pos[i];
        }
    
        int find_top() {
            return arr.front();
        }
};

int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */
    h heap;
    int Q,t,x;
    cin >> Q;
    for (int i = 0; i < Q; i++) {
        cin >> t;
        switch (t) {
            case 1:
                cin >> x;
                heap.add(x);
                break;
            case 2:
                cin >> x;
                heap.del(x);
                break;
            default:
                cout << heap.find_top() << endl;
        }
    }   
    return 0;
}
