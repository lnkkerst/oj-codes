#include <iostream>
using namespace std;

int main() {
  int t;
  cin >> t;
  while (t--) {
    int n, m;
    cin >> n >> m;
    if (n == 1) {
      int x;
      cin >> x;
      cout << x << ' ' << x << endl;
      continue;
    }
    int tl = 0, tr = 0, x, ttr = 0;
    for (int i = 1; i <= n; ++i) {
      cin >> x;
      int xx = m - x + 1;
      ttr += xx - 1;
      tl += x - 1;
      tr += m - x;
    }
    int ar = min(m, tl + 1);
    int al = m - min(m, tr + 1) + 1;
    cout << al << ' ' << ar << endl;
  }
  return 0;
}