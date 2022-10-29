#include <cstring>
#include <iostream>
using namespace std;
int main() {
  int n, m, z, x, y, s = 0;
  cin >> n >> m >> z;
  const int N = n + 4;
  bool a[N][N];
  memset(a, 0, sizeof(a));
  for (int i = 0; i < m; i++) {
    cin >> x >> y;
    x++;
    y++;
    a[x - 1][y - 1] = 1;
    a[x - 1][y + 1] = 1;
    a[x + 1][y - 1] = 1;
    a[x + 1][y + 1] = 1;
    for (int j = x - 2; j <= x + 2; j++)
      a[j][y] = 1;
    for (int j = y - 2; j <= y + 2; j++)
      a[x][j] = 1;
  }
  for (int i = 0; i < z; i++) {
    cin >> x >> y;
    x++;
    y++;
    for (int j = x - 2; j <= x + 2; j++) {
      for (int k = y - 2; k <= y + 2; k++)
        a[j][k] = 1;
    }
  }
  for (int i = 2; i < n + 2; i++)
    for (int j = 2; j < n + 2; j++)
      if (a[i][j] == 0)
        s++;
  cout << s;
  return 0;
}