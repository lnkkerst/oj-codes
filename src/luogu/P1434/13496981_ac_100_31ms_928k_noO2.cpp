#include <algorithm>
#include <cstring>
#include <cstdio>
#define MAXN 200

int h[MAXN][MAXN], dp[MAXN][MAXN];
int r, c;
int dfs(int x, int y) {
    if(dp[x][y])
		return dp[x][y];
    int i, j;
    dp[x][y] = 1;
    if(x > 0 && h[x - 1][y] < h[x][y])
		dp[x][y] = std::max(dfs(x - 1, y) + 1, dp[x][y]);
    if(y > 0 && h [x][y - 1] < h[x][y])
		dp[x][y] = std::max(dfs(x, y - 1) + 1, dp[x][y]);
    if(x < r - 1 && h[x + 1][y] < h[x][y])
		dp[x][y] = std::max(dfs(x + 1, y) + 1, dp[x][y]);
    if(y < r - 1 && h[x][y + 1] < h[x][y])
		dp[x][y] = std::max(dfs(x, y + 1) + 1, dp[x][y]);
    return dp[x][y];
}
int main() {
    scanf("%d%d", &r, &c);
    int i, j, m, n, tmp = 0, ans = 0;
	for(i = 0; i < r; i++)
        for(j = 0; j < c; j++)
            scanf("%d", &h[i][j]);
    memset(dp, 0, sizeof(dp));
    for(i = 0; i < r; i++)
        for(j = 0; j < c; j++) {
        	if(dfs(i, j) > ans)
				ans = dfs(i, j);
    	}
    printf("%d", ans);
    return 0;
}