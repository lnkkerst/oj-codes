#include <cstdio>
#include <cctype>
#define int long long

int f[36] = {0, 2};

int read() {
    int ret, fl = 1;
    char ch;
    while(!isdigit(ch = getchar()))
        (ch == '-') && (fl = -1);
    ret = ch - '0';
    while(isdigit(ch = getchar()))
        ret *= 10, ret += ch - '0';
    return ret * fl;
}

void print(int x) {
    if(x < 0) putchar('-'), x = -x;
    if(x > 9) print(x / 10);
    putchar(x % 10 + '0');
}

signed main() {
    for(int i = 2; i <= 35; ++i)
        f[i] = f[i - 1] * 3 + 2;
    int x;
    while(scanf("%ld", &x) != EOF)
        print(f[x]), puts("");
    return 0;
}