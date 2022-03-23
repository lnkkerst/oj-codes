#include <bits/stdc++.h>

using namespace std;

int n, a[13001], ans, dp[13001][13001];

int read() {
    int ret;
    bool flag = 0;
    char ch;
    while(!isdigit(ch = getchar())) (ch == '-') && (flag = 1);
    for(ret = ch - '0'; isdigit(ch = getchar()); ret *= 10, ret += ch - '0');
    return flag ? -ret : ret;
}

int calc_dp(int l, int r) {
    if(dp[l][r]) return dp[l][r];
    if(!dp[l][l]) dp[l][l] = a[l];
    int pos = l + 1;
    while(dp[l][pos] && pos <= r) ++pos;
    for(; pos <= r; ++pos) dp[l][pos] = max(dp[l][pos - 1] + a[pos], a[pos]);
    int ret = -13224;
    for(int i = l; i <= r; ++i) ret = max(dp[l][i], ret);
    return ret < 0 ? 0 : ret;
}

int main() {
    n = read();
    for(int i = 1; i <= n; ++i) a[i] = read();
    int l = 1, r = 1;
    while(r <= n && r - l + 1 <= n) {
        int tmp = calc_dp(l, r);
        ans += tmp;
        ans %= (int)1e5;
        if(r == n) ++l, r = l;
        else ++r;
    }
    printf("%d\n", ans);
    return 0;
}