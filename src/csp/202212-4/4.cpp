#pragma GCC optimize(2)
#include <algorithm>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#include <iostream>
#include <set>
#include <vector>

#define int long long

using namespace std;
using namespace __gnu_pbds;

using Element = pair<int, int>;
using Tree = tree<Element, null_type, less<Element>, rb_tree_tag,
                  tree_order_statistics_node_update>;

struct Node {
  Tree *tree = nullptr;
  int fa = 0;
  vector<int> son;
  int ans = 0;
  int a = 0;
  bool vis = false;
  int sonfin = 0;
};

int n;
vector<Node> a;
int globalCnt = 0;

int calc(vector<int> &a) {
  int res = 0;
  if (a.size() <= 1) {
    return 0;
  }
  res += (a[0] - a[1]) * (a[0] - a[1]);
  res +=
      (a[a.size() - 1] - a[a.size() - 2]) * (a[a.size() - 1] - a[a.size() - 2]);
  for (int i = 1; i < a.size() - 1; ++i) {
    int t1 = a[i] - a[i - 1];
    int t2 = a[i] - a[i + 1];
    res += min(t1 * t1, t2 * t2);
  }
  return res;
}

void dfs(int u) {
  if (a[u].vis) {
    return;
  }

  if (a[u].son.size() != a[u].sonfin) {
    return;
  }

  if (a[u].son.size() == 0) {
    a[u].tree = new Tree();
    a[u].tree->insert({a[u].a, ++globalCnt});
    a[a[u].fa].sonfin++;
    a[u].vis = true;
    dfs(a[u].fa);
    return;
  }

  int sid = a[u].son.front();
  Tree *s = a[sid].tree;
  for (auto i : a[u].son) {
    if (a[i].tree->size() > s->size()) {
      s = a[i].tree;
      sid = i;
    }
  }
  a[u].ans = a[sid].ans;
  for (auto i : a[u].son) {
    if (a[i].tree == s) {
      continue;
    }
    // for (auto i : *s) {
    //   cout << i.first << ' ' << i.second << endl;
    // }
    // cout << endl;
    // for (auto i : *a[i].tree) {
    //   cout << i.first << ' ' << i.second << endl;
    // }
    s->join(*a[i].tree);
    delete a[i].tree;
    a[i].tree = nullptr;
  }
  a[sid].tree = nullptr;
  s->insert({a[u].a, ++globalCnt});
  a[a[u].fa].sonfin++;
  a[u].vis = true;
  a[u].tree = s;
  dfs(a[u].fa);
  return;
}

void solve() {
  cin >> n;
  a.resize(n + 1);
  a[1].fa = 1;
  for (int i = 2; i <= n; ++i) {
    int x;
    cin >> x;
    a[i].fa = x;
    a[x].son.emplace_back(i);
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
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int t;
  // cin >> t;
  t = 1;
  while (t--) {
    solve();
  }
}
