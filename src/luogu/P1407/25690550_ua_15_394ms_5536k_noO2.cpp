#include <bits/stdc++.h>
using namespace std;

struct Node {
	int h, pre, dfn, low;
	bool vis;
	bool ins;
	int col;
	int ru;
	int du;
} nodes[100001];

struct Edge {
	int to, nex;
} edges[5000001];

int n, m, cnt, ans, sum;
int cnt_dfn, cnt_tj;
stack<int > tj;
map<string , int > couple;

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

void tarjan(int u) {
	nodes[u].low =nodes[u].dfn = ++cnt_dfn;
	tj.push(u);
	nodes[u].ins = 1;
	for(int i = nodes[u].h; i; i = edges[i].nex) {
		int v = edges[i].to;
		if(!nodes[v].dfn) tarjan(v), nodes[u].low = min(nodes[u].low, nodes[v].low);
		else if(nodes[v].ins) nodes[u].low = min(nodes[u].low, nodes[v].dfn);
	}
	if(nodes[u].low == nodes[u].dfn) {
		++cnt_tj;
		int now;
		do {
			now = tj.top();
			tj.pop();
			nodes[now].ins = 0;
			nodes[now].col = cnt_tj;
		} while(u != now);
	}
}

int main() {
	n = read();
	string boy, girl;
	for(int i = 1; i <= n; ++i) {
		cin >> girl >> boy;
		couple[girl] = i;
		couple[boy] = i + n;
		addedge(i, n + i);
	}
	m = read();
	for(int i = 1; i <= m; ++i) {
		cin >> girl >> boy;
		addedge(couple[boy], couple[girl]);
	}
	for(int i = 1; i <= n * 2; ++i)
		if(!nodes[i].dfn) tarjan(i);
	for(int i = 1; i <= n; ++i)
		if(nodes[i].col == nodes[i + n].col) printf("Usafe\n");
		else printf("Safe\n");
	return 0;
}