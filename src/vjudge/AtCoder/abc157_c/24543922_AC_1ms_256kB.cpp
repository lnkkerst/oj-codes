#include <iostream>
#include <vector>
using namespace std;

int n, m;
int a[23];
bool b[23];
bool fl = 1;

int main() {
	cin >> n >> m;
	while(m--) {
		int x, y;
		cin >> x >> y;
		if(a[x] != 0 && a[x] != y) {
			fl = 0;
			break;
		}
		a[x] = y;
		b[x] = 1;
	}
	if(!fl) {
		cout << "-1";
		return 0;
	}
	if(n != 1 && !a[1]) {
		if(b[1]) {
			cout << "-1";
			return 0;
		}
		else a[1] = 1;
	}
	for(int i = 1; i <= n; ++i)
		cout << a[i];
	return 0;
}