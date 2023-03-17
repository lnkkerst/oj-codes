#include <algorithm>
#include <cmath>
#include <iostream>
#include <vector>
using namespace std;

void solve() {
  int n;
  double m;
  cin >> n >> m;
  double ans = 0;
  for (int i = 0; i <= n; ++i) {
    int x;
    cin >> x;
    ans += x / pow(1 + m, i);
  }
  cout << ans << endl;
}

int main() {
  int t;
  // cin >> t;
  t = 1;
  while (t--) {
    solve();
  }
}
