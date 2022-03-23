#include <cstdio>
#include <algorithm>
#include <cctype>
using namespace std;

struct Node {
    int w, v;
} a[100010];

int n, ans;
int f[100010];

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
    return a.w > b.w;
}

int main() {
    n = read();
    for(int i = 1; i <= n; ++i) a[i].v = read(), a[i].w = read(), f[i] = -1e9;
    sort(a + 1, a + n + 1, cmp);
    for(int i = 1; i <= n; ++i)
        for(int j = i; j >= 1; --j)
            f[j] = max(f[j], f[j - 1] + a[i].v - (j - 1) * a[i].w);
    for(int j = 1; j <= n; ++j) ans = max(ans, f[j]);
    print(ans);
    return 0;
}