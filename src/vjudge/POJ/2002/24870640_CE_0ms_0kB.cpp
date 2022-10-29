#include <iostream>
#include <unordered_map>
using namespace std;

struct Point {
  int x, y;
  string dat() { return to_string(x) + ' ' + to_string(y); }
} a[1001];

unordered_map<string, bool> b;
int n;

int main() {
  while (cin >> n) {
    if (!n)
      return 0;
    b.clear();
    for (int i = 1; i <= n; ++i) {
      cin >> a[i].x >> a[i].y;
      b[a[i].dat()] = 1;
    }
    int ans = 0;
    for (int i = 1; i <= n; ++i) {
      for (int j = i + 1; j <= n; ++j) {
        Point p1{a[i].x - a[i].y + a[j].y, a[i].y + a[i].x - a[j].x};
        Point p2{a[j].x - a[i].y + a[j].y, a[j].y + a[i].x - a[j].x};
        if (b[p1.dat()] && b[p2.dat()])
          ++ans;
      }
    }
    cout << ans / 2 << endl;
  }
  return 0;
}