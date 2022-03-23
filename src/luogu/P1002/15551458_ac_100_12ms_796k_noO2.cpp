#include <cstdio>
#define MAXN 25

int main() {
    bool b[MAXN][MAXN] = {0};
    long long a[MAXN][MAXN] = {0};
    int n, m, x, y;

    scanf("%d%d%d%d", &n, &m, &x, &y);

    x++;
    y++;
    
    b[x][y] = 1;
    b[x + 1][y + 2] = 1;
    b[x + 2][y + 1] = 1;
    b[x - 2][y + 1] = 1;
    b[x - 1][y + 2] = 1;
    b[x - 2][y - 1] = 1;
    b[x - 1][y - 2] = 1;
    b[x + 1][y - 2] = 1;
    b[x + 2][y - 1] = 1;

    a[1][0] = 1;

    for(int i = 1; i <= n + 1; i++)
        for(int j = 1; j <= m + 1; j++)
            if(b[i][j] == 0)
                a[i][j] = a[i - 1][j] + a[i][j - 1];

    printf("%lld", a[n + 1][m + 1]);
    
    return 0;
}