#include <algorithm>
#include <cctype>
#include <cstdio>
#include <iostream>
#define int __int128_t
using namespace std;

struct Node {
  int l, r;
  bool operator<(const Node &b) const { return this->l * this->r < b.l * b.r; }
} a[1001];

int n;

int readint() {
  int ret, fl = 1;
  char ch;
  while (!isdigit(ch = getchar()))
    (ch == '-') && (fl = -1);
  ret = ch - '0';
  while (isdigit(ch = getchar()))
    ret *= 10, ret += ch - '0';
  return ret * fl;
}

void printint(int x) {
  if (x < 0)
    putchar('-'), x = -x;
  if (x > 9)
    printint(x / 10);
  putchar(x % 10 + '0');
}

signed main() {
  n = readint(), a[0].l = readint(), a[0].r = readint();
  for (int i = 1; i <= n; ++i)
    a[i].l = readint(), a[i].r = readint();
  sort(a + 1, a + n + 1);
  int ans = -1, sm = a[0].l;
  for (int i = 1; i <= n; ++i) {
    ans = max(ans, sm / a[i].r);
    sm *= a[i].l;
  }
  printint(ans);
  return 0;
}