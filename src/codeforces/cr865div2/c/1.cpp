#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

#define int long long

void solve() {
  int n;
  cin >> n;
  vector<int> a(n);
  for (int i = 0; i < n; ++i) {
    cin >> a[i];
  }
  int up = 0, down = 0;
  int last = 0;
  a[0] -= 1000000000000000000ll;
  a[1] -= 1000000000000000000ll;
  for (int i = 1; i < n - 1; ++i) {
    a[i] += last;
    last = a[i - 1] - a[i];
    a[i] = a[i - 1];
  }
  if (a[n - 1] + last < a[n - 2]) {
    cout << "NO" << endl;
  } else {
    cout << "YES" << endl;
  }
}

signed main() {
  int t;
  cin >> t;
  while (t--) {
    solve();
  }
}
