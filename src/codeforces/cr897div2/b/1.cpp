#pragma GCC optimize(2)
#include <algorithm>
#include <array>
#include <functional>
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
  string s;
  cin >> s;
  int c1 = 0;
  for (auto i : s) {
    c1 += i == '1';
  }
  int c0 = n - c1;
  int cp1 = 0;
  for (int i = 0; i < n / 2; ++i) {
    if (s[i] == '1') {
      cp1 += s[n - i - 1] == '0';
    } else {
      cp1 += s[n - i - 1] == '1';
    }
  }
  for (int i = 0; i <= n; ++i) {
    if (i < cp1) {
      cout << 0;
      continue;
    }
    if (i > n - cp1) {
      cout << 0;
      continue;
    }
    if (n & 1) {
      cout << 1;
      continue;
    }
    int rest = i - cp1;
    if (rest & 1) {
      cout << 0;
    } else {
      cout << 1;
    }
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
