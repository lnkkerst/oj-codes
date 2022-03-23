#include <cstdio>

int main() {
	double a, p;
	while(scanf("%lf%lf", &a, &p) != EOF) {
		printf("%.2lf\n", a * p / 10);
	}
	return 0;
}