#include <cstdio>
#define MAXN 405

struct queuee {
    int x, y;
}que[40010];

int dx[8] = {2,-2,2,-2,-1,1,-1,1}, dy[8] = {1,1,-1,-1,2,2,-2,-2};
int e[MAXN][MAXN], h = 0, t = 1, n, m, sx, sy;

int main() {
    scanf("%d%d%d%d", &n, &m, &sx, &sy);

    for(int i = 1; i <= n; i++)
        for(int j = 1; j <= m; j++)
            e[i][j] = -1;
    
    e[sx][sy] = 0;

    que[t].x = sx;
    que[t].y = sy;

    while(h < t) {
        h++;
        
        int s = e[que[h].x][que[h].y] + 1;
        
        for(int i = 0 ; i < 8; i++) {
            int nx = que[h].x + dx[i];
            int ny = que[h].y + dy[i];

            if(e[nx][ny] == -1 && nx >= 1 && nx <= n && ny >= 1 && ny <= m) {
                t++;

                que[t].x = nx;
                que[t].y = ny;
                e[nx][ny] = s; 
            }
        }
    }

    for(int i = 1; i <= n; i++) {
        for(int j = 1; j <= m; j++)
            printf("%-5d", e[i][j]);
        
        putchar('\n');
    }

    return 0;
}