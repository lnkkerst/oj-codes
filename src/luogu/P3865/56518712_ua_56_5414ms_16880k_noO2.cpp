#include <iostream>
#include <cmath>
using namespace std;

int n, m;
int a[100010];
int f[100010][40];

int main() {
    cin >> n >> m;
    for(int i = 1; i <= n; ++i) {
        cin >> a[i];
        f[i][0] = a[i];
    }
    for(int j = 1; (1 << j) <= n; ++j) {
        for(int i = 1; i <= n - (1 << j) + 1; ++i) {
            f[i][j] = max(f[i][j - 1], f[i + (1 << (j - 1))][j - 1]);
        }
    }
    for(int i = 1; i <= m; ++i) {
        int l, r;
        cin >> l >> r;
        int lo = log2(r - l + 1);
        cout << max(f[l][lo], f[r - (1 << lo) + 1][lo]) << endl;
    }
    return 0;
}
