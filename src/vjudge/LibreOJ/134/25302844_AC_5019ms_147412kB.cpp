#include <iostream>
#define int long long
using namespace std;

int a[10000][10000];
int n, m;

int lb(int x) {
	return x & -x;
}

void add(int x, int y, int v) {
	for(int i = x; i <= n; i += lb(i))
		for(int j = y; j <= m; j += lb(j))
			a[i][j] += v;
}

void addRange(int x1, int y1, int x2, int y2, int v) {
	add(x1, y1, v);
	add(x1, y2 + 1, -v);
	add(x2 + 1, y1, -v);
	add(x2 + 1, y2 + 1, v);
}

int query(int x, int y) {
	int ret = 0;
	for(int i = x; i; i -= lb(i))
		for(int j = y; j; j -= lb(j))
			ret += a[i][j];
	return ret;
}

signed main() {
	ios::sync_with_stdio(0);
	cin.tie(nullptr);
	cin >> n >> m;
	int opt;
	while(cin >> opt) {
		if(opt == 1) {
			int x1, x2, y1, y2, val;
			cin >> x1 >> y1 >> x2 >> y2 >> val;
			addRange(x1, y1, x2, y2, val);
		}
		else if(opt == 2) {
			int x, y;
			cin >> x >> y;
			cout << query(x, y) << endl;
		}
	}
	return 0;
}