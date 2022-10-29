#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

bool cmp(pair<int, int> &a, pair<int, int> &b) {
  int aa = a.first * a.first + a.second * a.second;
  int bb = b.first * b.first + b.second * b.second;
  return aa > bb;
}

int calc(vector<pair<int, int>> &a) {
  int ret = 0;
  // cout << a.size();
  for (auto i : a) {
    for (auto j : a) {
      int x = i.first - j.first;
      int y = i.second - j.second;
      ret += x * x + y * y;
      // cout << x << ' ' << y << endl;
    }
    // cout << i.first << ' ' << i.second << endl;
  }
  // cout << ret << endl;
  return ret >> 1;
}

bool inArea(int r, int x, int y) { return x * x + y * y <= r * r; }

vector<int> aa;
vector<pair<int, int>> a;
vector<bool> b;
int ans;

void dfs(int n, int m, int dep, int pre) {
  if (dep == m + 1) {
    vector<pair<int, int>> cc;
    for (int i = 1; i <= m; ++i) {
      cc.push_back(a[aa[i] - 1]);
      // cout << aa[i] << ' ';
    }
    // cout << endl;
    ans = max(ans, calc(cc));
    return;
  }
  for (int i = pre + 1; i <= n; ++i) {
    aa[dep] = i;
    dfs(n, m, dep + 1, i);
  }
}

int main() {
  int t;
  cin >> t;
  while (t--) {
    a.clear();
    aa.clear();
    b.clear();
    ans = -1;
    int n, r;
    cin >> n >> r;
    for (int i = -r; i <= r; ++i) {
      for (int j = -r; j <= r; ++j) {
        if (inArea(r, i, j)) {
          a.push_back({i, j});
        }
      }
    }
    sort(a.begin(), a.end(), cmp);
    a.erase(min(a.end(), a.begin() + 50), a.end());
    // for(auto i : a) {
    // 	cout << i.first << ' ' << i.second << endl;
    // }
    // cout << endl;
    // cout << a.size() << endl;
    aa.resize(a.size() + 1);
    dfs((int)a.size(), n, 1, 0);
    cout << ans << endl;
  }
  return 0;
}