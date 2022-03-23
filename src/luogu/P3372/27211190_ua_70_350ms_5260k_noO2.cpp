#include <bits/stdc++.h>
using namespace std;
const int MAXN = 100010;

struct SG_mtree {
	#define lc (x << 1)
	#define rc (x << 1 | 1)
	int ls, rs;
	int sum[MAXN << 2], a[MAXN << 2], tag[MAXN << 2];
	SG_mtree() {
		ls = 1, rs = 0;
		memset(sum, 0, sizeof(sum));
		memset(a, 0, sizeof(a));
		memset(tag, 0, sizeof(0));
	}
	void update(int x) {
		sum[x] = sum[lc] + sum[rc];
	}
	void build(int l, int r, int x) {
		if(l == r) {
			sum[x] = a[l];
			return ;
		}
		int mid = (l + r) >> 1;
		build(l, mid, lc);
		build(mid + 1, r, rc);
		update(x);
	}
	void pushdown(int l, int r, int x) {
		int mid = (r + l)  >> 1;
		if(tag[x]) {
			tag[lc] += tag[x];
			tag[rc] += tag[x];
			sum[lc] += (mid - l + 1) * tag[x];
			sum[rc] += (r - mid) * tag[x];
			tag[x] = 0;
		}
	}
	int query(int a, int b, int l, int r, int x) {
		if(a <= l && b >= r) return sum[x];
		pushdown(l, r, x);
		int mid = (r + l) >> 1, ret = 0;
		if(a <= mid) ret += query(a, b, l, mid, lc);
		if(mid < b) ret += query(a, b, mid + 1, r, rc);
		return ret;
	}
	void add(int a, int b, int v, int l, int r, int x) {
		if(a <= l && r <= b) {
			tag[x] += v;
			sum[x] += v * (r - l + 1);
			return ;
		}
		pushdown(l, r, x);
		int mid = (l + r) >> 1;
		if(a <= mid) add(a, b, v, l, mid, lc);
		if(mid < b) add(a, b, v, mid + 1, r, rc);
		update(x);
	}
} tree;

int read() {
	int ret, f = 1;
	char ch;
	while(!isdigit(ch = getchar())) (ch == '-') && (f = -1);
	for(ret = ch - '0'; isdigit(ch = getchar()); ret *= 10, ret += ch - '0');
	return ret* f;
}

void print(int x) {
	if(x < 0) putchar('-'), x = -x;
	if(x > 9) print(x / 10);
	putchar(x % 10 + '0');
}

int main() {
	int n = read(), m = read();
	for(int i = 1; i <= n; ++i) tree.a[i] = read();
	tree.build(1, n, 1);
	while(m--) {
		int opt = read(), l = read(), r = read();
		if(opt == 1) tree.add(l, r, read(), 1, n, 1);
		else print(tree.query(l, r, 1, n, 1)), putchar('\n');
	}
	return 0;
}