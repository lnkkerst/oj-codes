#include <iostream>
#include <cmath>
using namespace std;

int n, m;
int a[100010];
int f[100010][40];
int l2[100010] = {-1};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> n >> m;
    for(int i = 1; i <= n; ++i) {
        l2[i] = l2[i >> 1] + 1;
    }
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
        int lo = l2[r - l + 1];
        cout << max(f[l][lo], f[r - (1 << lo) + 1][lo]) << endl;
    }
    return 0;
}
