#include <cstdio>
#include <cctype>
#include <algorithm>

char a[2000001], n;

int main() {
    while(scanf("%d", &n) !=EOF) {
        for(int i = 1; i <= n; ++i) scanf("%d", &a[i]);
        std::stable_sort(a + 1, a + n + 1);
        for(int i = 1; i <= n; ++i) printf("%d ", a[i]);
        putchar('\n');
    }
    return 0;
}