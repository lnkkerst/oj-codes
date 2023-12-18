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
  set<int> s;
  for (int i = 1; i <= 1e17; i = (i * 10) + 1) {
    for (int j = 1; j <= 1e17; j = (j * 10) + 1) {
      for (int k = 1; k <= 1e17; k = (k * 10) + 1) {
        s.insert(i + j + k);
      }
    }
  }
  int n;
  cin >> n;
  cout << ((vector<int>{s.begin(), s.end()})[n - 1]) << endl;
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
