#include <cstdio>
#include <cctype>

int n, f[233][233], root[233][233];
int a[233];

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

void dfs(int l, int r) {
	if(l > r) return ;
	if(l == r) {
		print(l), putchar(' ');
		return ;
	}
	print(root[l][r]), putchar(' ');
	dfs(l, root[l][r] - 1);
	dfs(root[l][r] + 1, r);
}

int main() {
	n = read();
	for(int i = 1; i <= n; ++i) a[i] = read();
	for(int i = 1; i <= n; ++i) f[i][i] = a[i], f[i][i - 1] = 1;
	for(int i = n; i >= 1; --i)
		for(int j = i + 1; j <= n; ++j)
			for(int k = i; k <= j; ++k)
				if(f[i][j] < (f[i][k - 1] * f[k + 1][j] + f[k][k])) {
					f[i][j] = f[i][k - 1] * f[k + 1][j] + f[k][k];
					root[i][j] = k;
				}
	print(f[1][n]), putchar('\n');
	dfs(1, n);
	return 0;
}