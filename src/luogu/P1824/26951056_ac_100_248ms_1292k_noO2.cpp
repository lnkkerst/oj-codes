#include <cstdio>
#include <cctype>
#include <algorithm>

int n, m, a[100010];

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

int search() {
    int l = 0, r = 0x7fffffff, mid, now, cnt;
    while(l < r) {
        mid = (r + l + 1) >> 1;
        now = a[1], cnt = 1;
        for(int i = 2; i <= n && cnt < m; ++i)
            if(a[i] - now >= mid) now = a[i], ++cnt;
        if(cnt < m) r = mid - 1;
        else l = mid;
    }
}

int main() {
    n = read(), m = read();
    for(int i = 1; i <= n; ++i) a[i] = read();
    std::sort(a + 1, a + n + 1);
    print(search());
    return 0;
}