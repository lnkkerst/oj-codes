#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

#define int long long

vector<int> fib;

void solve() {
  int n, x, y;
  cin >> n >> x >> y;
  while (n > 1) {
    // cout << x << ' ' << y << endl;
    if (y > fib[n - 1]) {
      y = fib[n + 1] - y + 1;
    }
    // cout << fib[n + 1] << ' ' << y << endl;
    if (y > fib[n - 1]) {
      cout << "NO" << endl;
      return;
    }
    swap(x, y);
    x = -x;
    x += fib[n - 1] + 1;
    n--;
  }
  cout << "YES" << endl;
}

signed main() {
  fib.resize(46);
  fib[0] = 1;
  fib[1] = 1;
  for (int i = 2; i <= 45; ++i) {
    fib[i] = fib[i - 1] + fib[i - 2];
  }
  int t;
  cin >> t;
  while (t--) {
    solve();
  }
}
