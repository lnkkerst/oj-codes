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
        int x = read();
        bool fl = 1;
        for(int i = 2; i * i * i <= x && fl; ++i)
            for(int j = i + 1; i * j * j <= x && fl; ++j) {
                int t = x / (i * j);
                if(t > j && i * j * t == x)
                    printf("YES\n%d %d %d\n", i, j, t),
                    fl = 0;
            }
        if(fl) puts("NO");
    }
    return 0;
}