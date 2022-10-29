#include <algorithm>
#include <cmath>
#include <cstdio>

using namespace std;

struct peanut {
  int x, y, w;
} pea[1000];

bool cmp(peanut a, peanut b) { return a.w > b.w; }

int main() {
  int m, n, k, top = 0;
  scanf("%d%d%d", &m, &n, &k);
  //	for(int i = 1; i <= n * m; ++i) {
  //		int tmp;
  //		scanf("%d", &tmp);
  //		if(tmp) {
  //			pea[++top].x = i / n + 1;
  //			pea[top].y = i % n;
  //			pea[top].w = tmp;
  //		}
  //	}
  for (int i = 1; i <= m; ++i)
    for (int j = 1; j <= n; ++j) {
      int tmp;
      scanf("%d", &tmp);
      if (tmp) {
        pea[++top].x = i;
        pea[top].y = j;
        pea[top].w = tmp;
      }
    }
  sort(pea + 1, pea + top + 1, cmp);
  int ans = 0;
  ans += pea[1].w;
  k -= (pea[1].x + 1);
  for (int i = 2; i <= top; ++i) {
    k -= (abs(pea[i].x - pea[i - 1].x) + abs(pea[i].y - pea[i - 1].y) + 1);
    if ((k - pea[i].x) < 0)
      break;
    ans += pea[i].w;
  }
  printf("%d", ans);
}