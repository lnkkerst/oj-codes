#pragma GCC optimize(2)
#include <algorithm>
#include <array>
#include <bitset>
#include <cstdio>
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

int read() {
  int x = 0, f = 1;
  char ch = 0;
  while (ch < '0' || ch > '9') {
    if (ch == '-') {
      f = -1;
    }
    ch = getchar();
  }
  while (ch >= '0' && ch <= '9') {
    x = x * 10 + (ch - '0');
    ch = getchar();
  }
  return x * f;
}

void write(int x) {
  if (x < 0) {
    x = -x;
    putchar('-');
  }
  if (x > 9) {
    write(x / 10);
  }
  putchar(x % 10 + '0');
}

vector<int> sz(6e6);

void init() {
  for (int i = 0; i < sz.size(); ++i) {
    sz[i] = i * (i + 1) / 2 - i;
  }
}

void solve() {
  int n = read(), m = read();
  auto calc = [](int n, int m) {
    return (n * n + n) / 2 * (m * m + m) / 2;
  };
  if (calc(n, m) & 1) {
    puts("No");
    return;
  }
  puts("Yes");
  bool fl = false;
  if (((m * m + m) / 2) & 1) {
    fl = true;
    swap(n, m);
  }
  vector<int> a;
  int tot = 0;
  int su = 0;
  int target = m * (m + 1) / 4;
  while (true) {
    if (tot == m) {
      break;
    }
    int cur = m - tot;
    int tmp = target - su - m + tot;
    auto it = upper_bound(sz.begin(), sz.end(), tmp);
    --it;
    cur = distance(sz.begin(), it);
    // while (target - (su + (cur * (cur + 1) / 2)) < (m - tot - cur)) {
    //   --cur;
    // }
    tot += cur;
    su += (cur * (cur + 1) / 2);
    a.emplace_back(cur);
  }
  vector<int> row;
  int cur = 0;
  for (auto i : a) {
    for (int j = 1; j <= i; ++j) {
      row.emplace_back(cur);
    }
    cur = !cur;
  }
  if (!fl) {
    for (int i = 1; i <= n; ++i) {
      for (auto j : row) {
        write(j);
        putchar(' ');
      }
      putchar('\n');
    }
  } else {
    swap(n, m);
    for (int i = 1; i <= n; ++i) {
      for (int j = 1; j <= m; ++j) {
        write(row[i - 1]);
        putchar(' ');
      }
      putchar(' ');
    }
  }
}

signed main() {
  init();
  int t = read();
  while (t--) {
    solve();
  }
}
