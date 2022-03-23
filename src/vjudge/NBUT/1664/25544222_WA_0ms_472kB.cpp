#include <iostream>
#define int long long
using namespace std;

signed main() {
    int x;
    cin >> x;
    (x < 0) && (x = -x);
    int ans = 0, t = x;
    while(t) {
        ans += t & 1;
        t >>= 1;
    }
    cout << ans;
    return 0;
}