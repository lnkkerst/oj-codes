// luogu-judger-enable-o2
#include <cstdio>
using namespace std;
int main() {
  int n, m, max, rp = 0;
  scanf("%ld%ld", &n, &m);
  const int N = n, M = m;
  int a[m][n];
  for (int i = 0; i < m; i++) {
    max = 0;
    for (int j = 0; j < n; j++) {
      scanf("%ld", &a[i][j]);
      if (a[i][j] > max) {
        max = a[i][j];
      }
    }
    rp += max;
  }
  printf("%ld", rp);
  return 0;
}
