#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

#define int long long

struct Node {
  int x1, x2, y1, y2;
  Node(int _x1, int _y1, int _x2, int _y2)
    : x1(_x1), y1(_y1), x2(_x2), y2(_y2) {}
};

int n;
vector<Node> a;
int ta, tb;

int merge(Node a, Node b) {
  int ax1 = max(a.x1, b.x1);
  int ay1 = max(a.y1, b.y1);
  int ax2 = min(a.x2, b.x2);
  int ay2 = min(a.y2, b.y2);
  return max(0ll, (ax2 - ax1) * (ay2 - ay1));
}

signed main() {
  cin >> n >> ta >> tb;
  int ans = 0;
  for (int i = 1; i <= n; ++i) {
    int x1, x2, y1, y2;
    cin >> x1 >> y1 >> x2 >> y2;
    if (x1 >= ta || y1 >= tb) {
      continue;
    }
    if (x2 <= 0 || y2 <= 0) {
      continue;
    }
    int tmp = 0;
    Node na = Node(x1, y1, x2, y2);
    Node nb = Node(0ll, 0ll, ta, tb);
    tmp = max(tmp, merge(na, nb));
    tmp = max(tmp, merge(nb, na));
    ans += tmp;
  }
  cout << ans << endl;
}
