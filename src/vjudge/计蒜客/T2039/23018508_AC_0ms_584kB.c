#include <stdio.h>
#include <ctype.h>

const int dx[] = {0, 1, 0, -1}, dy[] = {1, 0, -1, 0};
int f[233][233], e[233][233];
int n, m, ans = (int)1e9 + 7;

int read() {
	int ret, f = 1;
	char ch;
	while(!isdigit(ch = getchar())) (ch == '-') && (f = -1);
	for(ret = ch - '0'; isdigit(ch = getchar()); ret *= 10, ret += ch - '0');
	return ret * f;
}

void print(int x) {
	if(x < 0) putchar('-'), x = -x;
	if(x > 9) print(x / 10);
	putchar(x % 10 + '0');
}

void dfs(int x, int y, int sum, int fl) {
	if(x < 1 || y < 1 || x > n || y > n || sum >= f[x][y]) return ;
	f[x][y] = sum;
	if(x == n && y == n) {
		ans = ans < sum ? ans : sum;
		return ;
	}
	for(int i = 0; i < 4; ++i) {
		int nx = x + dx[i], ny = y + dy[i];
		if(e[nx][ny]) {
			if(e[nx][ny] == e[x][y]) dfs(nx, ny, sum, 0);
			else dfs(nx, ny, sum + 1, 0);
		}
		else if(!fl) {
			e[nx][ny] = e[x][y];
			dfs(nx, ny, sum + 2, 1);
			e[nx][ny] = 0;
		}
	}
}

int main() {
	n = read(), m = read();
	for(int i = 0; i <= n; ++i)
		for(int j = 0; j <= n; ++j)
			f[i][j] = (int)1e9 + 7;
	for(int i = 1; i <= m; ++i) {
		int x = read(), y = read(), cl = read();
		e[x][y] = cl + 1;
	} dfs(1, 1, 0, 0);
	if(ans == (int)1e9 + 7) print(-1);
	else print(ans);
	return 0;
}