#include <cctype>
#include <cstdio>

int tree[1000010];
int n, m;

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

int lowbit(int x) {
  return x & -x;
}

void add(int x, int k) {
  while (x <= n) {
    tree[x] += k, x += lowbit(x);
  }
}

int query(int x) {
  int ret = 0;
  while (x) {
    ret += tree[x], x -= lowbit(x);
  }
  return ret;
}

int main() {
  n = read(), m = read();
  for (int i = 1; i <= n; ++i) {
    add(i, read());
  }
  for (int i = 1; i <= m; ++i) {
    if (read() == 1) {
      int l = read(), r = read(), k = read();
      add(l, k);
      add(r + 1, -k);
    } else {
      print(query(read()) / 2), putchar('\n');
    }
  }
  return 0;
}
