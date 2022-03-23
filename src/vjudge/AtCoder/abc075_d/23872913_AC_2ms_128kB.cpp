#include <cstdio>
#include <cctype>
#include <algorithm>
#define int long long
using namespace std;

struct Node {
    int x, y;
} a[233];

int n, num, ans = 0x7fffffffffffffff;

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

bool cmp(Node a, Node b) {
    return a.x < b.x;
}

signed main() {
    n = read(), num = read();
    for(int i = 1; i <= n; ++i) a[i].x = read(), a[i].y = read();
    std::sort(a + 1, a + n + 1, cmp);
    for(int i = 1; i <= n; ++i)
        for(int j = i + 1; j <= n; ++j) {
            int tmx = std::max(a[i].y, a[j].y),
                tmn = std::min(a[i].y, a[j].y);
            for(int k = 1; k <= n; ++k) {
                if(a[k].y > tmx || a[k].y < tmn) continue;
                int cnt = 0;
                for(int l = k; l <= n; ++l) {
                    if(a[l].y > tmx || a[l].y < tmn) continue;
                    if(++cnt >= num) ans = min(ans, (tmx - tmn) * (a[l].x - a[k].x));
                }
            }
        }
    print(ans);
    return 0;
}