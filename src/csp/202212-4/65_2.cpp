#pragma GCC optimize(2)
#include <algorithm>
#include <iostream>
#include <set>
#include <vector>

#define int long long

using namespace std;

struct Node {
  multiset<int> *tree = nullptr;
  int fa = 0;
  vector<int> son;
  int ans = 0;
  int a = 0;
  bool vis = false;
  int sonfin = 0;
};

int n;
vector<Node> a;

int calc1(multiset<int> &s) {
  int res = 0;
  vector<int> a{s.begin(), s.end()};
  if (a.size() <= 1) {
    return 0;
  }
  res += (a[0] - a[1]) * (a[0] - a[1]);
  res += (a[a.size() - 1] - a[a.size() - 2])
         * (a[a.size() - 1] - a[a.size() - 2]);
  for (int i = 1; i < a.size() - 1; ++i) {
    int t1 = a[i] - a[i - 1];
    int t2 = a[i] - a[i + 1];
    res += min(t1 * t1, t2 * t2);
  }
  return res;
}

int calc(vector<int> &a) {
  int res = 0;
  if (a.size() <= 1) {
    return 0;
  }
  res += (a[0] - a[1]) * (a[0] - a[1]);
  res += (a[a.size() - 1] - a[a.size() - 2])
         * (a[a.size() - 1] - a[a.size() - 2]);
  for (int i = 1; i < a.size() - 1; ++i) {
    int t1 = a[i] - a[i - 1];
    int t2 = a[i] - a[i + 1];
    res += min(t1 * t1, t2 * t2);
  }
  return res;
}

int insert(multiset<int> &s, int x) {
  auto it = s.insert(x);
  if (s.size() == 1) {
    return 0;
  }

  if (s.size() == 2) {
    int l = *s.begin();
    int r = *s.rbegin();
    int t1 = l - r;
    return t1 * t1 * 2;
  }
  vector<int> tmp1;
  int cnt = 0;
  for (int i = 1; i <= 2; ++i) {
    if (it == s.begin()) {
      break;
    }
    --it;
    ++cnt;
  }
  for (int i = 1; i <= 5 && it != s.end(); ++i) {
    tmp1.emplace_back(*it);
    ++it;
  }
  auto tmp2 = tmp1;
  tmp2.erase(tmp2.begin() + cnt);
  return calc(tmp1) - calc(tmp2);
}

int insert1(multiset<int> &s, int x) {
  auto it = s.insert(x);
  if (s.size() == 1) {
    return 0;
  }

  if (s.size() == 2) {
    int l = *s.begin();
    int r = *s.rbegin();
    int t1 = l - r;
    return t1 * t1 * 2;
  }

  if (it == s.begin()) {
    int l = *it;
    ++it;
    int r = *it;
    return (l - r) * (l - r);
  }

  ++it;
  if (it == s.end()) {
    --it;
    int r = *it;
    --it;
    int l = *it;
    return (l - r) * (l - r);
  }
  int r = *it;
  --it;
  int mid = *it;
  --it;
  int l = *it;
  int t1 = (l - mid);
  int t2 = (mid - r);
  int t3 = (l - r);
  int res = min(t1 * t1, t2 * t2) - (t3 * t3);
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
    a[u].tree = new multiset<int>();
    insert(*a[u].tree, a[u].a);
    // a[u].tree->insert(a[u].a);
    a[a[u].fa].sonfin++;
    a[u].vis = true;
    dfs(a[u].fa);
    return;
  }

  int sid = a[u].son.front();
  multiset<int> *s = a[sid].tree;
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
    for (auto j : *a[i].tree) {
      a[u].ans += insert(*s, j);
    }
    // s->insert(a[i].tree->begin(), a[i].tree->end());
    delete a[i].tree;
    a[i].tree = nullptr;
  }
  a[sid].tree = nullptr;
  a[u].ans += insert(*s, a[u].a);
  // s->insert(a[u].a);
  a[a[u].fa].sonfin++;
  a[u].vis = true;
  a[u].tree = s;
  // a[u].ans = calc(*s);
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
