#include <cstdio>
#include <cctype>
#define int long long

int a[233] = {0, 1};
int tot = 1;

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
    while(a[tot] <= (int)1e18) a[++tot] = a[tot - 1] * 3;
    int t = read();
    while(t--) {
        int x = read(), ans = 0;
        for(int i = 1; i <= tot; ++i) {
            if(a[i] >= x) {
                print(a[i]), putchar('\n');
                break;
            }
        }
    }
    return 0;
}