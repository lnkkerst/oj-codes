#include <iostream>
#include <algorithm>
#include <cstdio>
using namespace std;

struct Node {
	int x, y;
	bool operator==(const Node &b) const {
		return (this->x == b.x && this->y == b.y);
	}
	bool operator<(const Node &b) const {
		return x * x + y * y > b.x * b.x + b.y * b.y;
	}
	Node() : x(0), y(0) {}
} ;

void dfs(Node a[], int num[], int n, int m, int dep, int pre, int &ans) {
	if(dep == m + 1) {
		int tmp = 0;
		for(int i = 1; i <= m; ++i) {
			for(int j = i + 1; j <= m; ++j) {
				int tx = a[num[i]].x - a[num[j]].x;
				int ty = a[num[i]].y - a[num[j]].y;
				tmp += tx * tx + ty * ty;
			}
		}
		ans = max(tmp, ans);
		return ;
	}
	for(int i = pre + 1; i <= n; ++i) {
		num[dep] = i;
		dfs(a, num, n, m, dep + 1, i, ans);
	}
}

int main() {
	int t;
	scanf("%d", &t);
	while(t--) {
		int n, r;
		scanf("%d%d", &n, &r);
		Node a[300];
		int cnt = 0;
		for(int i = -r; i <= r; ++i) {
			int pos = 0;
			while(i * i + pos * pos <= r * r) ++pos;
			a[++cnt].x = i;
			a[cnt].y = pos - 1;
			a[++cnt].x = i;
			a[cnt].y = -pos + 1;
		}
		int num[300] = {0};
		int ans = -1;
		dfs(a, num, cnt, n, 1, 0, ans);
		printf("%d\n", ans);
	}
	return 0;
}