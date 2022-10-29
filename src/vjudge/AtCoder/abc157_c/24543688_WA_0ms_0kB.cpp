#include <iostream>
#include <vector>
using namespace std;

int n, m;
int a[23];
bool fl = 1;

int main() {
  cin >> n >> m;
  while (m--) {
    int x, y;
    cin >> x >> y;
    if (a[x] != 0 && a[x] != y) {
      fl = 0;
      break;
    }
    a[x] = y;
  }
  if (!fl || !a[1]) {
    cout << "-1";
    return 0;
  }
  for (int i = 1; i <= n; ++i)
    cout << a[i];
  return 0;
}