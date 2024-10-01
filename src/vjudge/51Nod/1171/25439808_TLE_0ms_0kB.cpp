#include <cmath>
#include <cstdio>
#include <iostream>
using namespace std;

int main() {
  ios::sync_with_stdio(0);
  cin.tie(NULL);
  cout.tie(NULL);
  int n;
  cin >> n;
  int i = sqrt(n), j = 0, j2 = 0, i2 = i * i;
  int ans[23333][2] = {0};
  int cnt = 0;
  while (i >= j) {
    while (i2 + j2 < n) {
      j2 += (j << 1 | 1);
      ++j;
    }
    if (i2 + j2 == n) {
      ans[++cnt][0] = j;
      ans[cnt][1] = i;
    }
    --i;
    i2 -= (i << 1 | 1);
  }
  if (!cnt) {
    cout << "No Solution\n";
    return 0;
  }
  for (int i = 1; i <= cnt; ++i) {
    if (ans[i][0] <= ans[i][1]) {
      cout << ans[i][0] << ' ' << ans[i][1] << '\n';
    }
  }
  return 0;
}
