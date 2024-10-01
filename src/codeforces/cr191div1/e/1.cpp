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

// #define DEBUG 1  // 调试开关
struct IO {
#define MAXSIZE (1 << 20)
#define isdigit(x) (x >= '0' && x <= '9')
  char buf[MAXSIZE], *p1, *p2;
  char pbuf[MAXSIZE], *pp;
#if DEBUG
#else
  IO(): p1(buf), p2(buf), pp(pbuf) {}

  ~IO() {
    fwrite(pbuf, 1, pp - pbuf, stdout);
  }
#endif
  char gc() {
#if DEBUG // 调试，可显示字符
    return getchar();
#endif
    if (p1 == p2) {
      p2 = (p1 = buf) + fread(buf, 1, MAXSIZE, stdin);
    }
    return p1 == p2 ? ' ' : *p1++;
  }

  bool blank(char ch) {
    return ch == ' ' || ch == '\n' || ch == '\r' || ch == '\t';
  }

  template <class T>
  void read(T &x) {
    double tmp = 1;
    bool sign = 0;
    x = 0;
    char ch = gc();
    for (; !isdigit(ch); ch = gc()) {
      if (ch == '-') {
        sign = 1;
      }
    }
    for (; isdigit(ch); ch = gc()) {
      x = x * 10 + (ch - '0');
    }
    if (ch == '.') {
      for (ch = gc(); isdigit(ch); ch = gc()) {
        tmp /= 10.0, x += tmp * (ch - '0');
      }
    }
    if (sign) {
      x = -x;
    }
  }

  void read(char *s) {
    char ch = gc();
    for (; blank(ch); ch = gc())
      ;
    for (; !blank(ch); ch = gc()) {
      *s++ = ch;
    }
    *s = 0;
  }

  void read(char &c) {
    for (c = gc(); blank(c); c = gc())
      ;
  }

  void push(const char &c) {
#if DEBUG // 调试，可显示字符
    putchar(c);
#else
    if (pp - pbuf == MAXSIZE) {
      fwrite(pbuf, 1, MAXSIZE, stdout), pp = pbuf;
    }
    *pp++ = c;
#endif
  }

  template <class T>
  void write(T x) {
    if (x < 0) {
      x = -x, push('-'); // 负数输出
    }
    static T sta[35];
    T top = 0;
    do {
      sta[top++] = x % 10, x /= 10;
    } while (x);
    while (top) {
      push(sta[--top] + '0');
    }
  }

  template <class T>
  void write(T x, char lastChar) {
    write(x), push(lastChar);
  }
} io;

void solve() {
  int n, m;
  io.read(n);
  io.read(m);
  vector<vector<int>> a(n + 10, vector<int>(n + 10));
  for (int i = 1; i <= n; ++i) {
    for (int j = 1; j <= n; ++j) {
      io.read(a[i][j]);
    }
  }
  auto p = a;
  for (int i = 1; i <= n; ++i) {
    for (int j = 1; j <= n; ++j) {
      p[i][j] += p[i - 1][j] + p[i][j - 1] - p[i - 1][j - 1];
    }
  }
  auto get_sum = [&](int l, int r) {
    l = max(l, 1ll);
    if (r < l) {
      return 0ll;
    }
    int res = p[r][r] - p[l - 1][r] - p[r][l - 1] + p[l - 1][l - 1];
    return res;
  };
  vector<vector<int>> dp(n + 10, vector<int>(m + 10, 1e12));
  vector<vector<int>> bt(n + 10, vector<int>(m + 10));
  for (int i = 0; i <= m; ++i) {
    dp[i][i] = 0;
    bt[n + 1][i] = n;
  }
  for (int i = 0; i <= n; ++i) {
    bt[i][0] = 1;
  }
  for (int i = 0; i <= n; ++i) {}
  for (int j = 1; j <= m; ++j) {
    for (int i = n; i >= j + 1; --i) {
      for (int k = bt[i][j - 1]; k <= bt[i + 1][j]; ++k) {
        int cur = dp[k - 1][j - 1] + get_sum(k, i) / 2;
        if (cur < dp[i][j]) {
          dp[i][j] = cur;
          bt[i][j] = k;
        }
      }
    }
  }
  io.write(dp[n][m]);
}

signed main() {
  // ios::sync_with_stdio(false);
  // cin.tie(nullptr);
  // cout.tie(nullptr);
  int t = 1;
  // cin >> t;
  while (t--) {
    solve();
  }
}
