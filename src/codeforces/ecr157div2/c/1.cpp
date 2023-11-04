#pragma GCC optimize(2)
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

#define int long long

int calc(string s) {
  int res = 0;
  for (auto i : s) {
    res += i - '0';
  }
  return res;
}

int solve1(vector<string> a) {
  int n = a.size();
  int res = 0;
  unordered_map<int, int> b1, b2;
  unordered_map<string, int> b;
  for (auto i : a) {
    b[i]++;
    for (int j = 1; j < i.size(); j += 2) {
      int tot = 0;
      int len = i.size() + j;
      int ls = calc(i.substr(0, len / 2));
      int rs = calc(i.substr(len / 2));
      b1[((j << 30) + ls - rs)]++;
    }
    reverse(i.begin(), i.end());
    for (int j = 1; j < i.size(); j += 2) {
      int tot = 0;
      int len = i.size() + j;
      int ls = calc(i.substr(0, len / 2));
      int rs = calc(i.substr(len / 2));
      b2[((j << 30) + ls - rs)]++;
    }
  }
  // for (auto [k, v] : b1) {
  //   int len = k >> 30;
  //   int num = k - (len << 30);
  //   cout << len << ' ' << num << ' ' << v << endl;
  // }
  // cout << "---" << endl;
  // for (auto [k, v] : b2) {
  //   int len = k >> 30;
  //   int num = k - (len << 30);
  //   cout << len << ' ' << num << ' ' << v << endl;
  // }
  unordered_map<int, int> b3;
  for (auto i : a) {
    b3[(i.size() << 30) + calc(i)]++;
  }

  for (auto i : a) {
    // res -= b[i];
    res += b3[(i.size() << 30) + calc(i)];
    res += b1[(i.size() << 30) + calc(i)];
    reverse(i.begin(), i.end());
    res += b2[(i.size() << 30) + calc(i)];
  }
  return res;
}

int solve2(vector<string> a) {
  int n = a.size();
  unordered_map<int, int> b1, b2;
  int res = 0;
  unordered_map<string, int> b;
  for (auto i : a) {
    b[i]++;
    for (int j = 2; j < i.size(); j += 2) {
      int tot = 0;
      int len = i.size() + j;
      int ls = calc(i.substr(0, len / 2));
      int rs = calc(i.substr(len / 2));
      b1[((j << 30) + ls - rs)]++;
    }
    reverse(i.begin(), i.end());
    for (int j = 2; j < i.size(); j += 2) {
      int tot = 0;
      int len = i.size() + j;
      int ls = calc(i.substr(0, len / 2));
      int rs = calc(i.substr(len / 2));
      b2[((j << 30) + ls - rs)]++;
    }
  }
  unordered_map<int, int> b3;
  for (auto i : a) {
    b3[(i.size() << 30) + calc(i)]++;
  }
  for (auto i : a) {
    // res -= b[i];
    res += b3[(i.size() << 30) + calc(i)];
    res += b1[(i.size() << 30) + calc(i)];
    reverse(i.begin(), i.end());
    res += b2[(i.size() << 30) + calc(i)];
  }
  return res;
}

void solve() {
  int n;
  cin >> n;
  vector<string> a1, a2;
  for (int i = 0; i < n; ++i) {
    string s;
    cin >> s;
    if (s.size() & 1) {
      a1.emplace_back(s);
    } else {
      a2.emplace_back(s);
    }
  }
  int ans = 0;
  ans += solve1(a1);
  ans += solve2(a2);
  cout << ans << endl;
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
