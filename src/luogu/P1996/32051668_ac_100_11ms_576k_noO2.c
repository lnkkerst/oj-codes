#include <stdio.h>

int n, m, s;
int vis[233];

int main() {
    scanf("%d%d", &n, &m);
    int i, j;
    for(i = 0; i < n; ++i) {
        for(j = 0; j < m; ++j) {
            if(++s > n) s = 1;
            if(vis[s]) --j;
        }
        printf("%d ", s);
        vis[s] = 1;
    }
    return 0;
}