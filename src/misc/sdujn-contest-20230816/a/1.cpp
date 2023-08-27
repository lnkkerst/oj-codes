#include <iostream>
#include <utility>
#include <vector>
using namespace std;

#define int long long

signed main() {
  string s;
  cin >> s;
  int n = s.length();
  vector<pair<int, pair<int, int>>> a;
  int cur = 0, cl = 0, cr = 0;
  int tot = 0;
  for (int i = 0; i < n; ++i) {
    if (s[i] == 'v') {
      ++cur;
    } else if (cur) {
      a.emplace_back(make_pair(cur, make_pair(cl, i - 1)));
      tot += cur;
      cur = 0;
      cl = i;
    }
  }
  if (cur) {
    a.emplace_back(make_pair(cur, make_pair(cl, n - 1)));
    tot += cur;
  }
  int cntf = 0, cntl = 0;
  int nf = tot, nl = a.size();
  int ans = 0;
  // for (auto i : a) {
  //   cout << i.first << ' ' << i.second.first << ' ' << i.second.second <<
  //   endl;
  // }
  for (int i = 0; i < n; ++i) {
    if (s[i] != 'o') {
      continue;
    }
    while (cntl < a.size() && i > a[cntl].second.second) {
      cntf += a[cntl].first;
      ++cntl;
    }
    // cout << i << ' ' << cntf << ' ' << cntl << endl;
    ans += (cntf - cntl) * (nf - cntf - (nl - cntl));
  }
  cout << ans << endl;
}
