#include <cctype>
#include <cstdio>

int a[233], n;
bool b[233], dx[233], dy[233];

inline int read() {
	int ret, f = 1;
	char ch;
	while(!isdigit(ch = getchar())) (ch == '-') && (f = -1);
	for(ret = ch - '0'; isdigit(ch = getchar()); ret *= 10, ret += ch - '0');
	return ret * f;
}

inline void print(int x) {
	if(x < 0) putchar('-'), x = -x;
	if(x > 9) print(x / 10);
	putchar(x % 10 + '0');
}

void dfs(int st) {
	if(st > n) {
		for(int i = 1; i <= n; ++i) print(a[i]);
		putchar('\n');
	}
	for(int i = 1; i <= n; ++i) {
		if(!b[i] && !dx[i + st] && !dy[st - i + n]) {
			a[st] = i, b[i] = dx[i + st] = dy[st - i + n] = 1;
			dfs(st + 1);
			b[i] = dx[i + st] = dy[st - i + n] = 0;
		}
	}
}

int main() {
	n = read();
	dfs(1);
	return 0;
}