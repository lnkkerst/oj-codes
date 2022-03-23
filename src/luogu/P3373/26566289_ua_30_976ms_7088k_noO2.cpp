#include <cstdio>
#include <map>
#include <iostream>
#include <cmath>
#include <cstring>
#define int long long
using namespace std;
const int MAXN  = 100010;

int n, m, a[MAXN], bl[MAXN], p;
int blocks, cnt = 0, l[MAXN], r[MAXN], sum[MAXN], dlt[MAXN], maxa[MAXN], mul[MAXN], add[MAXN];

void init() {
    blocks = sqrt(n);
    for(int i = 1; i <= n; ++i) bl[i] = i / blocks;
    for(int i = n; i >= 1; --i) l[bl[i]] = i;
    for(int i = 1; i <= n; ++i) r[bl[i]] = i;
    for(int i = 1; i <= n; ++i) sum[bl[i]] += a[i];
    for(int i = bl[1]; i <= bl[n]; ++i) mul[i] = 1;
}

void reset(int x) {
    for(int i = l[x]; i <= r[x]; ++i) a[i] = a[i] * mul[x] + add[x];
    mul[x] = 1, add[x] = 0;
}

void sum_range(int x, int y, int v) {
    reset(bl[x]);
    sum[bl[x]] = sum[bl[x]] + (min(y, r[bl[x]] - x + 1) * v);
    int tmp = min(y, r[bl[x]]);
    for(int j = x; j <= tmp; ++j) a[j] += v;
    if(bl[x] != bl[y]) {
        reset(bl[y]);
        sum[bl[y]] = sum[bl[y]] + (y - l[bl[y]] + 1) * v;
        for(int j = y; j >= l[bl[y]]; --j) a[j] += v;
        for(int j = bl[x] + 1; j <= bl[y] - 1; ++j) add[j] += v, sum[j] = sum[j] + blocks * v;
    }
}

void mul_range(int x, int y, int v) {
    reset(bl[x]);
    int tmp = min(y, r[bl[x]]);
    for(int j = x; j <= tmp; ++j) sum[bl[x]] += (v - 1) * a[j], a[j] = a[j] * v;
    if(bl[x] != bl[y]) {
        reset(bl[y]);
        for(int j = y; j >= l[bl[y]]; --j) sum[bl[y]] += (v - 1) * a[j], a[j] = a[j] * v;
    }
    for(int j = bl[x] + 1; j <= bl[y] - 1; ++j) mul[j] *= v, add[j] *= v, sum[j] *= v;
}

int query(int x, int y) {
    int ret = 0, tmp = min(y, r[bl[x]]);
    for(int j = x; j <= tmp; ++j) ret += a[j] * mul[bl[x]] + add[bl[x]];
    if(bl[x] != bl[y]) {
        for(int j = y; j >= l[bl[y]]; --j) ret += a[j] * mul[bl[y]] + add[bl[y]];
        for(int j = bl[x] + 1; j <= bl[y] - 1; ++j) ret += sum[j];
    }
    return ret;
}

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
    n = read(), m = read(), p = read();
    for(int i = 1; i <= n; ++i) a[i] = read();
    init();
    for(int i = 1; i <= m; ++i) {
        int opt = read();
        if(opt == 1) {
            int x = read(), y = read(), k = read();
            mul_range(x, y, k);
        }
        else if(opt == 3) {
            int x = read(), y = read();
            print(query(x, y) % p), putchar('\n');
        }
        else {
            int x = read(), y = read(), k = read();
            sum_range(x, y, k);
        }
    }
    return 0;
}