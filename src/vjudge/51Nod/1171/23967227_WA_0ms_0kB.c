#include <stdio.h>
#include <math.h>
#define int long long
int n;
int fl = 0;

signed main() {
    scanf("%lld", &n);
    int manran = (int)sqrt((double)n / 2.0);
//    int i = !(n & 1) + 1;
    for(int i = 1; i <= manran; ++i) {
        int t = (int)sqrt((double)n - (double)(i * i));
        if (t < i) break;
        if(t * t + i * i == n) printf("%lld %lld\n", i, t), fl = 1;
    }
    if(!fl) printf("No Solution\n");
    return 0;
}