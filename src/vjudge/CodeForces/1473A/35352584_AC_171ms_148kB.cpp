#include <iostream>
#include <vector>
using namespace std;


signed main() {
    int t;
    cin >> t;
    while(t--) {
        int n, d;
        cin >> n >> d;
        vector<int> a;
        for(int i = 1; i <= n; ++i) {
            int x;
            cin >> x;
            a.emplace_back(x);
        }
        bool fl1 = true;
        for(auto i : a) {
            if(i > d) {
                fl1 = false;
                break;
            }
        }
        if(fl1) {
            cout << "YES" << endl;
            continue;
        }
        int mi = 1e9;
        int mip = -1;
        for(int i = 0; i < a.size(); ++i) {
            if(a[i] < mi) {
                mi = a[i];
                mip = i;
            }
        }
        bool fl2 = false;
        for(int i = 0; i < a.size(); ++i) {
            if(i == mip) {
                continue;
            }
            if(a[i] + mi <= d) {
                fl2 = true;
                break;
            }
        }
        if(fl2) {
            cout << "YES" << endl;
            continue;
        }
        cout << "NO" << endl;
    }
    return 0;
}