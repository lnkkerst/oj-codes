#include <iostream>
#include <hash_map>
#include <cstdio>
using namespace std;
using namespace __gnu_cxx;

int f[2][1000010];
int n;
hash_map<int, int> id;
int cnt;

int find(int fa[], int x) {
	return x == fa[x] ? x : fa[x] = find(fa, fa[x]);
}

void merge(int fa[], int u, int v) {
	fa[find(fa, u)] = find(fa, v);
}

int main() {
	int t;
	cin >> t;
	while(t--) {
		int n;
		cin >> n;
		for(int i = 1; i <= n; ++i)
			f[0][i] = f[1][i] = i;
		bool fl = 0;
		for(int i = 1; i <= n; ++i) {
			int u, v, opt;
			cin >> u >> v >> opt;
			if(fl) continue;
			if(!id[u]) id[u] = ++cnt;
			if(!id[v]) id[v] = ++cnt;
			if(find(f[!opt], id[u]) == find(f[!opt], id[v])) {
				puts("NO");
				fl = 1;
			}
			merge(f[opt], id[u], id[v]);
		}
		puts("YES");
		id.clear();
	}
	return 0;
}