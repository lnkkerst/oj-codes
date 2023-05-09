#include <algorithm>
#include <cmath>
#include <iostream>
#include <vector>
using namespace std;

constexpr double eps = 1e-4;

using Node = pair<double, double>;

double dis(Node a, Node b) {
  return sqrt(pow(a.first - b.first, 2) + pow(a.second - b.second, 2));
}

double mulX(Node a, Node b, Node c) {
  return (b.first - a.first) * (c.second - a.second) -
         (b.second - a.second) * (c.first - b.first);
}

void solve() {
  vector<Node> a(20);
  for (auto &i : a) {
    cin >> i.first >> i.second;
  }
  for (int i = 0; i < 20; ++i) {
    if (fabs(dis(a[i], a[(i + 1) % 20]) - 9) < eps) {
      auto a1 = a[i], a2 = a[(i + 1) % 20], a3 = a[(i + 2) % 20];
      if ((mulX(a1, a2, a3) > 0 && (fabs(dis(a2, a3) - 8) < eps)) ||
          (mulX(a1, a2, a3) < 0 && (fabs(dis(a2, a3) - 6) < eps))) {
        cout << "right" << endl;
      } else {
        cout << "left" << endl;
      }
      return;
    }
  }
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int t;
  cin >> t;
  while (t--) {
    solve();
  }
}
