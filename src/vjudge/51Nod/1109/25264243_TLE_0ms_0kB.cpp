#include <iostream>
#include <algorithm>
using namespace std;
typedef long long ll;

int main() {
	ll x;
	cin >> x;
	ll n = x;
	while(n <= 0x7fffffffffffffff) {
		auto s = to_string(n);
		if(*max_element(s.begin(), s.end()) <= '1') {
			cout << s;
			return 0;
		}
		n += x;
	}
}