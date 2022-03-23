#include <cstdio>

int n, m, cem;
bool e[16][16], t[16][16];
int ans[16][16], ansn = (int)1e9;
int tmp[16][16];
bool f[16][16];
bool em[16];
int dx[] = {0, 1, 0, -1}, dy[] = {1, 0, -1, 0};

bool check() {
	for(int i = 0; i < m; ++i)
		if(t[n - 1][i]) return 0;
	return 1;
}

void init() {
	for(int i = 0; i < n; ++i)
		for(int j = 0; j < m; ++j)
			t[i][j] = e[i][j], f[i][j] = 0;
}

void fz(int x, int y, int o) {
	// tmp[x][y] = !tmp[x][y];
	if(!o) return ;
	else f[x][y] = !f[x][y];
	t[x][y] = !t[x][y];
	for(int i = 0; i < 4; ++i) {
		int nx = x + dx[i], ny = y + dy[i];
		if(x >= 0 && x < n && y >= 0 && y < n)
			t[nx][ny] = !t[nx][ny];
	}
}

void emm(int x) {
	if(x == 0) return ;
	emm(x / 2);
	em[cem++] = x % 2;
}

void work(int y) {
	int x = y;
	init();
	int cnt = 0, now = 0;
	for(int i = 0; i < m; ++i) {
		cnt += x & 1;
		fz(0, now, x & 1);
		x >>= 1, ++now;
	}
	for(int i = 1; i < n; ++i)
		for(int j = 0; j < m; ++j)
			cnt += t[i - 1][j],
			tmp[i - 1][j] = t[i - 1][j],
			fz(i, j, t[i - 1][j]);
	if(check()) {
		if(cnt < ansn) {
			ansn = cnt;
			for(int i = 0; i < n; ++i)
				for(int j = 0; j < m; ++j)
					ans[i][j] = f[i][j];
			cem = 0;
			emm(y);
			for(int i = 0; i < m; ++i) ans[0][i] = t[0][i] ^ em[i];
		}
	}
}

int main() {
	scanf("%d%d", &n, &m);
	for(int i = 0; i < n; ++i)
		for(int j = 0; j < m; ++j)	{
			char ch = getchar();
			while(ch != '1' && ch != '0')
				ch = getchar();
			e[i][j] = ch - '0';
		}
	for(int i = 0; i < 1 << n; ++i)
		work(i);
	if(ansn == (int)1e9) {
		printf("IMPOSSIBLE\n");
		return 0;
	}
	for(int i = 0; i < n; ++i, putchar('\n'))
		for(int j = 0; j < m; ++j, putchar(' '))
			printf("%d", ans[i][j]);
	return 0;
}