#include <bits/stdc++.h>
using namespace std;
int MOD;

int read() {
  int ret;
  bool flag = 0;
  char ch;
  while (!isdigit(ch = getchar())) {
    (ch == '-') && (flag = 1);
  }
  for (ret = ch - '0'; isdigit(ch = getchar()); ret *= 10, ret += ch - '0')
    ;
  return flag ? -ret : ret;
}

void print(int x) {
  if (x < 0) {
    putchar('-');
    x *= -1;
  }
  if (x > 9) {
    print(x / 10);
  }
  putchar(x % 10 + '0');
}

struct Trie {
  int go[11], end, fail;
} trie[10010];

struct Mat {
  int n, m;
  int dataee[36][36];
  Mat() {
    memset(dataee, 0, sizeof(dataee));
  }
  Mat(int _n, int _m) {
    n = _n;
    m = _m;
    memset(dataee, 0, sizeof(dataee));
  }
  int *operator[](int x) {
    return dataee[x];
  }
  Mat operator*(Mat b) {
    Mat c(n, b.m);
    for (int i = 1; i <= n; ++i) {
      for (int j = 1; j <= b.m; ++j) {
        for (int k = 1; k <= m; ++k) {
          c[i][j] = (c[i][j] % MOD + dataee[i][k] * b[k][j] % MOD) % MOD;
        }
      }
    }
    return c;
  }
  Mat pow(int k) {
    Mat tmp(n, n), res(n, n);
    for (int i = 1; i <= n; res[i][i] = 1, ++i) {
      for (int j = 1; j <= n; ++j) {
        tmp[i][j] = dataee[i][j];
      }
    }
    while (k) {
      if (k & 1) {
        res = res * tmp;
      }
      tmp = tmp * tmp;
      k >>= 1;
    }
    return res;
  }
};

char s[10010];
int cnt = 0;
int f[110][10010];
int ans = 0;
int n, m;

void insert(char *str) {
  int l = strlen(s);
  int x = 0;
  for (int i = 0; i < l; i++) {
    int k = str[i] - '0';
    if (!trie[x].go[k]) {
      trie[x].go[k] = ++cnt;
    }
    x = trie[x].go[k];
  }
  trie[x].end |= 1;
}

void init_fail() {
  queue<int> q;
  for (int i = 0; i < 10; ++i) {
    if (trie[0].go[i]) {
      q.push(trie[0].go[i]);
    }
  }
  while (!q.empty()) {
    int u = q.front();
    q.pop();
    for (int i = 0; i < 10; ++i) {
      if (trie[u].go[i]) {
        trie[trie[u].go[i]].end |= trie[trie[trie[u].fail].go[i]].end;
        trie[trie[u].go[i]].fail = trie[trie[u].fail].go[i];
        q.push(trie[u].go[i]);
      } else {
        trie[u].go[i] = trie[trie[u].fail].go[i];
      }
    }
  }
}

int main() {
  n = read(), m = read(), MOD = read();
  scanf("%s", s);
  insert(s);
  init_fail();
  Mat a(cnt + 1, cnt + 1), start(cnt + 1, cnt + 1);
  start[1][1] = 1;
  for (int i = 0; i <= cnt; ++i) {
    for (int j = 0; j < 10; ++j) {
      if (!trie[trie[i].go[j]].end) {
        ++a[i + 1][trie[i].go[j] + 1];
      }
    }
  }
  a = a.pow(n);
  a = start * a;
  for (int i = 1; i <= cnt + 1; ++i) {
    (ans += a[1][i]) %= MOD;
  }
  print(ans);
  return 0;
}
