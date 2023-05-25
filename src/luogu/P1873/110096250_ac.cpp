#include <iostream>
#include <vector>
#define int long long
using namespace std;

signed main() {
  int n, m;
  cin >> n >> m;
  vector<int> a(n);
  for (auto &i : a) {
    cin >> i;
  }
  int l = 0, r = 1e18;
  while (l < r) {
    int mid = (l + r + 1) >> 1;
    int tot = 0;
    for (auto i : a) {
      tot += max(0ll, i - mid);
    }
    if (tot < m) {
      r = mid - 1;
    } else {
      l = mid;
    }
  }
  cout << l << endl;
}
