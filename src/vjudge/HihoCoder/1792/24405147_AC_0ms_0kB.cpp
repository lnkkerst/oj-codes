#include <cstdio>
#include <cctype>

int read() {
    int ret, fl = 1;
    char ch;
    while(!isdigit(ch = getchar())) (ch == '-') && (fl = -1);
    for(ret = ch - '0'; isdigit(ch = getchar()); ret *= 10, ret += ch - '0');
    return ret * fl;
}

void print(int x) {
    if(x < 0) putchar('-'), x = -x;
    if(x > 9) print(x / 10);
    putchar(x % 10 + '0');
}

int main() {
    int n = read(), ans = 1;
    do {
        if(n % 2) break;
        else ++ans;
    } while(n >>= 1);
    print(ans);
    return 0;
}