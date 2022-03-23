#include <cstdio>
#include <cctype>
#define int long long

int read() {
    int ret, f = 1;
    char ch;
    while(!isdigit(ch = getchar())) (ch == '-') && (f = -1);
    for(ret = ch - '0'; isdigit(ch = getchar()); ret *= 10, ret += ch - '0');
    if(ch == EOF) return EOF;
    return ret * f;
}

void print(int x) {
    if(x < 0) putchar('-'), x = -x;
    if(x > 9) print(x / 10);
    putchar(x % 10 + '0');
}

int gcd(int x, int y) {
    return !y ? x : gcd(y, x % y);
}

int lcm(int x, int y) {
    return x * y / gcd(x, y);
}

signed main() {
    int n;
    while(scanf("%lld", &n) != EOF) {
        int ans = 1;
        while(n--) ans = lcm(read(), ans);
        print(ans), putchar('\n');
    }
    return 0;
}