#include <bits/stdc++.h>
using namespace std;

int n, m, t;
bool e[10010][10010], b[10010][10010];
int sx, sy, ex, ey;
int ans;

void dfs(int x, int y) {
    if(x == ex && y == ey) {++ans; return ;}
    if(x < 1 || x > n || y < 1 || y > m || e[x][y] || b[x][y]) return ;
    b[x][y] = 1;
    dfs(x + 1, y);
    dfs(x - 1, y);
    dfs(x, y - 1);
    dfs(x, y + 1);
    b[x][y] = 0;
}

int main() {
    cin >> n >> m >> t;
    cin >> sx >> sy >> ex >> ey;
    for(int i = 1; i <= t; ++i) {
        int t1, t2;
        cin >> t1 >> t2;
        e[t1][t2] = 1;
    }
    dfs(sx, sy);
    printf("%d\n", ans);
    return 0;
}