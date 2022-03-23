#include <iostream>
using namespace std;

int solve1(int x) {
	int ret = 0;
	do {
		ret += x % 10;
		x /= 10;
	} while(x);
	return ret;
}

int solve(int x) {
	int ret = 0;
	while(x >= 10) {
		ret += x;
		x = solve1(x);
	}
	return ret + x;
}

int main() {
	int x;
	cin >> x;
	for(int i = max(x - 1000000, 1); i <= x; ++i)
		if(solve(i) == x) {
			cout << i;
			return 0;
		}
	cout << -1;
	return 0;
}