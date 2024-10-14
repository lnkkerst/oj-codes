#include <cmath>
#include <cstdio>
#include <iostream>
using namespace std;
typedef long double LD;

struct node {
  LD x;
  LD y;
};
const int MAX_N = 100005;
const LD eps = 1e-7;
int n;
node a[MAX_N];

LD judge(LD x) {
  LD r = 0, tmp;
  for (int i = 0; i < n; ++i) {
    tmp = ((x - a[i].x) * (x - a[i].x) + a[i].y * a[i].y) / (2.0 * a[i].y);
    r = max(r, tmp);
  }

  return r;
}
int main() {
  LD ans = 0;
  scanf("%d", &n);
  for (int i = 0; i < n; ++i) {
    scanf("%Lf%Lf", &a[i].x, &a[i].y);
    if (a[i].y > 0) {
      ++ans;
    } else {
      a[i].y = -a[i].y;
    }
  }
  if (ans && ans != n) {
    ans = -1;
  }
  LD l = -1e8, r = 1e8, t1, t2;
  int ss = 100;
  while (ss-- && ans != -1) {
    t1 = l + (r - l) / 3;
    t2 = r - (r - l) / 3;
    if (judge(t1) <= judge(t2)) {
      r = t2;
    } else {
      l = t1;
    }
  }
  if (ans != -1) {
    ans = judge(l);
    printf("%Lf\n", ans);
  } else {
    printf("-1\n");
  }

  return 0;
}
