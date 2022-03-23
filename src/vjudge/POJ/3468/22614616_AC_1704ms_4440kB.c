#include <stdio.h>
#define N 400010
#define int long long
int cov[N], sum[N];
int n, m, l, r, x;
int a[N];
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
void pushdown(int cur, int len) {
	cov[cur << 1] += cov[cur];
	cov[cur << 1 | 1] += cov[cur];
	sum[cur << 1] += cov[cur] * ((len + 1) >> 1);
	sum[cur << 1 | 1] += cov[cur] * (len >> 1);
	cov[cur] = 0;
}
void update(int cur) {
	sum[cur] = sum[cur << 1] + sum[cur << 1 | 1];
}
int query(int l, int r, int L, int R, int cur) {
	if(l >= L && r <= R) return sum[cur];
	if(cov[cur]) pushdown(cur, r - l + 1);
	int mid = (l + r) >> 1, ans = 0;
	if(L <= mid) ans += query(l, mid, L, R, cur << 1);
	if(R > mid) ans += query(mid + 1, r, L, R, cur << 1 | 1);
	return ans;
}
void add(int l, int r, int L, int R, int x, int cur) {
	if(l >= L && r <= R) {
		cov[cur] += x;
		sum[cur] += (r - l + 1) * x;
		return;
	}
	if(cov[cur]) pushdown(cur, r - l + 1);
	int mid = (l + r) >> 1;
	if(L <= mid) add(l, mid, L, R, x, cur << 1);
	if(R > mid) add(mid + 1, r, L, R, x, cur << 1 | 1);
	update(cur);
}
signed main() {
	n = read(), m = read();
	for(int i = 1; i <= n; i++) add(1, n, i, i, read(), 1);
	while(m--) {
		char opt = getchar();
        while(opt != 'C' && opt != 'Q') opt = getchar();
		if(opt == 'C') {
			l = read(), r = read(), x = read();
			add(1, n, l, r, x, 1);
		}
        else {
			l = read(), r = read();
			print(query(1, n, l, r, 1)), putchar('\n');
		}
	}
	return 0;
}