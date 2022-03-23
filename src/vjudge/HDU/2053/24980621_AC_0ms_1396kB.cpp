#include <iostream>
using namespace std;

bool pd(int x) {
	for(int i = 1; x > 0; i += 2)
		x -= i;
	return !x;
}

int main() {
	int x;
	while(cin >> x) cout << pd(x) << endl;
	return 0;
}