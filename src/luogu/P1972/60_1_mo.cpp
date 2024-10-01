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

#define endl "\n"

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

struct Query {
  int l, r;
  int id;
};

void solve() {
  int n;
  io.read(n);
  vector<int> a(n);
  for (auto &i : a) {
    io.read(i);
  }
  int m;
  io.read(m);
  vector<Query> q(m);
  for (int i = 0; i < m; ++i) {
    q[i].id = i;
    io.read(q[i].l);
    io.read(q[i].r);
    q[i].l--;
    q[i].r--;
  }
  int bsz = sqrt(n);
  auto get_blk = [&](int x) {
    return x / bsz;
  };
  sort(q.begin(), q.end(), [&](const Query &a, const Query &b) {
    int ak = get_blk(a.l), bk = get_blk(b.l);
    if (ak == bk) {
      if (ak & 1) {
        return a.r > b.r;
      } else {
        return a.r < b.r;
      }
    }
    return ak < bk;
  });
  int l = 0, r = -1;
  int cnt = 0;
  vector<int> b(*max_element(a.begin(), a.end()) + 1);
  auto move = [&](int x, int type) {
    if (type == 1) {
      cnt += (++b[a[x]] == 1);
    } else {
      cnt -= (--b[a[x]] == 0);
    }
  };
  vector<int> ans(m);
  for (int i = 0; i < m; ++i) {
    while (l > q[i].l) {
      move(--l, 1);
    }
    while (r < q[i].r) {
      move(++r, 1);
    }
    while (l < q[i].l) {
      move(l++, -1);
    }
    while (r > q[i].r) {
      move(r--, -1);
    }
    ans[q[i].id] = cnt;
  }
  for (auto i : ans) {
    io.write(i, '\n');
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
