#include <cstdio>

int main() {
    int n;
    scanf("%d", &n);
    int ans = 0, t = 1;
    for(int i = 1; i <= n; ++i) {t *= i; ans += t; }
    printf("%d", ans);
    return 0;
}