#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int main() {
	vector<int> a;
	int n;
	cin >> n;
	for(int i = 1; i <= n; ++i) {
		int x;
		cin >> x;
		a.push_back(x);
	}
	while(!is_sorted(a.begin(), a.end(), less<int>()))
		random_shuffle(a.begin(), a.end());
	for(auto &i : a) {
		cout << i << ' ';
	}
}