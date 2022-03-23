#include <iostream>
#include <cmath>
using namespace std;

int a[1000010][23], n, len;

int main() {
    cin >> n >> len;
    for(int i = 1; i <= n; ++i) cin >> a[i][0];
    for(int j = 1; j <= 22; ++j)   
        for(int i = 1; i + (1 << j) - 1 <= n; ++i)
            a[i][j] = min(a[i][j - 1], a[i + (1 << (j - 1))][j - 1]);
    int t = log2(len);
    cout << min(a[1][t], a[1 + len - (1 << t) + 1][t]);
    for(int i = 2; i <= n - len; ++i)
        cout << ' ' << min(a[i][t], a[i + len - (1 << t) + 1][t]);
    return 0;
}