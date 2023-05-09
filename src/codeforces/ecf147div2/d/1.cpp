#include <algorithm>
#include <iostream>
#include <queue>
#include <utility>
#include <vector>
#define int long long

using namespace std;

void solve() {
  int n, k;
  cin >> n >> k;
  vector<pair<int, int>> a(n);
  for (auto &i : a) {
    cin >> i.first;
  }
  for (auto &i : a) {
    cin >> i.second;
  }
  {
    int tmp = 0;
    for (auto &i : a) {
      tmp += i.second - i.first + 1;
    }
    if (tmp < k) {
      cout << -1 << endl;
      return;
    }
  }
  sort(a.begin(), a.end(), [](pair<int, int> &a, pair<int, int> &b) -> bool {
    return a.first < b.first;
  });
  int pos = 0;
  int cnt = 0;
  deque<int> pos1;
  deque<pair<int, int>> li;
  int cld = 0;
  int ans = 0;
  for (auto &i : a) {
    int sz = i.second - i.first + 1;
    if (sz == 1) {
      ++cnt;
      pos1.emplace_back(i.first);
      ans += i.second - pos;
      pos = i.second;
      continue;
    }
    int cs1 = min(k - cld, sz) - 1 + (i.first - pos) + 2;
    li.emplace_back(make_pair(i.first, i.first + k - cld - 1));
    ans += cs1;
    cld += sz;
    pos = i.second;
    if (cld >= k) {
      break;
    }
  }
  while (cld < k) {
    ++cld;
    pos1.pop_front();
    ans += 2;
  }
  int rest = 0;
  int last = ans;
  // for (auto i : li) {
  //   cout << i.first << ' ' << i.second << endl;
  // }
  for (int i = 1; i <= pos1.size() && !li.empty(); ++i) {
    int t = last;
    li.back().second--;
    if (li.back().second < li.back().first) {
      if (li.size() == 1) {
        ans = min(ans, pos1[i - 1] + i * 2);
        break;
      }
      t -= 2;
      t -= (li.back().first - li[li.size() - 2].second);
      li.pop_back();
    } else {
      --t;
    }
    t += 2;
    ans = min(ans, t);
    last = t;
  }
  cout << ans << endl;
}

signed main() {
  int t;
  cin >> t;
  while (t--) {
    solve();
  }
}
