#include <iostream>
#include <iomanip>
using namespace std;

int main() {
	int n;
	cin >> n;
	cout << (n * (n - 1) / 2 * (n - 2) / 3 * (n - 3) / 4);
	return 0;
}