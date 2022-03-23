#include <bits/stdc++.h>
using namespace std;

int n, m;
int e[31][31];

void dfs(int x, int y) {
    if(x < 1 || x > n || y < 1 || y > m || e[x][y] != 0) return ;
    e[x][y] = 2;
    dfs(x + 1, y);
    dfs(x - 1, y);
    dfs(x, y + 1);
    dfs(x, y - 1);
}

int main() {
    cin >> n;
    m = n;
    for(int i = 1; i <= n; ++i)
        for(int j = 1; j <= m; ++j)
            cin >> e[i][j];
    for(int i = 1; i <= n; ++i)
        for(int j = 1; j <= m; ++j)
            if(e[i][j]) {
                dfs(i + 1, j + 1);
                break;
            }
    for(int i = 1; i <= n; ++i, cout << endl)
        for(int j = 1; j <= m; ++j)
            cout << e[i][j] << ' ';
    return 0;
}