#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

#define int long long

void solve() {
  int n, s1, s2;
  cin >> n >> s1 >> s2;
  vector<pair<int, int>> a;
  vector<int> ans1, ans2;
  for (int i = 0; i < n; ++i) {
    int x;
    cin >> x;
    a.emplace_back(make_pair(x, i + 1));
  }
  sort(a.begin(), a.end(), greater<>());
  for (auto &i : a) {
    int t1 = i.first * s1 * (ans1.size() + 1);
    int t2 = i.first * s2 * (ans2.size() + 1);
    if (t1 < t2) {
      ans1.emplace_back(i.second);
    } else if (t1 > t2) {
      ans2.emplace_back(i.second);
    } else {
      if (s1 > s2) {
        ans2.emplace_back(i.second);
      } else {

        ans1.emplace_back(i.second);
      }
    }
  }
  cout << ans1.size() << ' ';
  for (auto i : ans1) {
    cout << i << ' ';
  }

  cout << endl << ans2.size() << ' ';
  for (auto i : ans2) {
    cout << i << ' ';
  }
  cout << endl;
}

signed main() {
  int t;
  cin >> t;
  while (t--) {
    solve();
  }
}
