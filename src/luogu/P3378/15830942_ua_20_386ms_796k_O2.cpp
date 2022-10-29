// luogu-judger-enable-o2
#include <cstdio>
#define MAXN 1000010

int h[MAXN], n = 0;

void swap(int &x, int &y) {
  int t = x;
  x = y;
  y = t;
}

void pushup(int i) {
  if (i == 1)
    return;
  if (h[i] < h[i >> 1]) {
    swap(h[i], h[i >> 1]);
    pushup(i >> 1);
  }
}

void pushdown(int i) {
  if (i << 1 > n)
    return;
  int t = i << 1;
  if (t < n && h[t | 1] > h[t])
    t |= 1;
  if (h[t] < h[i]) {
    swap(h[t], h[i]);
    pushdown(t);
  }
}

void add() {
  int x;
  scanf("%d", &x);
  ++n;
  h[n] = x;
  pushup(n);
}

void printf() { printf("%d\n", h[1]); }

void del() {
  h[1] = h[n];
  n--;
  pushdown(1);
}

int main() {
  int q;
  scanf("%d", &q);
  for (int i = 1; i <= q; i++) {
    int e;
    scanf("%d", &e);
    if (e == 1)
      add();
    else if (e == 2)
      printf();
    else if (e == 3)
      del();
  }
  return 0;
}