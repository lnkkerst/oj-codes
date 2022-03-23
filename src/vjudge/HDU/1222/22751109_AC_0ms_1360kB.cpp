#include <cstdio>
#include <cstring>
#include <string>
#include <iostream>
#include <cctype>
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

int gcd(int x, int y) {
    return !y ? x : gcd(y, x % y);
}

int main() {
    int t = read();
    while(t--) {
        int m = read(), n = read();
        int tmp = gcd(m, n);
        if(tmp == 1) printf("NO\n");
        else printf("YES\n");
    }
    return 0;
}