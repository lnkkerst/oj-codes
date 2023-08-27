#include <algorithm>
#include <deque>
#include <iostream>
#include <map>
#include <vector>
using namespace std;

#define int long long

signed main() {
  int n;
  cin >> n;
  vector<int> a(n);
  for (auto &i : a) {
    cin >> i;
  }
  int ans = 0;

  deque<int> bb[233];
  for (int i = 0; i < n; ++i) {
    bb[a[i]].emplace_back(i);
  }
  for (int k = 2; k <= 200; ++k) {
    vector<int> q(233, -1);
    int tmp = 0;
    int last = -1;
    for (int i = 0; i < n; ++i) {
      int ta = k - a[i];
      if (a[i] >= k) {
        continue;
      }
      if (q[ta] != -1 && q[ta] > last) {
        ++tmp;
        last = i;
      } else {
        q[a[i]] = i;
      }
    }
    ans = max(ans, tmp * 2);
  }
  cout << ans << endl;
}
