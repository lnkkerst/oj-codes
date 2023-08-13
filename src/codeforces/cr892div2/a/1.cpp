#pragma GCC optimize(2)
#include <algorithm>
#include <iostream>
#include <map>
#include <set>
#include <unordered_map>
#include <unordered_set>
#include <vector>
using namespace std;

void solve() {
  int n;
  cin >> n;
  vector<int> a(n);
  unordered_map<int, int> bk;
  for (auto &i : a) {
    cin >> i;
    ++bk[i];
  }
  vector<int> b, c;
  sort(a.begin(), a.end());
  c.emplace_back(a.back());
  a.pop_back();
  while (a.back() == c.front()) {
    c.emplace_back(a.back());
    a.pop_back();
  }
  b = a;
  if (c.empty() || b.empty()) {
    cout << -1 << endl;
    return;
  }
  cout << b.size() << ' ' << c.size() << endl;
  for (auto i : b) {
    cout << i << ' ';
  }
  cout << endl;
  for (auto i : c) {
    cout << i << ' ';
  }
  cout << endl;
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);
  int t;
  cin >> t;
  while (t--) {
    solve();
  }
}
