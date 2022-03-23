#include <bits/stdc++.h>
using namespace std;

struct Node {
	int h, pre;
	bool vis;
} nodes[2333];

struct Edge {
	int to, nex;
} edges[2333 * 2333];

struct Point {
    int x, y;
} a[2333];

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
    for(int i = 1; i <= n; ++i)
        a[i].x = read(), a[i].y = read();
    for(int i = 1; i <= n; ++i)
        a[n + i].x = read(), a[n + i].y = read();
    for(int i = 1; i <= n; ++i)
        for(int j = n + 1; j <= n * 2; ++j)
            if(a[i].x < a[j].x && a[i].y < a[j].y)
                addedge(i, j);
    for(int i = 1; i <= n; ++i) {
        for(int j = 1; j <= n + cnt; ++j)
            nodes[j].vis = 0;
        if(dfs(i)) ++ans;
    }
    print(ans);
    return 0;
}