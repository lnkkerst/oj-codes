#include <iostream>
using namespace std;

int kmp[1000010];
int a[1000010], b[1000010];

int main() {
  int t;
  cin >> t;
  while (t--) {
    int n, m;
    bool fl = 0;
    cin >> n >> m;
    for (int i = 1; i <= n; ++i)
      cin >> a[i], kmp[i] = 0;
    for (int i = 1; i <= m; ++i)
      cin >> b[i];
    int j = 0;
    for (int i = 2; i <= m; ++i) {
      while (j && b[i] != b[j + 1])
        j = kmp[j];
      if (b[j + 1] == b[i])
        ++j;
      kmp[i] = j;
    }
    j = 0;
    for (int i = 1; i <= n; ++i) {
      while (j > 0 && b[j + 1] != a[i])
        j = kmp[j];
      if (b[j + 1] == a[i])
        ++j;
      if (j == m) {
        cout << i - m + 1 << endl;
        fl = 1;
        break;
      }
    }
    if (!fl)
      cout << -1 << endl;
  }
  return 0;
}