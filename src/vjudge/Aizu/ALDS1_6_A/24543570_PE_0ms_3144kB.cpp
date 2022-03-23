#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector<int > a;
int n;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(NULL);
	cin >> n;
	while(n--) {
		int x;
		cin >> x;
		a.push_back(x);
	}
	sort(a.begin(), a.end());
	for(auto i = a.begin(); i != a.end() - 1; ++i)
		cout << *i << ' ';
	cout << *(a.end() - 1);
	return 0;
}