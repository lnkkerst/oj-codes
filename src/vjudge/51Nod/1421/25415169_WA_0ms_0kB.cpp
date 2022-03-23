#include <iostream>
#include <map>
#include <algorithm>
using namespace std;

int n, a[200001];

int main() {
	cin >> n;
	for(int i = 1; i <= n; ++i) cin >> a[i];
	sort(a + 1, a + n + 1, greater<int>());
	int ans = -1;
	for(int i = 1; i <= n - 1; ++i) {
		int pos = i + 1;
		while(pos <= n && (a[i] % a[pos] || ans == -1) && a[pos] > ans)
			ans = max(ans, a[i] % a[pos]), ++pos;
	}
	cout << ans;
	return 0;
}