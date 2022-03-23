#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

#define int long long

const int MOD = 1e9 + 7;

signed main() {
    int t;
    cin >> t;
    while(t--) {
        int n, k;
        cin >> n >> k;
        vector<int> a;
        for(int i = 1; i <= n; ++i) {
            int x;
            cin >> x;
            a.emplace_back(x);
        }
        sort(a.begin(), a.end(), greater<>());
        --k;
        int cnt = 1;
        int need = 1;
        for(int i = k + 1; i < a.size(); ++i) {
            if(a[i] == a[k]) {
                ++cnt;
            } else {
                break;
            }
        }
        for(int i = k - 1; i >= 0; --i) {
            if(a[i] == a[k]) {
                ++cnt;
                ++need;
            } else {
                break;
            }
        }
        int ans = 1;
        for(int i = 1 ;i <= cnt; ++i) {
            ans *= i;
            ans %= MOD;
        }
        for(int i = 1; i <= need; ++i) {
            ans /= i;
            ans %= MOD;
        }
        for(int i = 1; i <= cnt - need; ++i) {
            ans /= i;
            ans %= MOD;
        }
        cout << ans << endl;
    }
    return 0;
}