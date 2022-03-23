#include <cstdio>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/hash_policy.hpp>
#include <cctype>
using namespace std;
using namespace __gnu_pbds;

gp_hash_table<int, int> b;

int read() {
	int ret, fl = 1;
	char ch;
	while(!isdigit(ch = getchar()))
		(ch == '-') && (fl = -1);
	ret = ch - '0';
	while(isdigit(ch = getchar()))
		ret *= 10, ret += ch - '0';
	return ret * fl;
}
int main() {
	int n = read(), k = read();
	for(int i = 1; i <= n; ++i) {
		int x = read();
		auto cnt = b.find(x);
		if(cnt != b.end() && !((cnt->second + 1) % k)) b.erase(x);
		else ++b[x];
	}
	
	for(auto i : b) {
		if(i.second % k) {
			printf("%d", i.first);
			break;
		}
	}
	return 0;
}