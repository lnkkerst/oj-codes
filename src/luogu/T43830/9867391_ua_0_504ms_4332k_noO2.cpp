#include <cstdio>
using namespace std;
int main() {
  long long n, m, max, rp = 0, i, j, k, l;
  scanf("%lld%lld", &n, &m);
  const int N = n, M = m;
  int a[m][n];
  for (i = 0; i < m; i++)
    for (j = 0; j < n; j++)
      scanf("%lld", &a[i][j]);
  for (k = 0; k < n; k++) {
    j = 0;
    max = 0;
    l = -1;
    for (int i = 0; i < m; i++) {
      if (a[i][j] > max) {
        if (i == l)
          j++;
        max = a[i][j];
        l = i;
      }
    }
    rp += max;
  }
  printf("%lld", rp);
  return 0;
}