#include <cstdio>

int s[100010];
int len, ans, last;

int max(int x, int y) {
	return x > y ? x : y;
}

int main() {
	char ch;
	while((ch = getchar()) != EOF)
		s[++len] = ch == 48 ? 1 : -1;
	for(int i = 1; i <= len; ++i) {
		last = max(0, last) + s[i];
		ans = max(ans, last);
	}
	printf("%d", ans);
	return 0;
}