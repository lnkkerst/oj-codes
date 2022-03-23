#include <cstdio>
#include <cctype>
#include <algorithm>

int a[20000010], n;

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
    while(scanf("%d", &n) !=EOF) {
        for(int i = 1; i <= n; ++i) a[i] = read();
        std::sort(a + 1, a + n + 1);
        for(int i = 1; i <= n; ++i) print(a[i]), putchar(' ');
        putchar('\n');
    }
    return 0;
}