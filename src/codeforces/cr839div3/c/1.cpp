#include <algorithm>
#include <iostream>
#include <map>
#include <vector>
using namespace std;

void solve() {
  int k, n;
  cin >> k >> n;
  vector<int> pre{1};
  while (pre.back() <= 50) {
    pre.emplace_back(pre.back() + pre.size());
  }
  int pos = 0;
  while (pre[pos] <= n) {
    ++pos;
  }
  --pos;
  decltype(pre) ans{pre.begin(), pre.begin() + pos + 1};
  map<int, bool> b;
  while (ans.size() > k) {
    ans.pop_back();
  }
  while (ans.size() < k && ans.back() < n) {
    ans.emplace_back(ans.back() + 1);
  }
  for (auto i : ans) {
    b[i] = true;
  }
  while (ans.size() < k) {
    for (int i = n; i >= 1; --i) {
      if (!b[i]) {
        ans.emplace_back(i);
        sort(ans.begin(), ans.end());
        b[i] = true;
        break;
      }
    }
  }
  for (auto i : ans) {
    cout << i << ' ';
  }
  cout << endl;
}

int main() {
  int t;
  cin >> t;
  while (t--) {
    solve();
  }
}
