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

void solve() {
  int n;
  cin >> n;
  vector<int> a(n), b(n);
  for (auto &i : a) {
    cin >> i;
  }
  int mi = 1e9;
  for (auto &i : b) {
    cin >> i;
    mi = min(mi, i);
  }
  string ans = "";
  for (int i = 0; i < n; ++i) {
    if (a[i] > b[i]) {
      cout << "WinWinWin!!!" << endl;
      return;
    }
  }
  for (int i = 0; i < n; ++i) {
    if (a[i] > mi) {
      cout << "HaHa" << endl;
      return;
    }
  }
  cout << "AreYouOK?" << endl;
}

signed main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);
  int t = 1;
  while (t--) {
    solve();
  }
}
