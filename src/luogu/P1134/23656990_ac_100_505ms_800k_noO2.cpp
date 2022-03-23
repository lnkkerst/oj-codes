#include <cstdio>

int main() {
	long long a = 1;
	int n;
	scanf("%d", &n);
	for(int i = 1; i <= n; ++i) {
		a *= i;
		while(a % 10 == 0)
			a /= 10;
		a %= 10000000;
	}
	printf("%lld", a % 10);
	return 0;
}