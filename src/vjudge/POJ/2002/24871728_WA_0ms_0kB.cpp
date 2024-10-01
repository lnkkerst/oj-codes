#include <cstring>
#include <iostream>
using namespace std;

const int MOD = 100000;

struct Hash {
  int h[100000], v[100000], nex[100000];
  int cnt;
  void insert(long long x) {
    long long k = (x % MOD + MOD) % MOD;
    v[++cnt] = x;
    nex[cnt] = h[k];
    h[k] = cnt;
  }
  bool query(long long x) {
    long long k = (x % MOD + MOD) % MOD;
    for (int i = h[k]; i; i = nex[i]) {
      if (v[i] == x) {
        return 1;
      }
    }
    return 0;
  }
} b;

struct Point {
  int x, y;
  long long dat() {
    return x * 100000ll + y;
  }
} a[1001];

int n;

int main() {
  while (cin >> n) {
    if (!n) {
      return 0;
    }
    memset(&b, 0, sizeof(b));
    for (int i = 1; i <= n; ++i) {
      cin >> a[i].x >> a[i].y;
      b.insert(a[i].dat());
    }
    int ans = 0;
    for (int i = 1; i <= n; ++i) {
      for (int j = i + 1; j <= n; ++j) {
        Point p1 = (Point){a[i].x - a[i].y + a[j].y, a[i].y + a[i].x - a[j].x};
        Point p2 = (Point){a[j].x - a[i].y + a[j].y, a[j].y + a[i].x - a[j].x};
        if (b.query(p1.dat()) && b.query(p2.dat())) {
          ++ans;
        }
      }
    }
    cout << ans / 2 << endl;
  }
  return 0;
}
