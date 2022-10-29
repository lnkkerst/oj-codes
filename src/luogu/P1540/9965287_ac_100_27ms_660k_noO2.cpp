#include <cstring>
#include <iostream>
using namespace std;
int main() {
  int m, n, ans = 0, word;
  bool flag;
  cin >> m >> n;
  const int M = m;
  int a[M], h = 0;
  memset(a, 1001, sizeof(a));
  for (int i = 0; i < n; i++) {
    flag = 0;
    cin >> word;
    for (int j = 0; j < m; j++) {
      if (a[j] == word) {
        flag = 1;
        break;
      }
    }
    if (flag == 0) {
      ans++;
      a[h] = word;
      if (h + 1 == m)
        h = 0;
      else
        h++;
    }
  }
  cout << ans;
  return 0;
}