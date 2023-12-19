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

string hashS(vector<int> a) {
  string s = "";
  for (auto i : a) {
    s += to_string(i) + " ";
  }
  return s;
}

void solve() {
  int n;
  cin >> n;
  vector<int> a(n);
  for (auto &i : a) {
    cin >> i;
  }
  set<string> b;
  function<void(vector<int>)> dfs = [&](vector<int> a) {
    auto hs = hashS(a);
    if (b.find(hs) != b.end()) {
      return;
    }
    b.insert(hs);
    for (int i = 2; i <= a.size(); ++i) {
      for (int j = 0; j + i - 1 < a.size(); ++j) {
        auto ta = a;
        auto mi = *min_element(ta.begin() + j, ta.begin() + j + i);
        ta.erase(ta.begin() + j, ta.begin() + j + i);
        ta.insert(ta.begin() + j, mi);
        // cout << "ij  " << i << ' ' << j << endl;
        // for (auto i : a) {
        //   cout << i << ' ';
        // }
        // cout << endl;
        // for (auto i : ta) {
        //   cout << i << ' ';
        // }
        // cout << endl;
        dfs(ta);
      }
    }
  };
  dfs(a);
  cout << b.size() << endl;
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
