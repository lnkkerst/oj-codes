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

const int inf = 1e9;

struct info {
  int ans, mn, mx;
  pair<int, int> lmost, rmost;
  info() : ans(-inf), mn(-inf), mx(inf), lmost(), rmost() {}
  info(int c, int x) : ans(0), mn(x), mx(x), lmost(c, x), rmost(c, x) {}
  friend info operator+(const info &lhs, const info &rhs) {
    if (lhs.ans < 0)
      return rhs;
    if (rhs.ans < 0)
      return lhs;
    info res;
    res.ans = max({lhs.ans, rhs.ans, rhs.mn - lhs.mx});
    res.mn = min(lhs.mn, rhs.mn);
    res.mx = max(lhs.mx, rhs.mx);
    res.lmost = lhs.lmost;
    res.rmost = rhs.rmost;
    return res;
  }
};

template <class Node_CItr, class Node_Itr, class Cmp_Fn, class _Alloc>
struct my_node_update {
private:
  using Key = pair<int, int>;
  info query(Node_CItr it, Key L, Key R) {
    if (it == node_end())
      return info();
    if (L <= it.get_metadata().lmost && it.get_metadata().rmost < R)
      return it.get_metadata();
    Key key = **it;
    if (key >= R)
      return query(it.get_l_child(), L, R);
    if (key < L)
      return query(it.get_r_child(), L, R);
    return query(it.get_l_child(), L, R) + info((*it)->first, (*it)->second) +
           query(it.get_r_child(), L, R);
  }

public:
  typedef info metadata_type;
  void operator()(Node_Itr it, Node_CItr end_it) {
    info res((*it)->first, (*it)->second);
    Node_Itr lc = it.get_l_child();
    Node_Itr rc = it.get_r_child();
    if (lc != end_it)
      res = lc.get_metadata() + res;
    if (rc != end_it)
      res = res + rc.get_metadata();
    const_cast<metadata_type &>(it.get_metadata()) = res;
  }
  info query(Key L, Key R) { return query(node_begin(), L, R); }
  virtual Node_CItr node_begin() const = 0;
  virtual Node_CItr node_end() const = 0;
};

using Element = pair<int, int>;
using Tree =
    tree<Element, null_type, less<Element>, rb_tree_tag, my_node_update>;

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
int globalCnt;

int calc(Tree &s) {
  int res = 0;
  vector<int> a;
  for (auto &i : s) {
    a.emplace_back(i.first);
  }
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
  for (auto i : a[u].son) {
    if (a[i].tree == s) {
      continue;
    }
    s->join(*a[i].tree);
    delete a[i].tree;
    a[i].tree = nullptr;
  }
  a[sid].tree = nullptr;
  s->insert({a[u].a, ++globalCnt});
  a[a[u].fa].sonfin++;
  a[u].vis = true;
  a[u].tree = s;
  a[u].ans = calc(*s);
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
