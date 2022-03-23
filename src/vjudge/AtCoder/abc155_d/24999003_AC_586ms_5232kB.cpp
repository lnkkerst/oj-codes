#include <iostream>
#include <algorithm>
#include <vector>
#define int long long
using namespace std;

int n, k;
vector<int > a[3];

int crank(int x) {
	if(!x) return a[0].size() * a[2].size() + 1;
	int ret = 1;
	vector<int > tmp;
	if(x > 0) {
		for(int i = 0; i < 3; i += 2) {
			for(auto j : a[i]) {
				ret += distance(tmp.begin(), lower_bound(tmp.begin(), tmp.end(), (x + j - 1) / j));
				tmp.push_back(j);
			}
			tmp.clear();
		}
		ret += (a[1].size() * (a[1].size() - 1)) / 2 + a[0].size() * a[2].size() + a[1].size() * (a[0].size() + a[2].size());
	}
	else for(auto i : a[0]) ret += a[2].size() - distance(a[2].begin(), upper_bound(a[2].begin(), a[2].end(), -x / i));
	return ret;
}

signed main() {
    cin >> n >> k;
    for(int i = 1; i <= n; ++i) {
        int x;
        cin >> x;
        if(x > 0) a[0].push_back(x);
        else if(!x) a[1].push_back(x);
        else a[2].push_back(-x);
    }
    for(int i = 0; i < 3; ++i)
        sort(a[i].begin(), a[i].end());
    int l = -1e18, r = 1e18, ans;
    while(l <= r) {
        int mid = (l + r) >> 1;
        int rk = crank(mid);
		if(rk <= k) ans = mid, l = mid + 1;
		else r = mid - 1;
    }
	cout << ans << endl;
    return 0;
}