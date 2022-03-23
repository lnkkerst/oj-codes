#include <bits/stdc++.h>
using namespace std;

struct Node {
	int h, pre;
	bool vis;
} nodes[10001];

struct Edge {
	int to, nex;
} edges[10001 * 10001];

int n, m, e, cnt, ans;

void addedge(int u, int v) {
	edges[++cnt].to = v;
	edges[cnt].nex = nodes[u].h;
	nodes[u].h = cnt;
}

bool dfs(int u) {
	if(nodes[u].vis) return 0;
	nodes[u].vis = 1;
	for(int i = 1; i; i = edges[i].nex) {
		if(!nodes[edges[i].to].pre || dfs(nodes[edges[i].to].pre)) {
			nodes[edges[i].to].pre = u;
			return 1;
		}
	}
	return 0;
}

int main() {
	cin >> n >> m >> e;
	for(int i = 1; i <= e; ++i) {
		int t1, t2;
		cin >> t1 >> t2;
		if(t1 <= n && t2 <= m) addedge(t1, t2 + n);
	}
	for(int i = 1; i <= n + m; ++i) {
		for(int j = 1; j <= n + m; ++j) nodes[j].vis = 0;
		if(dfs(i)) ++ans;
		else break;
	}
	cout << ans << endl;
}