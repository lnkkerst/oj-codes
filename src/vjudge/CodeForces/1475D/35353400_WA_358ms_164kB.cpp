#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

struct App {
  int v, m;
  App() { v = m = 0; }
};

int main() {
  int t;
  cin >> t;
  while (t--) {
    int n, m;
    cin >> n >> m;
    vector<int> b1(1, 0), b2(1, 0);
    vector<int> a;
    for (int i = 1; i <= n; ++i) {
      int x;
      cin >> x;
      a.emplace_back(x);
    }
    for (int i = 1; i <= n; ++i) {
      int x;
      cin >> x;
      if (x == 1) {
        b1.emplace_back(a[i - 1]);
      } else {
        b2.emplace_back(a[i - 1]);
      }
    }
    sort(b1.begin() + 1, b1.end(), greater<>());
    sort(b2.begin() + 1, b2.end(), greater<>());
    for (int i = 1; i < b1.size(); ++i) {
      b1[i] += b1[i - 1];
    }
    for (int i = 1; i < b2.size(); ++i) {
      b2[i] += b2[i - 1];
    }
    if (b1.back() + b2.back() < m) {
      cout << "-1" << endl;
      continue;
    }
    int ans = 1e9;
    for (int i = 0; i < b1.size(); ++i) {
      int l = 0, r = int(b2.size()) - 1, cur = 1e9;
      while (l <= r) {
        int mid = (l + r) >> 1;
        if (b1[i] + b2[mid] >= m) {
          cur = mid;
          r = mid - 1;
        } else {
          l = mid + 1;
        }
        ans = min(ans, i + cur * 2);
      }
    }
    cout << ans << endl;
  }
  return 0;
}