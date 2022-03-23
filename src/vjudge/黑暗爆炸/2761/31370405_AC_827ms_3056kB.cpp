#include <iostream>
#include <unordered_set>
#include <vector>
using namespace std;

int main() {
    int t;
    cin >> t;
    while(t--) {
        int n;
        cin >> n;
        vector<int> ans;
        unordered_set<int> b;
        for(int i = 1; i <= n; ++i) {
            int x;
            cin >> x;
            if(b.find(x) == b.end()) {
                ans.emplace_back(x);
                b.insert(x);
            }
        }
        for(auto i : ans)
            cout << i << ' ';
        cout << endl;
    }
    return 0;
}