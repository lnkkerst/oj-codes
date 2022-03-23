#include <cstdio>
#include <cctype>
#define int __int128_t
int n, m;
int a[1000010], b[1000010];
int f[1000010], t[1000010];
int mod;

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

int min(int x, int y) {
	return x < y ? x : y;
}

int max(int x, int y) {
	return x > y ? x : y;
}

signed main() {
	n = read(), mod = read();
	for(int i = 1; i <= n; ++i) a[i] = read();
	int maxn = -1;
	for(int i = 1; i <= n; ++i)	{
		b[i] = max(a[i], a[i] + b[i - 1]);
		maxn = max(maxn, b[i]);
		t[i] = maxn;
	} f[1] = t[1], f[2] = f[1] + t[1];
	maxn = max(f[1], f[2]);
	bool fl = 0;
	for(int i = 2; i <= n; ++i) {
		if(f[i - 1] + t[i - 1] < 0 && f[i - 1] > 0) fl = 1;
		if(fl) f[i] = f[i - 1] % mod + t[i - 1] % mod;
		else f[i] = max(f[i - 1], f[i - 1] + t[i - 1]);
		maxn = max(maxn, f[i]) %mod;
	}
	print(maxn % mod);
	return 0;
}