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

using u8 = unsigned char;
using i8 = char;
using u16 = unsigned short;
using i16 = short;
using u32 = unsigned int;
using i32 = int;
using u64 = unsigned long long;
using i64 = long long;

void solve() {
  int n;
  cin >> n;
  n *= 2;
  string s;
  for (int i = 0; i < (n + 16 - 1) / 16; ++i) {
    string t;
    cin >> t;
    s += t;
  }
  string ans;
  stringstream ss(s);
  char c;
  n = 0;
  int base = 1;
  auto getBit = [&](int len = 1, bool rev = false, int blen = 2) -> u64 {
    vector<string> vs;
    string s;
    for (int i = 0; i < len; ++i) {
      string t;
      for (int j = 0; j < blen; ++j) {
        char c;
        ss >> c;
        t += c;
      }
      vs.emplace_back(t);
    }
    if (rev) {
      reverse(vs.begin(), vs.end());
    }
    for (auto i : vs) {
      s += i;
    }
    // cout << "getBit " << len << ' ' << rev << ' ' << s << endl;
    return stoull(s, 0, 16);
  };
  auto getStr = [&](int len = 1, int blen = 2) {
    string res;
    char c;
    for (int i = 0; i < len * blen; ++i) {
      ss >> c;
      res += c;
    }
    // cout << "getStr " << len << ' ' << res << endl;
    return res;
  };
  auto getRef = [&](int o, int l) {
    o *= 2;
    l *= 2;
    int pos = ans.size() - o;
    int end = ans.size();
    int cur = pos;
    string res;
    for (int i = 0; i < l; ++i) {
      res += ans[cur];
      ++cur;
      if (cur == end) {
        cur = pos;
      }
    }
    // cout << "getRef " << o << ' ' << l << ' ' << res << endl;
    return res;
  };
  while (!ss.eof()) {
    u8 x = getBit();
    if (x & (1ull << 7)) {
      n += x ^ (1ull << 7);
      base *= 128;
    } else {
      n += x * base;
      break;
    }
  }
  // cout << n << endl;
  while (!ss.eof()) {
    // cout << ans.length() << endl;
    if (ans.length() / 2 == n) {
      break;
    }
    u8 x = getBit();
    int low2 = u8((x << 6)) >> 6;
    // cout << low2 << endl;
    if (low2 == 0b00) {
      int l = (x >> 2);
      // cout << "l " << l << endl;
      if (l >= 60) {
        int tot = l - 59;
        l = getBit(tot, true);
      }
      ++l;
      ans += getStr(l);
    } else if (low2 == 0b01) {
      int l = (u8(x << 3) >> 5) + 4;
      int o = x >> 5;
      o = o * 256 + getBit(1);
      ans += getRef(o, l);
    } else if (low2 == 0b10) {
      int l = (x >> 2) + 1;
      int o = getBit(2, true);
      ans += getRef(o, l);
    }
  }
  for (int i = 1; i <= ans.size(); ++i) {
    cout << ans[i - 1];
    if (i % 16 == 0) {
      cout << endl;
    }
  }
}

signed main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);
  int t = 1;
  // cin >> t;
  while (t--) {
    solve();
  }
}
