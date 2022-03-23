// luogu-judger-enable-o2
#include <cctype>
#include <cstdio>

int read() {
    int res;
    char ch;
    bool flag = 0;
    while(!isdigit(ch = getchar()))
        (ch == '-') && (flag = true);
    for(res = ch - '0'; isdigit(ch = getchar()); res = res * 10 + ch - '0');
    (flag) && (res =-res);
    return res;
}

void print(int x) {
    if(x < 0) {
        putchar('-');
        x = -x;
    }
    if(x > 9)
        print(x / 10);
    putchar(x % 10 + '0');
}

int n;
bool a[(1 << 10) + 1][(1 << 10) + 1];

void work(int lx, int ly, int rx, int ry) {
    if((lx == rx) && (ly = ry))
        return ;
    
    int s = (rx - lx + 1) / 2;

    for(int i = lx ; i <= lx + s - 1; ++i)
        for(int j = ly; j <= ly + s - 1; ++j)
            a[i][j] = 1;

    work(lx, ly + s, rx - s, ry);
    work(lx + s, ly, rx, ry - s);
    work(lx + s, ly + s, rx, ry);
}

int main() {
    n = read();
    n = 1 << n;
    work(1, 1, n, n);
    for(int i = 1; i <= n; ++i, putchar('\n'))
        for(int j = 1; j <= n; ++j, putchar(' '))
            print(!a[i][j]);
    return 0;
}