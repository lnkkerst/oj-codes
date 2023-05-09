#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

void solve() {
  int n;
  cin >> n;
  if (n == 1) {
    cout << 1 << endl;
    return;
  }
  if (n & 1) {
    cout << -1 << endl;
    return;
  }
  vector<int> a(n + 1);
  auto b = a;
  a[1] = n;
  a[2] = n - 1;
  b[1] = 0;
  b[2] = n - 1;
  int cur = 1;
  int last = 0;
  for (int i = 3; i <= n; i += 2) {
    b[i] = cur;
    b[i + 1] = n - 1 - cur;
    a[i] = n + cur - b[i - 1];
    a[i + 1] = b[i + 1] - b[i];
    ++cur;
  }
  for (int i = 1; i <= n; ++i) {
    cout << a[i] << ' ';
  }
  cout << endl;
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int t;
  cin >> t;
  while (t--) {
    solve();
  }
}
