#include <cstdio>

int n;
bool a[3000][3000];

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
    scanf("%d", &n);
    n = 1 << n;
    work(1, 1, n, n);
    for(int i = 1; i <= n; ++i, putchar('\n'))
        for(int j = 1; j <= n; ++j, putchar(' '))
            printf("%d", !a[i][j]);
    return 0;
}