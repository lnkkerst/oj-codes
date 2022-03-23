#include <bits/stdc++.h>
using namespace std;

int n, q;
int a[100010];
bitset<100010> b;

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

int main() {
    n = read(), q = read();
    b[0] = 1;
    for(int i = 1; i <= n; ++i) b |= b << read();
    for(int i = 1; i < 100010; ++i) a[i] = a[i - 1] + b[i];
    for(int i = 1; i <= q; ++i) {
        int t1 = read(), t2 = read();
        print(a[t2] - a[t1 - 1]);
        putchar('\n');
    }
    return 0;
}