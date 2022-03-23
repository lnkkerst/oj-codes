#include <iostream>
using namespace std;

int n;
string ans = "1";

void dfs(int st, int mod, int num) {
	if(!mod) {
		cout << ans;
		exit(0);
	}
	if(st >= num) return ;
	ans.push_back('0');
	dfs(st + 1, (mod * 10) % n, num);
	ans.back() = '1';
	dfs(st + 1, (mod * 10 + 1) % n, num);
	ans.pop_back();
}

int main() {
	cin >> n;
	for(int i = 1; ; ++i) dfs(0, 1, i);
}