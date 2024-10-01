#include <algorithm>
#include <cctype>
#include <cstdio>
#include <iostream>

using namespace std;

inline int get() {
  char ch;
  int res = 0;
  bool flag = false;
  while (ch = getchar(), !isdigit(ch) && ch != '-')
    ;
  (ch == '-' ? flag = true : res = ch ^ 48);
  while (ch = getchar(), isdigit(ch)) {
    res = res * 10 + ch - 48;
  }
  return flag ? -res : res;
}

const int N = 5005;
struct point {
  int v, w;
  inline void scan() {
    v = get();
    w = get();
  }

  inline bool operator<(const point &a) const {
    return w > a.w;
  }
} p[N];

int n, f[N], Ans;
inline void CkMax(int &x, int y) {
  if (x < y) {
    x = y;
  }
}

int main() {
  //	freopen("wizard.in", "r", stdin);
  //	freopen("wizard.out", "w", stdout);

  n = get();
  for (int i = 1; i <= n; ++i) {
    p[i].scan();
  }
  sort(p + 1, p + n + 1);
  for (int i = 0; i <= n; ++i) {
    f[i] = -1e9;
  }
  f[0] = 0;
  for (int i = 1; i <= n; ++i) {
    for (int j = i; j >= 1; --j) {
      CkMax(f[j], f[j - 1] + p[i].v - (j - 1) * p[i].w);
    }
  }
  for (int j = 1; j <= n; ++j) {
    CkMax(Ans, f[j]);
  }
  printf("%d\n", Ans);

  //	fclose(stdin); fclose(stdout);
  return 0;
}
