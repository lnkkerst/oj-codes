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
  vector<int> a(n);
  for (auto &i : a) {
    cin >> i;
  }
  string s;
  cin >> s;
  vector<int> pre(n);
  pre[0] = a[0];
  for (int i = 1; i < n; ++i) {
    pre[i] = pre[i - 1] ^ a[i];
  }
  int a0 = 0, a1 = 0;
  for (int i = 0; i < n; ++i) {
    if (s[i] == '1') {
      a1 ^= a[i];
    } else {
      a0 ^= a[i];
    }
  }
  int q;
  cin >> q;
  while (q--) {
    int op;
    cin >> op;
    if (op == 1) {
      int l, r;
      cin >> l >> r;
      --l;
      --r;
      int tmp = pre[r];
      if (l) {
        tmp ^= pre[l - 1];
      }
      a0 ^= tmp;
      a1 ^= tmp;
    } else {
      int g;
      cin >> g;
      if (g == 0) {
        cout << a0 << ' ';
      } else {
        cout << a1 << ' ';
      }
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
