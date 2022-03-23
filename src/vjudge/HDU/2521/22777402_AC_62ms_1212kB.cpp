#include <cstdio>
#include <cctype>
#include <algorithm>
using namespace std;

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

int f[500010];

int calc(int x) {
    if(f[x]) return f[x];
    for(int i = 1; i <= x; ++i)
        if(x % i == 0) ++f[x];
    return f[x];
}

int main() {
    int t = read();
    while(t--) {
        int l = read(), r = read(), maxn = -1, maxa;
        for(int i = l; i <= r; ++i)
            if(calc(i) > maxn) {
                maxn = calc(i);
                maxa = i;
            }
        print(maxa), putchar('\n');
    }
}