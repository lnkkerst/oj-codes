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
  int n;
  cin >> n;
  vector<int> a(n);
  int cnt = 0;
  int tot = 0;
  for (auto &i : a) {
    cin >> i;
    if (i >= 2) {
      ++cnt;
    }
    tot += i;
  }
  if ((tot - n) & 1) {
    cout << "gui" << endl;
  } else {
    cout << "sweet" << endl;
  }
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
