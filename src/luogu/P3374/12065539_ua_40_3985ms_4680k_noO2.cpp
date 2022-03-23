#include <iostream>
#define MAXN 500001

using namespace std;

int main() {
	int n, m, a[MAXN], ansn[MAXN] = {0}, ans = 1, x, y, event;
	std::cin >> n >> m;
	for (int i = 1; i <= m; i++)
		cin >> a[i];
	for (int i = 1; i <= n; i++) {
		cin >> event >> x >> y;
		if (event == 1)
			a[x] += y;
		if (event == 2) {
			for (int j = x; j <= y; j++)
				ansn[ans] += a[j];
			ans++;
		}
	}
	for (int i = 1; i < ans; i++)
	cout << ansn[i] << endl;
	return 0;
}