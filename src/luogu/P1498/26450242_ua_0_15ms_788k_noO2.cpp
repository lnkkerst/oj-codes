#include <cstdio>
int n, a[2333] = {1};
int main() {
	scanf("%d", &n);
	for(int i = 0; i < 1 << n; ++i) {
		for(int j = 1; j < (1 << n) - i; ++j) putchar(' ');
		for(int j = i; j >= 0; --j) a[j] ^= a[j - 1];
		if(i % 2 == 0)
			for(int j = 0; j <= i; ++j) a[j] ? putchar('/'), putchar('\\') : putchar(' '), putchar(' ');
		else for(int j = 0; j <= i; j += 2) a[j] ? putchar('/'), putchar('_'), putchar('_'), putchar('\\') : putchar(' '), putchar(' '), putchar(' '), putchar(' ');
		putchar('\n');
	}
	return 0;
}