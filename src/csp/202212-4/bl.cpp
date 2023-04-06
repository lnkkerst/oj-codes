#pragma GCC optimize(2)
#include <algorithm>
#include <iostream>
#include <set>
#include <vector>

#define int long long

using namespace std;

struct Node {
  multiset<int> sona;
  vector<int> sons;
  int fa;
  int a;
  int sonCnt = 0;
  int finCnt = 0;
  int ans;
  bool vis;
};

int n;
vector<Node> a;

void dfs(int u) {
  if (a[u].vis) {
    return;
  }
  if (a[u].sonCnt != a[u].finCnt) {
    return;
  }

  multiset<int> tmp;
  tmp.insert(a[u].a);

  for (auto i : a[u].sons) {
    tmp.insert(a[i].sona.begin(), a[i].sona.end());
  }

  a[u].sona = tmp;

  vector<int> tmpa{tmp.begin(), tmp.end()};
  sort(tmpa.begin(), tmpa.end());

  int anstmp = 0;
  if (tmpa.size() != 1) {
    int t1 = tmpa[0] - tmpa[1];
    anstmp += t1 * t1;
    t1 = tmpa[tmpa.size() - 1] - tmpa[tmpa.size() - 2];
    anstmp += t1 * t1;
    for (int i = 1; i < tmpa.size() - 1; ++i) {
      int t1 = tmpa[i] - tmpa[i - 1];
      int t2 = tmpa[i] - tmpa[i + 1];
      anstmp += min(t1 * t1, t2 * t2);
    }
  }
  a[u].ans = anstmp;
  a[a[u].fa].finCnt++;

  a[u].vis = true;

  if (u != 1) {
    dfs(a[u].fa);
  }
}

void solve() {
  cin >> n;
  a.resize(n + 1);
  a[1].fa = 1;
  for (int i = 2; i <= n; ++i) {
    cin >> a[i].fa;
    ++a[a[i].fa].sonCnt;
    a[a[i].fa].sons.emplace_back(i);
  }
  for (int i = 1; i <= n; ++i) {
    cin >> a[i].a;
  }
  for (int i = 1; i <= n; ++i) {
    dfs(i);
  }
  for (int i = 1; i <= n; ++i) {
    cout << a[i].ans << endl;
  }
}

signed main() {
  int t;
  // cin >> t;
  t = 1;
  while (t--) {
    solve();
  }
}
