#include <iostream>
#define int long long
#define ll long long
using namespace std;

const int MOD = (int)1e9 + 7;
int n, a, b;

int qpow(int x, int k) {
    int ret = 1;
    while(k) {
        if(k & 1) ret *= x;
        x *= x, k >>= 1;
        ret %= MOD, x %= MOD;
    }
    return ret;
}

int inv(int x) {
    return qpow(x, MOD - 2);
}

int C(int x, int n) {
    int t1 = 1, t2 = 1;
    if(x < n - x) x = n - x;
    for(int i = x + 1; i <= n; ++i)
        t1 *= i, t1 %= MOD;
    for(int i = 1; i <= n - x; ++i)
        t2 *= i, t2 %= MOD;
    return t1 * inv(t2) % MOD;
}

signed main() {
    cin >> n >> a >> b;
    cout << ((qpow(2, n) - C(a, n) - C(b, n) - 1) % MOD + MOD) % MOD;
    return 0;
}