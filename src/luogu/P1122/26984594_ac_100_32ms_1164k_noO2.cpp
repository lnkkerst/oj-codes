#include <cstdio>
#include <cctype>

struct Edge {
	int to, nex;
} edges[23333 << 1];

int n, ans, cnt;
int a[23333], f[23333];
int h[23333];

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

int max(int x, int y) {
	return x > y ? x : y;
}

void addedge(int u, int v) {
	edges[++cnt] = (Edge){v, h[u]};
	h[u] = cnt;
}

void dfs(int fa, int u) {
	for(int i = h[u]; i; i = edges[i].nex) {
		int v = edges[i].to;
		if(v != fa) {
			dfs(u, v);
			f[u] = max(f[u], f[u] + f[v]);
		}
	}
	ans = max(ans, f[u]);
}

int main() {
	n = read();
	for(int i = 1; i <= n; ++i)
		f[i] = a[i] = read();
	for(int i = 1; i <= n - 1; ++i)	{
		int u = read(), v = read();
		addedge(u, v);
		addedge(v, u);
	}
	dfs(0, 1);
	print(ans);
	return 0;
}