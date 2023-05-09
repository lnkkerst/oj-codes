#include <algorithm>
#include <iostream>
#include <queue>
#include <unordered_map>
#include <vector>
using namespace std;

void solve() {
  int n;
  cin >> n;
  string s;
  cin >> s;
  if (n & 1) {
    cout << -1 << endl;
    return;
  }
  unordered_map<char, int> bc;
  for (auto i : s) {
    ++bc[i];
  }
  for (auto &i : bc) {
    if (i.second > n / 2) {
      cout << -1 << endl;
      return;
    }
  }
  unordered_map<char, int> b;
  for (int i = 0; i < s.length() / 2; ++i) {
    if (s[i] == s[n - i - 1]) {
      ++b[s[i]];
    }
  }
  int ans = 0;
  priority_queue<int> q;
  for (auto &i : b) {
    q.push(i.second);
  }
  while (q.size() >= 2) {
    int a = q.top();
    q.pop();
    int b = q.top();
    q.pop();
    ans += b;
    a -= b;
    if (a) {
      q.push(a);
    }
  }
  if (!q.empty()) {
    ans += q.top();
  }
  cout << ans << endl;
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int t;
  cin >> t;
  while (t--) {
    solve();
  }
}
