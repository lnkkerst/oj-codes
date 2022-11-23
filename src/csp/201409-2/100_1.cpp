#include <iostream>
#include <vector>
using namespace std;

int n;
int a[101][101];

int main() {
  cin >> n;
  for (int i = 1; i <= n; ++i) {
    int x1, y1, x2, y2;
    cin >> x1 >> y1 >> x2 >> y2;
    for (int j = x1; j < x2; ++j) {
      for (int k = y1; k < y2; ++k) {
        ++a[j][k];
      }
    }
  }
  int ans = 0;
  for (int i = 0; i <= 100; ++i) {
    for (int j = 0; j <= 100; ++j) {
      ans += !!a[i][j];
    }
  }
  cout << ans << endl;
}
