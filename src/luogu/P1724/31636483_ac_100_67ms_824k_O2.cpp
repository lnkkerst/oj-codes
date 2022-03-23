#include <cstdio>
#include <cctype>

int t, n = 0, cnt[6], ansx, ansy;
char a[5010];

inline int read() {
    int ret, fl = 1;
    char ch;
    while(!isdigit(ch = getchar()))
        (ch == '-') && (fl = -1);
    ret = ch - '0';
    while(isdigit(ch = getchar()))
        ret *= 10, ret += ch - '0';
    return ret * fl;
}

inline void print(int x) {
    if(x < 0) putchar('-'), x = -x;
    if(x > 9) print(x / 10);
    putchar(x % 10 + '0');
}

inline int pre(char ch) {
    if(ch == 'N') return 0;
    if(ch == 'S') return 1;
    if(ch == 'W') return 2;
    if(ch == 'E') return 3;
    return 4;
}

int main() {
    char ch;
    while(isalpha(ch = getchar()))
        a[++n] = ch, ++cnt[pre(ch)];
    t = read();
    int tmp = t / n;
    ansx += cnt[3] * tmp, ansx -= cnt[2] * tmp;
    ansy += cnt[0] * tmp, ansy -= cnt[1] * tmp;
    tmp = t % n;
    for(int i = 1; i <= tmp; ++i) {
        if(a[i] == 'N') ++ansy;
        if(a[i] == 'S') --ansy;
        if(a[i] == 'E') ++ansx;
        if(a[i] == 'W') --ansx;
    }
    print(ansx), putchar(' '), print(ansy);
    return 0;
}