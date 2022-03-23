#include <bits/stdc++.h>
using namespace std;

long long n, a[300010];

int main() {
    cin >> n;
    for(long long i = 1; i <= n; ++i) cin >> a[i];
    sort(a + 1, a + n + 1, greater<long long >());
    long double ans = a[1] * a[1];
    long long sum = a[1];
    for(long long i = 2; i <= n; ++i) {
        sum += a[i];
        long double tmp = (long double)(sum * sum) / (long double)i;
        if(tmp > ans) ans = tmp;
        else break;
    }
    cout << ans;
}