#pragma GCC optimize(2)

#include <algorithm>
#include <cstdio>
#include <functional>
#include <map>
#include <queue>
#include <set>
#include <unordered_map>
#include <unordered_set>
#include <vector>
using namespace std;

void solve() {
  int n;
  scanf("%d", &n);
  vector<int> a(n);
  int cnt2 = 0;
  unordered_set<int> b;
  for (auto &i : a) {
    scanf("%d", &i);
    b.insert(i);
    if (i % 2 == 0) {
      ++cnt2;
    }
  }
  if (cnt2 >= 2) {
    puts("YES");
    return;
  }
  sort(a.begin(), a.end(), greater<>());
  while (a.back() == 1) {
    a.pop_back();
  }
  auto aa = a;
  set<int> sa{a.begin(), a.end()};
  if (a.size() != sa.size()) {
    puts("YES");
    return;
  }
  a = vector<int>{sa.begin(), sa.end()};
  sort(a.begin(), a.end(), greater<>());
  map<int, int> cnt;
  int cntr = 0, cntr2 = 0;
  for (auto x : a) {
    for (int i = 2; i * i <= x; ++i) {
      ++cntr2;
      if (cntr2 >= 1e6) {
        puts("YES");
        return;
      }
      if (x % i == 0) {
        if (b.find(i) != b.end()) {
          puts("YES");
          return;
        }
        while (x % i == 0) {
          x /= i;
          ++cntr;
          if (cntr >= 1e6) {
            puts("YES");
            return;
          }
        }
        ++cnt[i];
        if (cnt[i] >= 2) {
          puts("YES");
          return;
        }
      }
    }
    if (x > 1) {
      ++cnt[x];
      if (cnt[x] >= 2) {
        puts("YES");
        return;
      }
    }
  }
  for (auto i : cnt) {
    if (i.first == 1) {
      continue;
    }
    if (i.second >= 2) {
      puts("YES");
      return;
    }
  }
  puts("NO");
}

signed main() {
  int t;
  scanf("%d", &t);
  while (t--) {
    solve();
  }
}
