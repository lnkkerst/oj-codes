#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

struct Tree {
	int cnt;
	vector<int> sum;
	vector<int> ls, rs;
	Tree(int n) : cnt(0), sum(n), ls(n), rs(n) {};
	int build(int l, int r) {
		++cnt;
		sum[cnt] = 0;
		int mid = (l + r) >> 1;
		if(l < r) 
			ls[cnt] = build(l, mid),
			rs[cnt] = build(mid + 1, r);
		return cnt;
	}
	int updatef(int pre, int l, int r, int x) {
		++cnt;
		ls[cnt] = ls[pre];
		rs[cnt] = rs[pre];
		sum[cnt] = sum[pre] + 1;
		int mid = (l + r) >> 1;
		if(l < r) {
			if(x <= mid) ls[cnt] = update(ls[pre], l, mid, x);
			else rs[cnt] = update(rs[pre], mid + 1, r, x);
		}
		return cnt;
	}
	inline int updateff(int pre, int l, int r, int x) {
		++cnt;
		ls[cnt] = ls[pre], rs[cnt] = rs[pre], sum[cnt] = sum[pre];
		if(l < r) {
			int mid = (l + r) >> 1;
			if(x <= mid) ls[cnt] = update(ls[pre], l, mid, x);
			else rs[cnt] = update(rs[cnt], mid + 1, r, x);
		}
		return cnt;
	}
	int update(int pre, int l, int r, int x) {
		int rt = ++cnt;
		ls[rt] = ls[pre]; rs[rt] = rs[pre]; sum[rt] = sum[pre]+1;
		if (l < r){
			int mid = (l + r) >> 1;
			if (x <= mid) ls[rt] = update(ls[pre], l, mid, x);
			else rs[rt] = update(rs[pre], mid + 1, r, x);
		}
		return rt;
	}
	int query(int a, int b, int l, int r, int k) {
		if(l >= r) return l;
		int t = sum[ls[b]] - sum[ls[a]];
		int mid = (l + r) >> 1; 
		if(t >= k) return query(ls[a], ls[b], l, mid, k);
		else return query(rs[a], rs[b], mid + 1, r, k - t);
	}
} ;

int main() {
	int n, q;
	cin >> n >> q;
	vector<int> a(n + 1), b(n + 1), tree(n + n);
	Tree base((n + 1) << 5);
	for(int i = 1; i <= n; ++i)
		cin >> a[i], b[i] = a[i];
	sort(b.begin() + 1, b.end());
	b.erase(unique(b.begin() + 1, b.end()), b.end());
	tree[0] = base.build(1, b.size() - 1);
	for(int i = 1; i <= n; ++i) {
		int t = lower_bound(b.begin() + 1, b.end(), a[i]) - b.begin();
		tree[i] = base.update(tree[i - 1], 1, b.size() - 1, t);
	}
	while(q--) {
		int l, r, k;
		cin >> l >> r >> k;
		int pos = base.query(tree[l - 1], tree[r], 1, b.size() - 1, k);
		cout << b[pos] << endl;
	}
	return 0;
}