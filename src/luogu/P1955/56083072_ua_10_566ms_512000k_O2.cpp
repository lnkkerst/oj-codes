#include <iostream>
#include <unordered_map>
#include <vector>
using namespace std;

vector<int> fa;
vector<pair<int, int>> a, b;
int n, cnt;
unordered_map<int, int> id;

int find(int x) {
  return fa[x] == x ? x : fa[x] = find(fa[x]);
}

void merge(int x, int y) {
  fa[find(x)] = find(y);
}

int main() {
  int t;
  cin >> t;
  while (t--) {
    cin >> n;
    a.clear();
    b.clear();
    id.clear();
    cnt = 0;
    for (int k = 1; k <= n; ++k) {
      int i, j, e;
      cin >> i >> j >> e;
      if (id.find(i) == id.end()) {
        id[i] = ++cnt;
      }
      if (id.find(j) == id.end()) {
        id[j] = ++cnt;
      }
      if (e == 1) {
        a.emplace_back(make_pair(i, j));
      } else {
        b.emplace_back(make_pair(i, j));
      }
    }
    fa = vector<int>{cnt + 1};
    for (int i = 1; i <= n; ++i) {
      fa[i] = i;
    }
    for (auto i : a) {
      merge(i.first, i.second);
    }
    auto ans = "YES";
    for (auto i : b) {
      if (find(i.first) == find(i.second)) {
        ans = "NO";
        break;
      }
    }
    cout << ans << endl;
  }
  return 0;
}
