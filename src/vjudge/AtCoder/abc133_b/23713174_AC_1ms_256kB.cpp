// #include <iostream>
// #include <vector>
// #include <algorithm>
// #define int long long
// using namespace std;

// struct Node {
// 	string name;
// 	int w, v;
// } a[1000010];

// bool cmp(Node a, Node b) {
// 	return a.v > b.v;
// }

// void work(int n, int k) {
// 	for(int i = 1; i <= n; ++i)
// 		cin >> a[i].name >> a[i].w >> a[i].v;
// 	stable_sort(a + 1, a + n + 1, cmp);
// 	int maxx = -1, pos = 1, ans = 0, maxp;
// 	while(k && pos <= n) {
// 		if(a[pos].w <= k) {
// 			k -= a[pos].w;
// 			ans += a[pos].w * a[pos].v;
// 			if(maxx < a[pos].w * a[pos].v)
// 				maxx = a[pos].w * a[pos].v, maxp = pos;
// 		}
// 		else {
// 			ans += a[pos].v * k;
// 			if(maxx < a[pos].v * k)
// 				maxx = a[pos].v * k, maxp = pos;
// 			k = 0;
// 		}
// 		++pos;
// 	}
// 	cout << ans << endl << a[maxp].name << ' ' << maxx << endl;
// } 

// signed main() {
// 	ios::sync_with_stdio(0);
// 	cin.tie(NULL);
// 	int n, k;
// 	while(cin >> n >> k) work(n, k);
// 	return 0;
// }

#include <iostream>
#include <cmath>
using namespace std;

double dis[23][23];
int n, x, ans = 0;
double eps = 1e-7;

double calc(int a, int b) {
	double ret = 0;
	for(int i = 1; i <= x; ++i)
		ret += (dis[a][i] - dis[b][i]) * (dis[a][i] - dis[b][i]);
	return sqrt(ret);
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(NULL);
	cin >> n >> x;
	for(int i = 1; i <= n; ++i)
		for(int j = 1; j <= x; ++j)
			cin >> dis[i][j];
	for(int i = 1; i <= n; ++i)
		for(int j = i + 1; j <= n; ++j) {
			double dist = calc(i, j);
			// cout << i << ' ' << j << ' ' << dist << endl;
			if(fabs(dist) - floor(dist) <= eps) ++ans;
		}
	cout << ans;
	return 0;
}