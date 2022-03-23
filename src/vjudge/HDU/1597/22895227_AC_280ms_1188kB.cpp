#include <cstdio>
#include <cctype>

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
    int t = read();
    while(t--) {
        int x = read(), tmp = 1;
        while(x > tmp) x -= tmp++;
        print(x % 9 ? x % 9 : 9);
        putchar('\n');
    }
    return 0;
}