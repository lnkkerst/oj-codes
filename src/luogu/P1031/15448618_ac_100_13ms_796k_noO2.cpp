#include <cstdio>
#define MAXN 500

int main() {
    int n, a[MAXN], ar = 0, ans = 0;

    scanf("%d", &n);

    for(int i = 1; i <= n; i++) {
        scanf("%d", &a[i]);

        ar += a[i];
    }

    ar /= n;

    for(int i = 1; i <= n; i++)
        a[i] -= ar;

    int l = 1, r = n;

    for(;a[l] == 0 && l < n; l++);
    for(;a[r] == 0 && r > 1; r--);

    while(l < r) {
        a[l + 1] += a[l];
        a[l] = 0;
        ans++;
        l++;

        for(; a[l] == 0 && l < r; l++);
    }

    printf("%d", ans);

    return 0;
}