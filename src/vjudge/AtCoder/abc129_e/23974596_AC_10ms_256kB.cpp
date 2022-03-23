#include <cstdio>
#include <cstring>
#define int long long

const int MOD = (int)1e9 + 7;
char str[100010];
int ans = 1, len;

int qpow(int x, int k) {
    int ret = 1;
    while(k) {
        if(k & 1) ret *= x, ret %= MOD;
        x *= x, k >>= 1, x %= MOD;
    }
    return ret % MOD;
}

signed main() {
    scanf("%s", str + 1);
    len = strlen(str + 1);
    for(int i = len; i; --i)
        if(str[i] == '1')
            ans <<= 1, ans += qpow(3, len - i), ans %= MOD;
    printf("%lld", ans);
    return 0;
}