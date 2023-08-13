#include <algorithm>
#include <iostream>
#include <vector>
#define int long long
using namespace std;

void solve() {
  int n;
  cin >> n;
  ++n;
  cout << n * n + 1 << endl;
}

signed main() {
  int t;
  cin >> t;
  while (t--) {
    solve();
  }
}
