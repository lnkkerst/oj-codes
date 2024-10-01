#include <cctype>
#include <cstdio>
#include <cstring>

struct Trie {
  int nex[2010][4], end[2010], pre[2010], root, tot;
  int ans;
  Trie() {
    memset(nex, 0, sizeof(nex));
    memset(end, 0, sizeof(end));
    memset(pre, 0, sizeof(pre));
    ans = 0;
    root = tot = 1;
  }
  void init() {
    memset(nex, 0, sizeof(nex));
    memset(end, 0, sizeof(end));
    memset(pre, 0, sizeof(pre));
    ans = 0;
    root = tot = 1;
  }
  int fixx(char ch) {
    if (ch == 'A') {
      return 0;
    }
    if (ch == 'C') {
      return 1;
    }
    if (ch == 'G') {
      return 2;
    }
    if (ch == 'T') {
      return 3;
    }
    return 1;
  }
  void insert(char str[]) {
    int now = root;
    for (int i = 0; str[i]; ++i) {
      int k = fixx(str[i]);
      if (!nex[now][k]) {
        nex[now][k] = ++tot;
      }
      now = nex[now][k];
      ++pre[now];
    }
    ++end[now];
  }
  int max(int x, int y) {
    return x > y ? x : y;
  }
  void dfs(int deep, int now) {
    if (!now) {
      return;
    }
    ans = max(ans, deep * pre[now]);
    for (int i = 0; i < 4; ++i) {
      dfs(deep + 1, nex[now][i]);
    }
  }
} a;

int n;
char s[2010];

int read() {
  int ret, f = 1;
  char ch;
  while (!isdigit(ch = getchar())) {
    (ch == '-') && (f = -1);
  }
  for (ret = ch - '0'; isdigit(ch = getchar()); ret *= 10, ret += ch - '0')
    ;
  return ret * f;
}

void print(int x) {
  if (x < 0) {
    putchar('-'), x = -x;
  }
  if (x > 9) {
    print(x / 10);
  }
  putchar(x % 10 + '0');
}

int main() {
  int t = read();
  for (int k = 1; k <= t; ++k) {
    n = read();
    a.init();
    for (int i = 1; i <= n; ++i) {
      scanf("%s", s);
      a.insert(s);
    }
    a.dfs(0, 1);
    printf("Case %d: %d\n", k, a.ans);
  }
  return 0;
}
