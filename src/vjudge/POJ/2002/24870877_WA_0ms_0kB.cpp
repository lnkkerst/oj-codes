#include <cstring>
#include <iostream>
using namespace std;

struct Point {
  int x, y;
  int dat() {
    return ((x * 100000ll + y) % 1000000 + 1000000) % 1000000;
  }
} a[1001];

bool b[1000000];
int n;

int main() {
  while (cin >> n) {
    if (!n) {
      return 0;
    }
    memset(b, 0, sizeof(b));
    for (int i = 1; i <= n; ++i) {
      cin >> a[i].x >> a[i].y;
      b[a[i].dat()] = 1;
    }
    int ans = 0;
    for (int i = 1; i <= n; ++i) {
      for (int j = i + 1; j <= n; ++j) {
        Point p1 = (Point){a[i].x - a[i].y + a[j].y, a[i].y + a[i].x - a[j].x};
        Point p2 = (Point){a[j].x - a[i].y + a[j].y, a[j].y + a[i].x - a[j].x};
        if (b[p1.dat()] && b[p2.dat()]) {
          ++ans;
        }
      }
    }
    cout << ans / 2 << endl;
  }
  return 0;
}
