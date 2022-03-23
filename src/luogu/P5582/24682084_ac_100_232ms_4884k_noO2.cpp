#include <cstdio>
#include <cstring>

bool b[1000010];
int a[1000010];

int gcd(int x, int y) {
    return !y ? x : gcd(y, x % y);
}

int work(int n, int k) {
    for(int i = 1; i <= k; ++i)
        scanf("%d", &a[i]), b[a[i]] = 1;
    int d = n;
    if(n == 1 && k == 1) return -1;
    for(int i = 1; i <= n; ++i)
        if(!b[i]) d = gcd(d, i);
    for(int i = 1; i <= k; ++i)
        b[a[i]] = 0;
    return d <= 1 ? n : -1;
}

int main() {
    int t;
    scanf("%d", &t);
    while(t--) {
        int n, k;
        scanf("%d%d", &n, &k);
        printf("%d\n", work(n, k));
    }
    return 0;
}