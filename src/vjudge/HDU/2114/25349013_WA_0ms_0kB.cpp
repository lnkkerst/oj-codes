#include <iostream>
#include <cstdio>
#define int long long
using namespace std;

signed main() {
	int x;
	while(cin >> x) {
		printf("%04lld\n", (((x * (x + 1)) >> 1) % 10000 * ((x * (x + 1)) >> 1) % 10000) % 10000);
	}
	return 0;
}