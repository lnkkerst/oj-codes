#include <cstdio>

using namespace std;

int gcd(int x, int y) {
    return !y ? x : gcd(y, x % y);
}

int main() {
    int n, m;
    scanf("%d%d", &n, &m);
    n = gcd(n, m);
    int fib[1000007] = {0, 1, 1};
    for(int i = 3; i <= n + 2; i++)
        fib[i] = (fib[i - 1] + fib[i - 2]) % 100000000;
    printf("%d", fib[n]);
    return 0;   
}