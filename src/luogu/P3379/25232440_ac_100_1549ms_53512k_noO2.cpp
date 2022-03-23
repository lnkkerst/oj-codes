#include <bits/stdc++.h>
using namespace std;

struct Edge {
	int v, nex;
} edges[1000020];

struct Node {
	int head, fa[20], deep;
} nodes[500010];

int n, m, s;
int cnt = 0;
int lg[500010];

int read() {
	int ret;
	bool f = 0;
	char ch;
	while(!isdigit(ch = getchar())) (ch == '-') && (f = 1);
	for(ret = ch - '0'; isdigit(ch = getchar()); ret *= 10, ret += ch - '0');
	return f ? -ret : ret;
}

void print(int x) {
	if(x < 0) {
		putchar('-');
		x = -x;
	}
	if(x > 9) print(x / 10);
	putchar(x % 10 + '0');
}

void addedge(int u, int v) {
	edges[++cnt].v = v;
	edges[cnt].nex = nodes[u].head;
	nodes[u].head = cnt;
}

void dfs_lca(int f, int fa) {
	nodes[f].deep = nodes[fa].deep + 1;
	nodes[f].fa[0] = fa;
	for(int i = 1; (1 << i) <= nodes[f].deep; ++i)
		nodes[f].fa[i] = nodes[nodes[f].fa[i - 1]].fa[i - 1];
	for(int i = nodes[f].head; i; i = edges[i].nex)
		if(edges[i].v != fa)
			dfs_lca(edges[i].v, f);
}

int calc_lca(int x, int y) {
	if(nodes[x].deep < nodes[y].deep) swap(x, y);
	while(nodes[x].deep > nodes[y].deep) x = nodes[x].fa[lg[nodes[x].deep - nodes[y].deep] - 1];
	if(x == y) return x;
	for(int k = lg[nodes[x].deep] - 1; k >= 0; --k)
		if(nodes[x].fa[k] != nodes[y].fa[k])
			x = nodes[x].fa[k], y = nodes[y].fa[k];
	return nodes[x].fa[0];
}

int main() {
	n =read(), m = read(), s = read();
	for(int i = 1; i < n; ++i) {
		int t1 = read(), t2 = read();
		addedge(t1, t2);
		addedge(t2, t1);
	}
	for(int i = 1; i <= n; ++i)
		lg[i] = lg[i - 1] + (1 << lg[i - 1] == i);
	dfs_lca(s, 0);
	for(int i = 1; i <= m; ++i) {
		int t1 =read(), t2 = read();
		print(calc_lca(t1, t2));
        putchar('\n');
	}
	return 0;
}
