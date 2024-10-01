#pragma GCC optimize(2)
#include <algorithm>
#include <deque>
#include <iostream>
#include <map>
#include <queue>
#include <set>
#include <vector>
using namespace std;

void solve() {
  int n = 5;
  map<char, int> mp{
    {'A', 1 },
    {'T', 10},
    {'J', 11},
    {'Q', 12},
    {'K', 13}
  };
  for (int i = '2'; i <= '9'; ++i) {
    mp[i] = i - '0';
  }
  vector<int> a(5);
  set<char> s1;
  set<int> s;
  for (int i = 0; i < 5; ++i) {
    string str;
    cin >> str;
    a[i] = mp[str.front()];
    s.insert(a[i]);
    s1.insert(str.back());
  }
  if (s1.size() != 1 || s.size() != n) {
    cout << "check\n";
    return;
  }
  // for (auto i : a) {
  //   cout << i << endl;
  // }
  auto ta = a;
  sort(ta.begin(), ta.end());
  vector<int> j1{1, 10, 11, 12, 13};
  if (ta == j1) {
    cout << "allin\n";
    return;
  }
  for (int i = 0; i < 4; ++i) {
    if (ta[i] != ta[i + 1] - 1) {
      cout << "check\n";
      return;
    }
  }
  int mine = ta.front();
  // cout << mine << endl;
  set<int> ss;
  for (int i = 2; i < 5; ++i) {
    ss.insert(a[i]);
  }
  if (find(j1.begin(), j1.end(), a[0]) == j1.end()
      && find(j1.begin(), j1.end(), a[1]) == j1.end()) {
    for (int i = 2; i < 5; ++i) {
      if (find(j1.begin(), j1.end(), a[i]) != j1.end()) {
        cout << "check\n";
        return;
      }
    }
  }
  int op = 0;
  for (int i = 1; i + 4 <= 13; ++i) {
    bool fl = false;
    for (int j = i; j <= i + 4; ++j) {
      if (find(ss.begin(), ss.end(), j) != ss.end()) {
        fl = true;
        break;
      }
    }
    if (!fl) {
      continue;
    }
    fl = false;
    for (int j = i; j <= i + 4; ++j) {
      if (a[0] == j || a[1] == j) {
        fl = true;
        break;
      }
    }
    if (!fl) {
      op = max(op, i);
    }
  }
  if (mine > op) {
    cout << "allin\n";
  } else {
    cout << "check\n";
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
