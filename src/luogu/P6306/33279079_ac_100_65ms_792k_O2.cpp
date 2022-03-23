#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>
#define int long long
using namespace std;

typedef long long LL;
#define gc pa==pb&&(pb=(pa=buf)+fread(buf,1,100000,stdin),pa==pb)?EOF:*pa++
static char buf[100000], *pa(buf), *pb(buf);
inline LL readint() {
    LL x = 0;
    char c = gc;
    while (c < '0' || c > '9')c = gc;
    for (; c >= '0' && c <= '9'; c = gc)x = x * 10 + (c & 15);
    return x;
}

signed main() {
    int n = readint(), k = readint();
    int num[8][1 << 8] = {0};
    for(int i = 1; i <= n; ++i) {
        int x = readint();
        for(int j = 0; j < 8; ++j)
            ++num[j][x >> (j * 8) & ((1 << 8) - 1)];
    }
    int ans = 0;
    for(int i = 1; i < (1 << 8); ++i)
        for(int j = 0; j < 8; ++j)
            if(num[j][i] % k)
                ans += (i << (j * 8));
    cout << ans;
    return 0;
}