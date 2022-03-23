#include <bits/stdc++.h>
#define int long long
using namespace std;
const int MAXS = 101, MOD = 1e9 + 7;
int uni[1000010];

struct Mat {
    int n, m, data[MAXS][MAXS];
    Mat(int _n = 0, int _m = 0, int _v = 0) {
        if(!_m) _m = _n;
        n = _n, m = _m;
        memset(data, _v, sizeof(data));
    }
    int* operator[](int x) { return data[x]; }
    Mat operator*(Mat b) {
        Mat ret(n, b.m, 0x3f);
        for(int k = 1; k <= n; ++k)
            for(int i = 1; i <= n; ++i)
                for(int j = 1; j <= n; ++j)
                    ret[i][j] = min(ret[i][j], data[i][k] + b[k][j]);
        return ret;
    }
    Mat pow(int k) {
        Mat tmp(n), ret(n);
        for(int i = 1; i <= n; ++i)
            for(int j = 1; j <= n; ++j)
                tmp[i][j] = ret[i][j] = data[i][j];
        while(k) {
            if(k & 1) ret = ret * tmp;
            tmp = tmp * tmp, k >>= 1;
        }
        return ret;
    }
} ;

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
    int n = read(), t = read(), s = read(), e = read(), cnt = 0;
    Mat dis(100, 100, 0x3f);
    for(int i = 1; i <= t; ++i) {
        int w = read(), u = read(), v = read();
        if(!uni[u]) uni[u] = ++cnt;
        if(!uni[v]) uni[v] = ++cnt;
        dis[uni[u]][uni[v]] = dis[uni[v]][uni[u]] = w;
    } dis.m = dis.n = cnt;
    // printf("%lld\n", cnt);
    Mat ans = dis.pow(n - 1);
    print(ans[uni[s]][uni[e]]);
    return 0;
}