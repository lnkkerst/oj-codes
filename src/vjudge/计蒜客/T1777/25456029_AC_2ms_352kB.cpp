#include <iostream>
using namespace std;

int main() {
	int h, a, b;
	cin >> h >> a >> b;
	if(b >= a) {
		if(a > h) {
			puts("YES");
			cout << 1;
			return 0;
		}
		puts("NO");
		return 0;
	}
	puts("YES");
	int ans = 0, now = 0;
	while(1) {
		++ans;
		now += a;
		if(now > h) break;
		now -= b;
	}
	cout << ans << endl;
}