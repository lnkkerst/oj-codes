#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

void solve() {
  int x, k;
  cin >> x >> k;
  if (x % k != 0) {
    cout << 1 << endl;
    cout << x << endl;
    return;
  }
  cout << 2 << endl;
  cout << x - 1 << ' ' << 1 << endl;
}

int main() {
  int t;
  cin >> t;
  while (t--) {
    solve();
  }
}
