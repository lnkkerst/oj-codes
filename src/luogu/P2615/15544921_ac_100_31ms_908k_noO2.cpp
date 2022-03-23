#include <cstdio>

int main() {
    int n, a[40][40] = {0};

    scanf("%d", &n);

    int x = 1, y = n / 2 + 1;

    a[x][y] = 1;

    for(int i = 2; i <= n * n; i++) {
        if(x == 1 && y != n) {
            x = n;
            y++;
        }
        else if(y == n && x != 1) {
            y = 1;
            x--;
        }
        else if(x == 1 && y == n) {
            x++;
        }
        else if(x != 1 && y != n && a[x - 1][y + 1] == 0) {
            x--;
            y++;
        }
        else
            x++;

        a[x][y] = i;
    }

    for(int i = 1; i <= n; i++) {
        for(int j = 1; j <= n; j++)
            printf("%d ", a[i][j]);
        
        putchar('\n');
    }

    return 0;
}