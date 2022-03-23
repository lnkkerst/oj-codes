#include <cstdio>
#include <cctype>
#define int long long

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

signed main() {
    int n = read(), m = read(), a = read();
    print(((m + a - 1) / a) * ((n + a - 1) / a));
    return 0;
}