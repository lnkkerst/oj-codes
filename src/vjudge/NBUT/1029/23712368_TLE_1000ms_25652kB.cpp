#include <iostream>
#include <vector>
#include <algorithm>
#define int long long
using namespace std;

struct Node {
	string name;
	int w, v;
} a[1000010];

bool cmp(Node a, Node b) {
	return a.v > b.v;
}

void work(int n, int k) {
	for(int i = 1; i <= n; ++i)
		cin >> a[i].name >> a[i].w >> a[i].v;
	sort(a + 1, a + n + 1, cmp);
	int maxx = -1, pos = 1, ans = 0, maxp;
	while(k) {
		if(a[pos].w <= k) {
			k -= a[pos].w;
			ans += a[pos].w * a[pos].v;
			if(maxx < a[pos].w * a[pos].v)
				maxx = a[pos].w * a[pos].v, maxp = pos;
		}
		else {
			ans += a[pos].v * k;
			if(maxx < a[pos].v * k)
				maxx = a[pos].v * k, maxp = pos;
			k = 0;
		}
		++pos;
	}
	cout << ans << endl << a[maxp].name << ' ' << maxx << endl;
} 

signed main() {
	int n, k;
	while(cin >> n >> k) work(n, k);
	return 0;
}