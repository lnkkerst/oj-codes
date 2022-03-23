#include <cstdio>

using namespace std;

int n, m, k, x;

int qpow(int a, int b, int p) {
    int ans = 1;
    while(b) {
        if(b & 1) ans = 1LL * ans * a % p;
        b >>= 1;
        a = 1LL * a * a % p;
    }
    return ans;
}

int main() {
    scanf("%d%d%d%d", &n, &m, &k, &x);
    printf("%d\n", (x + m * qpow(10, k, 0x7fffffff)) % n);
    return 0;
}