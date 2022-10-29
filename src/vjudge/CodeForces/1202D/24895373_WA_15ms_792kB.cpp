#include <iostream>
#define int long long
using namespace std;

int f[100001];

signed main() {
  int pos = 2;
  while (f[pos] < 2e9)
    f[pos] = (pos * (pos - 1)) / 2, ++pos;
  int t;
  cin >> t;
  while (t--) {
    int n;
    cin >> n;
    pos = lower_bound(f + 2, f + 100000, n) - f;
    for (int i = pos; i >= 2; --i) {
      if ((n / f[i]) * f[i] == n) {
        for (int j = 1; j <= n / f[i]; ++j)
          cout << 1;
        for (int j = 1; j <= i; ++j)
          cout << 3;
        cout << 7 << endl;
      }
      break;
    }
  }
  return 0;
}