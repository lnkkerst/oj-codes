#include <bits/stdc++.h>
using namespace std;

int n, full;
long long eat;

int read() {
    int ret, flag = 1;
    char ch;
    while(!isdigit(ch = getchar())) (ch == '-') && (flag = -1);
    for(ret = ch - '0'; isdigit(ch = getchar()); ret *= 10, ret += ch - '0');
    return ret * flag;
}

void print(int x) {
    if(x < 0) { putchar('-'); x *= -1; }
    if(x > 9) { print(x / 10); }
    putchar(x % 10 + '0');
}

int main() {
    n = read();
    for(int i = 1; i <= n; ++i) {
        int tmp = read();
        if(tmp >= 1) ++full, eat += tmp;
    }
    printf("%lf\n", (double)(eat) / (double)(full) * (double)(eat));
    return 0;
}