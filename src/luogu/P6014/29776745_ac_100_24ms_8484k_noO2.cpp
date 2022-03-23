#include <cstdio>
#include <cctype>
#define int long long

int a[1000010], sum, n;
int cnt[11];

int read() {
    int ret, f = 1;
    char ch;
    while(!isdigit(ch = getchar())) (ch == '-') && (f = -1);
    for(ret = ch - '0'; isdigit(ch = getchar()); ret *= 10, ret += ch - '0');
    return ret * f;
}

void print(int x) {
    if(x < 0) putchar('-'), x = -x;
    if(x > 9) print(x / 10);
    putchar(x % 10 + '0');
}

bool pd(int x) {
    if(!(x & 1) && cnt[x >> 1] >= 2) return 1;
    for(int i = 1; i <= x; ++i)
        if(cnt[i] && cnt[x - i] && i != (x - i)) return 1;
    return 0;
}

signed main() {
    n = read();
    for(int i = 1; i <= n; ++i) a[i] = read(), sum += a[i], ++cnt[a[i]];
    if(pd((sum % 10) + 10))
        if(sum % 10) print(sum % 10);
        else print(10);
    else if(pd(sum % 10))
        print(sum % 10);
    else print(0);
    return 0;
}