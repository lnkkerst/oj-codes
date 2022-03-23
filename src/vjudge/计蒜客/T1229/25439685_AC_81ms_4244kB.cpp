#pragma GCC optimize(2)
#include <iostream>
#include <cstdio>
#include <unordered_map>
using namespace std;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(nullptr);
	cout.tie(nullptr);
	int n;
	cin >> n;
	unordered_map<int, int> a;
	unordered_map<int, bool > b;
	for(int i = 1; i <= n; ++i) {
		string opt;
		int x;
		cin >> opt >> x;
		if(opt == "add") {
			++a[x];
			cout << a[x] << '\n';
			b[x] = 1;
		}
		else if(opt == "ask") {
			cout << b[x] << ' ' << a[x] << '\n';
		}
		else {
			cout << a[x] << '\n';
			a[x] = 0;
		}
	}
	return 0;
}