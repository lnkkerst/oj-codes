#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

void solve() {
  int a[4];
  cin >> a[0] >> a[1] >> a[3] >> a[2];
  for (int i = 0; i < 4; ++i) {
    if (a[i] < a[(i + 1) % 4] && a[(i + 3) % 4] < a[(i + 2) % 4]
        && a[i] < a[(i + 3) % 4] && a[(i + 1) % 4] < a[(i + 2) % 4]) {
      cout << "YES" << endl;
      return;
    }
  }
  cout << "NO" << endl;
  return;
}

int main() {
  int t;
  cin >> t;
  while (t--) {
    solve();
  }
}
