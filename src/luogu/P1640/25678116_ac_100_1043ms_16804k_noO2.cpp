#include <bits/stdc++.h>
using namespace std;

struct Node {
	int h, pre;
	bool vis;
} nodes[1000001];

struct Edge {
	int to, nex;
} edges[2000001];

int n, cnt, ans;

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

void addedge(int u, int v) {
	edges[++cnt].to = v;
	edges[cnt].nex = nodes[u].h;
	nodes[u].h = cnt;
}

bool dfs(int u) {
	if(nodes[u].vis) return 0;
	nodes[u].vis = 1;
	for(int i = nodes[u].h; i; i = edges[i].nex) {
		if(!nodes[edges[i].to].pre || dfs(nodes[edges[i].to].pre)) {
			nodes[edges[i].to].pre = u;
			return 1;
		}
	}
	return 0;
}

int main() {
	n = read();
	for(int i = 1; i <= n; ++i) {
		int t1 = read(), t2 = read();
		addedge(t1, i);
		addedge(t2, i);
	}
	for(int i = 1; i <= 10000; ++i) {
		for(int j = 1; j <= 10000; ++j) nodes[j].vis = 0;
		if(dfs(i)) ++ans;
		else break;
	}
	print(ans);
	return 0;
}