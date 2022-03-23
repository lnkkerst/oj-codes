#include <iostream>
#include <iomanip>
#include <cmath>
using namespace std;

int main() {
	int a, b, c;
	cin >> a >> b >> c;
	if(!b) cout << a;
	else cout << a - min(int(a), int(ceil(c / b)));
	return 0;
}