#pragma GCC optimize(2)
#include <algorithm>
#include <array>
#include <bitset>
#include <cmath>
#include <deque>
#include <functional>
#include <iomanip>
#include <iostream>
#include <map>
#include <numeric>
#include <queue>
#include <set>
#include <stack>
#include <unordered_map>
#include <unordered_set>
#include <vector>
using namespace std;

void solve() {
  int n, k;
  cin >> n >> k;
  string s;
  cin >> s;
  int ca = 0, cb = 0;
  for (auto c : s) {
    ca += c == 'A';
    cb += c == 'B';
  }
  if (cb == k) {
    cout << 0 << endl;
    return;
  }
  cout << 1 << endl;
  if (cb > k) {
    int ans = 0;
    while (true) {
      if (cb == k) {
        cout << ans << " A" << endl;
        return;
      }
      ca -= s[ans] == 'A';
      cb -= s[ans] == 'B';
      s[ans] = 'A';
      ++ca;
      ++ans;
    }
  }
  if (cb < k) {
    int ans = 0;
    while (true) {
      if (cb == k) {
        cout << ans << " B" << endl;
        return;
      }
      ca -= s[ans] == 'A';
      cb -= s[ans] == 'B';
      s[ans] = 'B';
      ++cb;
      ++ans;
    }
  }
}

signed main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);
  int t = 1;
  cin >> t;
  while (t--) {
    solve();
  }
}
