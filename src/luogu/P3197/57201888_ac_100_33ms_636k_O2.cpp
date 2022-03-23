#include <iostream>
using namespace std;
#define int long long

constexpr int p = 100003;

int qPow(int x, int k) {
    int res = 1;
    while(k) {
        if(k & 1) {
            res *= x;
            res %= p;
        }
        x *= x;
        x %= p;
        k >>= 1;
    }
    return res;
}

signed main() {
    int n, m;
    cin >> m >> n;
    cout << (qPow(m, n) % p - m * qPow(m - 1, n - 1) % p + p) % p;
    return 0;
}