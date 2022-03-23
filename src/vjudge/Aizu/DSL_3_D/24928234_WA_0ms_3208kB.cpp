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
    int t = log2(len * 2 - 1);
    for(int i = 1; i <= n - len; ++i) cout << a[i][t] << ' ';
    return 0;
}