#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

#define int long long

void solve() {
  int n;
  int x1, y1, x2, y2;
  cin >> n >> x1 >> y1 >> x2 >> y2;
  x1 = x1 * 2 - 1;
  x2 = x2 * 2 - 1;
  y1 = y1 * 2 - 1;
  y2 = y2 * 2 - 1;
  n *= 2;
  x1 -= n / 2;
  x2 -= n / 2;
  y1 -= n / 2;
  y2 -= n / 2;
  if (x1 > 0 && y1 < 0) {
    swap(x1, y1);
    x1 = -x1;
  }
  if (y1 > 0 && x1 < 0) {
    swap(x1, y1);
    y1 = -y1;
  }
  if (y1 < 0 && x1 < 0) {
    x1 = -x1;
    y1 = -y1;
  }
  if (x2 > 0 && y2 < 0) {
    swap(x2, y2);
    x2 = -x2;
  }
  if (y2 > 0 && x2 < 0) {
    swap(x2, y2);
    y2 = -y2;
  }
  if (y2 < 0 && x2 < 0) {
    x2 = -x2;
    y2 = -y2;
  }
  int z1 = max(x1, y1), z2 = max(x2, y2);
  cout << abs(z1 - z2) / 2 << endl;
}

signed main() {
  int t;
  cin >> t;
  while (t--) {
    solve();
  }
}
