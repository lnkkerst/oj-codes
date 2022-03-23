#include <cstdio>
#include <cctype>

// const int a[] = {1, 16, 81, 256, 625, 1296, 2401, 4096, 6561, 10000, 14641, 20736, 28561, 38416, 50625, 65536, 83521};

// struct Node {
//     int h, dig;
//     bool vis;
// } a[1010];

// struct Edge {
//     int to, nex;
//     bool vis;
// } e[200010];

int n, m, cnt, ans;
int dig[1010];

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

// void addedge(int u, int v) {
//     e[++cnt] = (Edge){v, a[u].h};
//     a[u].h = cnt, ++a[u].dig;
// }

int main() {
    n = read(), m = read();
    while(m--) ++dig[read()], ++dig[read()];
    for(int i = 1; i <= n; ++i)
        cnt += dig[i] & 1;
    return print(cnt ? cnt / 2 : 1), 0;
}