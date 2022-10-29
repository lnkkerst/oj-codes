#include <cctype>
#include <cstdio>
#include <cstring>
#define int long long

struct Trie {
  int cnt, root, go[200000][10], val[200000];
  Trie() {
    memset(go, 0, sizeof(go));
    memset(val, 0, sizeof(val));
    root = cnt = 0;
  }
  void add(int num, int v) {
    int now = root;
    while (num) {
      int k = num % 10;
      if (!go[now][k])
        go[now][k] = ++cnt;
      now = go[now][k], num /= 10;
    }
    val[now] += v;
  }
  int query(int num) {
    int now = root;
    while (num) {
      int k = num % 10;
      if (!go[now][k])
        return 0;
      now = go[now][k], num /= 10;
    }
    return val[now];
  }
} b;

int n, k, ans = 0;
int fs[200010];

int read() {
  int ret, f = 1;
  char ch;
  while (!isdigit(ch = getchar()))
    (ch == '-') && (f = -1);
  for (ret = ch - '0'; isdigit(ch = getchar()); ret *= 10, ret += ch - '0')
    ;
  return ret * f;
}

void print(int x) {
  if (x < 0)
    putchar('-'), x = -x;
  if (x > 9)
    print(x / 10);
  putchar(x % 10 + '0');
}

signed main() {
  n = read(), k = read();
  for (int i = 1; i <= n; ++i)
    fs[i] = fs[i - 1] + read();
  b.add(0, 1);
  int j = 0;
  for (int i = 1; i <= n; ++i) {
    if (i >= k)
      b.add((fs[j] - j + k) % k, -1), ++j;
    ans += b.query((fs[i] - i + k) % k);
    b.add((fs[i] - i + k) % k, 1);
  }
  print(ans);
  return 0;
}