#include <bits/stdc++.h>

using namespace std;

int n, a[20020], ans, dp[20020];

int read() {
    int ret;
    bool flag = 0;
    char ch;
    while(!isdigit(ch = getchar())) (ch == '-') && (flag = 1);
    for(ret = ch - '0'; isdigit(ch = getchar()); ret *= 10, ret += ch - '0');
    return flag ? -ret : ret;
}

void print(int x) {
    if(x < 0) { putchar('-'); x *= -1; }
    if(x > 9) { print(x / 10); }
    putchar(x % 10 + '0');
}

int calc_dp(int l, int r) {
    for(int i = l; i <= r; ++i) dp[i] = 0;
    dp[l] = a[l];
    for(int i = l + 1; i <= r; ++i) dp[i] = max(a[i], dp[i - 1] + a[i]);
    int ret = -112;
    for(int i = l; i <= r; ++i) ret = max(ret, dp[i]);
    return ret >= 0 ? ret : 0;
}

void dfs(int size, int no) {
    if(size > n || size + no - 1 > n) return ;
    int tmp = calc_dp(no, no + size - 1);
    ans += tmp;
    ans %= (int)1e5;
    if(size + no - 1 == n) dfs(size + 1, 1);
    else dfs(size , no + 1);
}

int main() {
    n = read();
    for(int i = 1; i <= n; ++i) a[i] = read();
    dfs(1, 1);
    printf("%d\n", ans);
    return 0;
}