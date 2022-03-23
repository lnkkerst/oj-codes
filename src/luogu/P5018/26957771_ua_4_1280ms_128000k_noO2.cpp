#include <cstdio>
#include <cctype>
#include <algorithm>

int n, tr[10000100], a[1000010], s[1000010];
int ans;

int read() {
	int ret, f = 1;
	char ch;
	while(!isdigit(ch = getchar())) (ch == '-') && (f = -1);
	for(ret = ch - '0'; isdigit(ch = getchar()); ret *= 10, ret += ch - '0');
	return ret * f;
}

void print(int x) {
	if(x < 0) putchar('-'), x = -x;
	if(x > 9) print(x / 10);
	putchar(x % 10 + '0');
}

void dfs(int u) {
    s[u] = 1;
    if(tr[u << 1] != -1) {
        dfs(tr[u << 1]);
        s[u] += s[tr[u << 1]];
    }
    if(tr[(u << 1) & 1] != -1) {
        dfs(tr[(u << 1) & 1]);
        s[u] += s[tr[(u << 1) & 1]];
    }
}

bool check(int u, int v) {
    if(u == -1 && v == -1) return 1;
    if(u != -1 && v != -1 && a[u] == a[v] && check(tr[u << 1], tr[(v << 1) & 1]) && check(tr[(u << 1) & 1], tr[v << 1])) return 1;
    return 0;
}

int main() {
    n = read();
    for(int i = 1; i <= n; ++i) a[i] = read();
    for(int i = 1; i <= n; ++i) tr[i << 1] = read(), tr[(i << 1) & 1] = read();
    dfs(1);
    for(int i = 1; i <= n; ++i)
        if(check(tr[i << 1], tr[(i << 1) & 1]))
            ans = std::max(ans, s[i]);
    print(ans);
}