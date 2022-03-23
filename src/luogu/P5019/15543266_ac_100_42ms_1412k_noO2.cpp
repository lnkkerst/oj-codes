#include <cstdio>
#define ll long long

int main() {
    ll n, a[100010], ans = 0;

    scanf("%lld", &n);

    for(int i = 1; i <= n; i++)
        scanf("%lld", &a[i]);

    for(int i = 2; i <= n; i++)
        if(a[i] > a[i - 1])
            ans += a[i] - a[i - 1];

    printf("%lld", ans + a[1]);

    return 0;
}