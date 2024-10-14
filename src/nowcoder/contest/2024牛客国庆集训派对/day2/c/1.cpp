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

#define int long long

void solve() {
  vector<pair<int, int>> a(3);
  int n;
  for (int i = 0; i < 3; ++i) {
    cin >> a[i].first;
    a[i].second = i;
  }
  cin >> n;
  sort(a.begin(), a.end());
  vector<string> s(3);
  for (int i = 1; i <= a[0].first; ++i) {
    s[0] += 'a';
    s[1] += 'a';
    s[2] += 'a';
  }
  for (int i = 1; i <= a[1].first - a[0].first; ++i) {
    s[1] += 'b';
    s[2] += 'b';
    s[0] += 'c';
  }
  for (int i = 1; i <= a[2].first - a[0].first; ++i) {
    s[0] += 'd';
    s[1] += 'e';
    s[2] += 'd';
  }
  for (int i = 0; i < 3; ++i) {
    if (s[i].length() > n) {
      cout << "NO" << endl;
      return;
    }
    while (s[i].length() < n) {
      s[i] += 'f' + i;
    }
  }
  auto calc = [&](string s1, string s2) {
    int res = 0;
    for (int i = 0; i < n; ++i) {
      if (s1[i] == s2[i]) {
        ++res;
      }
    }
    return res;
  };
  sort(a.begin(), a.end(), [&](pair<int, int> a, pair<int, int> b) {
    return a.second < b.second;
  });
  vector<int> idx{0, 1, 2};
  do {
    if (calc(s[idx[0]], s[idx[1]]) == a[0].first
        && calc(s[idx[1]], s[idx[2]]) == a[1].first
        && calc(s[idx[0]], s[idx[2]]) == a[2].first) {
      cout << s[idx[0]] << endl << s[idx[1]] << endl << s[idx[2]] << endl;
      return;
    }
  } while (next_permutation(idx.begin(), idx.end()));
  cout << "NO" << endl;
}

signed main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);
  int t = 1;
  // cin >> t;
  while (t--) {
    solve();
  }
}
