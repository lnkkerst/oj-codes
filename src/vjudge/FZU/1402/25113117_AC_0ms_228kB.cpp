#include <iostream>
#define int long long
using namespace std;

int n, a[11], b[11];

signed main() {
    while(cin >> n) {
        for(int i = 1; i <= n; ++i)
            cin >> a[i] >> b[i];
        int ans = b[1], t = a[1];
        for(int i = 2; i <= n; ++i) {
            while(ans % a[i] != b[i])
                ans += t;
            t *= a[i];
        }
        cout << ans << endl;
    }
    return 0;
}