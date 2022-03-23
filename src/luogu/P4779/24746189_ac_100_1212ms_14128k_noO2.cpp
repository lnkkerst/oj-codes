#include <bits/stdc++.h>
using namespace std;

struct Edge {
	int v, w, nex;
} edges[4000010];

struct Node {
	int h, dis;
} nodes[1000010];

int read() {
	int ret;
	char ch;
	bool flag = 0;
	while(!isdigit(ch = getchar())) (ch == '-') && (flag = 1);
	for(ret = ch - '0'; isdigit(ch = getchar()); ret *= 10, ret += ch - '0');
	return flag ? -ret : ret;
}

int n, m, s, cnt;

void addedge(int w, int v, int u) {
	edges[++cnt] = (struct Edge){v, w, nodes[u].h};
	nodes[u].h = cnt;
}

void dij(int s) {
	for(int i = 1; i <= n; ++i) nodes[i].dis = (int)1e9;
	nodes[s].dis = 0;
	set<pair<int, int > > heap;
	for(int i = 1; i <= n; ++i) heap.insert(make_pair(nodes[i].dis, i));
	while(!heap.empty()) {
		int d = heap.begin()->first;
		int u = heap.begin()->second;
		heap.erase(heap.begin());
		if(d > nodes[u].dis) continue;
		for(int i = nodes[u].h; i; i = edges[i].nex) 
			if(nodes[u].dis + edges[i].w < nodes[edges[i].v].dis) {
				nodes[edges[i].v].dis = nodes[u].dis + edges[i].w;
				heap.insert(make_pair(nodes[edges[i].v].dis, edges[i].v));
			}
	} 
}

int main() {
	n = read(), m = read(), s = read();
	for(int i = 1; i <= m; ++i) addedge(read(), read(), read());
	dij(s);
	for(int i = 1; i <= n; ++i) printf("%d ", nodes[i].dis);
	return 0;
}
