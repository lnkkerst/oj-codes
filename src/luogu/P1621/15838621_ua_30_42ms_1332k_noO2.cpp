#include <cstdio>
#define MAXN 100010

int a, b, p, f[MAXN], ans;
bool book[MAXN];

void lnin(int x, int y) {
  for (int i = x; i <= y; i++)
    f[i] = i;
}

int find(int x) { return f[x] == x ? x : f[x] = find(f[x]); }

void merge(int x, int y) { f[find(x)] = find(y); }

int main() {
  scanf("%d%d%d", &a, &b, &p);
  ans = b - a + 1;
  lnin(a, b);
  for (int i = 2; i <= b; ++i) {
    if (!book[i]) {
      if (i >= p) {
        for (int j = i << 1; j <= b; j += i) {
          book[i] = 1;
          if (j - i >= a && find(j) != find(j - 1)) {
            merge(j, j - 1);
            --ans;
          }
        }
      } else {
        for (int j = i << 1; j <= b; j += i) {
          book[j] = 1;
        }
      }
    }
  }
  printf("%d\n", ans);
  return 0;
}