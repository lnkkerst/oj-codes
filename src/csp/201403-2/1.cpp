#include <iostream>
#include <vector>
using namespace std;

int n, m;
vector<int> a[2560][1440];
vector<int> b;

int main() {
  cin >> n >> m;
  b.resize(n + 1);
  for (int i = 1; i <= n; ++i) {
    int x1, y1, x2, y2;
    cin >> x1 >> y1 >> x2 >> y2;
    for (int k = x1; k <= x2; ++k) {
      for (int j = y1; j <= y2; ++j) {
        a[k][j].emplace_back(i);
      }
    }
    b[i] = i;
  }
  int maw = n;
  for (int i = 1; i <= m; ++i) {
    int x, y;
    cin >> x >> y;
    if (a[x][y].empty()) {
      cout << "IGNORED" << endl;
      continue;
    }
    int mai = a[x][y].front();
    int ma = b[mai];
    for (auto i : a[x][y]) {
      if (b[i] > ma) {
        mai = i;
        ma = b[i];
      }
    }
    b[mai] = maw + 1;
    maw++;
    cout << mai << endl;
  }
}
