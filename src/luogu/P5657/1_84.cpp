#include <algorithm>
#include <array>
#include <bitset>
#include <deque>
#include <functional>
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

using i128 = __int128_t;
using u64 = unsigned long long;

void solve() {
  u64 in, ik;
  cin >> in >> ik;
  i128 n = in, k = ik;
  function<string(i128, i128)> dfs = [&](i128 n, i128 k) -> string {
    if (n == 0) {
      return "";
    }
    if (k < (1ull << (n - 1))) {
      return "0" + dfs(n - 1, k);
    } else {
      return "1" + dfs(n - 1, (1ull << n) - k - 1);
    }
  };
  cout << dfs(n, k) << endl;
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
