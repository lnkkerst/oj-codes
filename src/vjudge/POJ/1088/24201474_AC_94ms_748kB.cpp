#include <iostream>
using namespace std;

int n, m;
int f[110][110], a[110][110];
const int dx[] = {0, 1, 0, -1}, dy[] = {1, 0, -1, 0};

int solve(int x, int y) {
	if(f[x][y] > 1) return f[x][y];
	for(int i = 0; i < 4; ++i) {
		int nx = x + dx[i], ny = y + dy[i];
		if(nx >= 1 && nx <= n && ny >= 1 && ny <= m && a[nx][ny] < a[x][y])
			f[x][y] = max(f[x][y], solve(nx, ny) + 1);
	}
	return f[x][y];
}

int main() {
	cin >> n >> m;
	for(int i = 1; i <= n; ++i)
		for(int j = 1; j <= m; ++j)
			f[i][j] = 1, cin >> a[i][j];
	int ans = -1;
	for(int i = 1; i <= n; ++i)
		for(int j = 1; j <= m; ++j)
			ans = max(solve(i, j), ans);
	cout << ans;
	return 0;
}