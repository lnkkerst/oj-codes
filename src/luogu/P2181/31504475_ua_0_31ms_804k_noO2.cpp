#include <iostream>
#include <iomanip>
using namespace std;

int main() {
	int n;
	cin >> n;
	cout << ((n * (n - 1)) >> 1);
	return 0;
}