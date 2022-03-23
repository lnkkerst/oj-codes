#include <iostream>
using namespace std;

int main() {
	int h, a, b;
	cin >> h >> a >> b;
	if(b >= a) {
		puts("NO");
		return 0;
	}
	puts("YES");
	cout << (h - a) / (a - b) + 1;
	return 0;
}