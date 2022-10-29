#include <algorithm>
#include <cmath>
#include <iomanip>
#include <iostream>
#include <vector>
using namespace std;

struct Node {
  double x, y;
  bool operator<(const Node &b) const {
    return this->x == b.x ? this->y < b.y : this->x < b.x;
  }
};

double calcDis(const Node &a, const Node &b) {
  double tx = (a.x - b.x) * (a.x - b.x);
  double ty = (a.y - b.y) * (a.y - b.y);
  return sqrt(tx + ty);
}

double solve(vector<Node> a, int l, int r) {
  if (l == r)
    return 1e20;
  if (l + 1 == r)
    return calcDis(a[l], a[r]);
  int mid = (l + r) >> 1;
  double dist = min(solve(a, l, mid), solve(a, mid + 1, r));
  vector<Node> q;
  for (int i = l; i < r; ++i)
    if (fabs(a[mid].x - a[i].x) < dist)
      q.push_back(a[i]);
  sort(q.begin(), q.end(),
       [](const Node &a, const Node &b) { return a.y < b.y; });
  for (auto i = q.begin(); i != q.end(); ++i)
    for (auto j = i + 1; j != q.end() && (j->y - i->y) < dist; ++j)
      dist = min(dist, calcDis(*i, *j));
  return dist;
}

int main() {
  int n;
  cin >> n;
  vector<Node> a(n);
  for (int i = 0; i < n; ++i)
    cin >> a[i].x >> a[i].y;
  sort(a.begin(), a.end());
  cout << fixed << setprecision(4) << solve(a, 0, (int)a.size() - 1);
  return 0;
}