#include <algorithm>
#include <iostream>
using namespace std;

struct Node {
  int x, pos;
  bool operator<(const Node &b) const { return this->x < b.x; }
} a[10001];

int mabs(int x) { return x > 0 ? x : -x; }

int main() {
  int n;
  cin >> n;
  for (int i = 1; i <= n; ++i) {
    cin >> a[i].x;
    a[i].pos = i;
  }
  stable_sort(a + 1, a + n + 1);
  int ans = 0;
  for (int i = 1; i <= n; ++i)
    ans += mabs(a[i].pos - i);
  cout << ans;
  return 0;
}