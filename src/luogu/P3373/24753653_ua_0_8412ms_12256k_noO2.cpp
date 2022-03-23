#include <bits/stdc++.h>
#define int long long
#define MAXN 400010
using namespace std;

int p;

struct SmT {
    #define lc x << 1
    #define rc x << 1 | 1
    int ls, rs;
    int sum[MAXN], a[MAXN], tag[MAXN], tagc[MAXN];
    SmT() {
        ls = 1, rs = 0;
    }
    void read() {
        int ret;
        char ch;
        bool flag = 0;
        while(!isdigit(ch = getchar())) (ch == '-') && (flag = true);
        for(ret = ch - '0'; isdigit(ch = getchar()); ret = ret * 10 + ch - '0');
        a[++rs] = ret;
    }
    void update(int x) {
        sum[x] = (sum[lc] % p + sum[rc] % p) % p;
    }
    void tbuild(int l, int r, int x) {
        sum[x] = 0, tag[x] = 0, tagc[x] = 1;
        if(l == r) {
            sum[x] = a[l];
            return ;
        }
        int mid = (l + r) >> 1;
        tbuild(l, mid, lc);
        tbuild(mid + 1, r, rc);
        update(x);
    }
    void build() {
        tbuild(ls, rs, 1);
    }
    int tquery(int a, int b, int l, int r, int x) {
        if(a <= l && r <= b) return sum[x] % p;
        //down(l, r, x);
        int mid = (l + r) >> 1, ans = 0;
        if(tagc[x] != 1 || tag[x]) down(l, r, x);
        if(a <= mid) ans += tquery(a, b, l, mid, lc), ans %= p;
        if(mid < b) ans += tquery(a, b, mid + 1, r, rc), ans %= p;
        return ans % p;
    }
    int query(int a, int b) {
        return tquery(a, b, ls, rs, 1);
    }
    void down(int l, int r, int x) {
        int mid = (l + r) >> 1;
        // if(tag[x]) {
        //     tag[lc] += tag[x];
        //     tag[rc] += tag[x];
        //     sum[lc] += (mid - l + 1) * tag[x];
        //     sum[rc] += (r - mid) * tag[x];
        //     tag[x] = 0;
        // }
        tagc[lc] = (tagc[lc] * tagc[x]) % p;
        tagc[rc] = (tagc[rc] * tagc[x]) % p;
        tag[lc] = (tag[lc] * tagc[x]) % p;
        tag[rc] = (tag[rc] * tagc[x]) % p;
        sum[lc] = (sum[lc] * tagc[x]) % p;
        sum[rc] = (sum[rc] * tagc[x]) % p;
        tagc[x] = 1;
        tag[lc] = (tag[lc] + tag[x]) % p;
        tag[rc] = (tag[rc] + tag[x]) % p;
        sum[lc] = (sum[lc] + (mid - l + 1) * tag[x]) % p;
        sum[rc] = (sum[rc] + (r - mid) * tag[x]) % p;
        tag[x] = 0;
    }
    void tadd(int a, int b, int v, int l, int r, int x) {
        if(a <= l && r <= b) {
            tag[x] += v;
            tag[x] %= p;
            sum[x] += v * (r - l + 1);
            sum[x] %= p;
            return ;
        }
        //down(l, r, x);
        int mid = (l + r) >> 1;
        if(tagc[x] != 1 || tag[x]) down(l, r, x);
        if(a <= mid) tadd(a, b, v, l, mid, lc);
        if(mid < b) tadd(a, b, v, mid + 1, r, rc);
        update(x);
    }
    void add(int a, int b, int v) {
        tadd(a, b, v, ls, rs, 1);
    }
    void tmul(int a, int b, int v, int l, int r, int x) {
        if(a <= l && r <= b) {
            tagc[x] = (tagc[x] * v) % p;
            tag[x] = (tag[x] * v) % p;
            sum[x] = (sum[x] * v) % p;
            return ;
        }
        //down(l, r, x);
        int mid = (l + r) >> 1;
        if(tagc[x] != 1 || tag[x]) down(l, r, x);
        if(a <= mid) tmul(a, b, v, l, mid, ls);
        if(b > mid) tmul(a, b, v, mid + 1, r, rs);
        update(x);
    }
    void mulall(int a, int b, int v, int l, int r, int x) {
        if(l >= a && r <= b) {
            tagc[x] = (tagc[x] * v) % p;
            tag[x] = (tag[x] * v) % p;
            sum[x] = (sum[x] * v) % p;
            return ;
        }
        int mid = (l + r) >> 1;
        int ls = x << 1;
        int rs = ls | 1;
        if(tagc[x] != 1 || tag[x]) down(l, r, x);
        if(a <= mid) mulall(a, b, v, l, mid, ls);
        if(b > mid) mulall(a, b, v, mid + 1, r, rs);
        update(x);
    }
    void mul(int a, int b, int v) {
        //tmul(a, b, v, ls, rs, 1);
        mulall(a, b, v, ls, rs, 1);
    }
} smt;

int read() {
    int ret;
    char ch;
    bool flag = 0;
    while(!isdigit(ch = getchar())) (ch == '-') && (flag = true);
    for(ret = ch - '0'; isdigit(ch = getchar()); ret = ret * 10 + ch - '0');
    return flag ? -ret : ret;
}

#undef int
int main() {
    #define int long long
    int n = read(), m = read();
    p = read();
    for(int i = 1; i <= n; ++i) smt.read();
    smt.build();
    while(m--) {
        int opt = read();
        if(opt == 2) {
            int x = read(), y = read(), v = read();
            smt.add(x, y, v);
            for(int i = 1; i <= n; ++i) printf("%lld ", smt.query(i, i));
            printf("\n");
        }
        else if(opt == 3) {
            int x = read(), y = read();
            printf("%lld\n", smt.query(x, y));
        }
        else {
            int x = read(), y = read(), v = read();
            smt.mul(x, y, v);
            for(int i = 1; i <= n; ++i) printf("%lld ", smt.query(i, i));
            printf("\n");
        }
    }
    return 0;
}