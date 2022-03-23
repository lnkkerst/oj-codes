#include <cstdio>
#define ll long long

ll a, b, p;

ll fast_power(ll a, ll b) {
    if(b == 0) return 1;

    ll t = fast_power(a, b >> 1);

    if(b % 2 == 0)
        return t * t % p;
    else
        return (t * t % p) * a % p;

}

int main() {
    scanf("%lld%lld%lld", &a, &b, &p);
    printf("%lld^%lld mod %lld=%lld",a, b, p, fast_power(a, b));

    return 0;
}