#include <iostream>
#include <algorithm>
using namespace std;

int n, a[1000010], k;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(NULL);
    cin >> n >> k;
    for(int i = 1; i <= n; ++i) cin >> a[i];
    sort(a + 1, a + n + 1);
    cout << a[k] << endl;
    return 0;
}