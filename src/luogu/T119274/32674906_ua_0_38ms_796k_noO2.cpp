#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

int main() {
  int t;
  cin >> t;
  while (t--) {
    int n, m;
    cin >> n >> m;
    int bt = 0;
    vector<int> a(n + 1), v1(m + 1), v2[m + 1];
    int al = 1e9, ar = 0, t = 0, tt = 0;
    for (int i = 1; i <= n; ++i) {
      cin >> a[i];
      al = min(a[i], al);
      t += a[i] - 1;
    }
    ar = min(t + 1, m);
    cout << al << ' ' << ar << endl;
  }
  return 0;
}
