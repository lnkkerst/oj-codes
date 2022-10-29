#include <cmath>
#include <iostream>
#define int long long
using namespace std;

signed main() {
  int t;
  cin >> t;
  while (t--) {
    int n;
    cin >> n;
    int ans1, ans2, ans3;
    for (int i = 10 > sqrt(n) ? 10 : sqrt(n); i >= 2; --i) {
      int t = i * (i - 1) / 2;
      if (t * (n / t) == n) {
        for (int j = 1; j <= n / t; ++j)
          cout << 1;
        for (int j = 1; j <= i; ++j)
          cout << 3;
        cout << 7 << endl;
        break;
      }
    }
  }
  return 0;
}