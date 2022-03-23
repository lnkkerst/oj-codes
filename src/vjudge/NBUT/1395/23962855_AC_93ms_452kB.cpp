#include <cstdio>
#include <algorithm>
#include <cstring>
#include <cctype>
using namespace std;

int n, ans;
int a[1233], b[1233];

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

void merge_sort(int l, int r) {
	if(l == r) return ;
	int mid = (l + r) >> 1;
	merge_sort(l, mid), merge_sort(mid + 1, r);
	int i = l, j = mid + 1, pos = l;
	while(i <= mid && j <= r) {
		if(a[i] > a[j]) ans += mid - i + 1, b[pos++] = a[j], ++j;
		else b[pos++] = a[i], ++i;
	}
	while(i <= mid) b[pos++] = a[i], ++i;
	while(j <= r) b[pos++] = a[j], ++j;
	for(int i = l; i <= r; ++i) a[i] = b[i];
	return ;
}

int main() {
	while(scanf("%d", &n) != EOF) {
		for(int i = 1; i <= n; ++i) a[i] = read();
		memset(b, 0, sizeof(b));
		ans = 0;
		merge_sort(1, n);
		print(ans), putchar('\n');
	}
	return 0;
}