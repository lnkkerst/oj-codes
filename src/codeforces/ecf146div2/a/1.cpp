#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

#define int long long

void solve() {
  int n, k;
  cin >> n >> k;
  if (n % 2 == 0) {
    cout << "YES" << endl;
    return;
  }
  if (k % 2 == 0) {
    cout << "NO" << endl;
    return;
  }
  cout << "YES" << endl;
}

signed main() {
  int t;
  cin >> t;
  while (t--) {
    solve();
  }
}
