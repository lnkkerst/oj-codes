#include <cstdio>
#define int long long

int gcd(int x, int y) {
    return !y ? x : gcd(y, x % y);
}

signed main() {
    int a, b, s;
    scanf("%lld%lld%lld", &a, &b, &s);
    puts(s % gcd(a, b) ? "NO" : "YES");
    return 0;
}
