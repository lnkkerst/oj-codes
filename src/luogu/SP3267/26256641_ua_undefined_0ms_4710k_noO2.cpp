#include <algorithm>
#include <cctype>
#include <cstdio>
#include <cstring>
using namespace std;
const int B = 175;

struct Qus {
  int l, r, no;
} q[1000100];

int ans, m, n;
int a[10010], b[100010], cnt[2000100];

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
  if (x > 10) {
    print(x / 10);
  }
  putchar(x % 10 + '0');
}

int get(int x) {
  return (x - 1) / B + 1;
}

bool cmp(Qus a, Qus b) {
  return get(a.l) == get(b.l) ? a.r < b.r : a.l > b.l;
}

void del(int x) {
  if (!--cnt[x]) {
    --ans;
  }
}

void add(int x) {
  if (!cnt[x]++) {
    ++ans;
  }
}

int main() {
  n = read();
  for (int i = 1; i <= n; ++i) {
    a[i] = read();
  }
  m = read();
  for (int i = 1; i <= m; ++i) {
    q[i].l = read(), q[i].r = read(), q[i].no = i;
  }
  sort(q + 1, q + m + 1, cmp);
  int l = 1, r = 0;
  for (int i = 1; i <= m; ++i) {
    while (l < q[i].l) {
      del(a[l++]);
    }
    while (l > q[i].l) {
      add(a[--l]);
    }
    while (r < q[i].r) {
      add(a[++r]);
    }
    while (r > q[i].r) {
      del(a[r--]);
    }
    b[q[i].no] = ans;
  }
  for (int i = 1; i <= m; ++i) {
    print(b[i]), putchar('\n');
  }
  return 0;
}
