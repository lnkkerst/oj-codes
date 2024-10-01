#include <bits/stdc++.h>
#define int long long
using namespace std;

struct Node {
  int l, r;
  mutable int v;
  Node(int _l, int _r = -1, int _v = 0) {
    l = _l, r = _r, v = _v;
  }
  bool operator<(const Node &b) const {
    return l < b.l;
  }
};

set<Node> nodes;

#define IT set<Node>::iterator

IT split(int pos) {
  IT it = nodes.lower_bound(Node(pos));
  if (it != nodes.end() && it->l == pos) {
    return it;
  }
  --it;
  int _l = it->l, _r = it->r, _v = it->v;
  nodes.erase(it), nodes.insert(Node(_l, pos - 1, _v));
  return nodes.insert(Node(pos, _r, _v)).first;
}

void assign(int l, int r, int _v = 0) {
  IT itl = split(l), itr = split(r + 1);
  nodes.erase(itl, itr), nodes.insert(Node(l, r, _v));
}

void add(int l, int r, int _v = 1) {
  IT itl = split(l), itr = split(r + 1);
  while (itl != itr) {
    itl->v += _v, ++itl;
  }
}

int calc_rank(int l, int r, int k) {
  vector<pair<int, int>> q;
  q.clear();
  IT itl = split(l), itr = split(r + 1);
  while (itl != itr) {
    q.push_back(make_pair(itl->v, itl->r - itl->l + 1)), ++itl;
  }
  sort(q.begin(), q.end());
  for (int i = 0; i < (int)q.size(); ++i) {
    k -= q[i].second;
    if (k <= 0) {
      return q[i].first;
    }
  }
  return -1;
}

int pow(int a, int b, int mod) {
  int ret = 1, ans = a % mod;
  while (b) {
    if (b & 1) {
      ret = ret * ans % mod;
    }
    ans *= ans, ans %= mod, b >>= 1;
  }
  return ret;
}

int sum(int l, int r, int ex, int mod) {
  IT itl = split(l), itr = split(r + 1);
  int ret = 0;
  while (itl != itr) {
    ret = (ret + (itl->r - itl->l + 1) * pow(itl->v, ex, mod)) % mod, ++itl;
  }
  return ret;
}

int n, m, seed, vmax;
int a[100010];

int rnd() {
  int ret = seed;
  seed = (seed * 7 + 13) % 1000000007;
  return ret;
}

#undef int
int main() {
#define int long long
  cin >> n >> m >> seed >> vmax;
  for (int i = 1; i <= n; ++i) {
    a[i] = (rnd() % vmax) + 1, nodes.insert(Node(i, i, a[i]));
  }
  nodes.insert(Node(n + 1, n + 1, 0));
  for (int i = 1; i <= m; ++i) {
    int opt = (rnd() % 4) + 1, l = (rnd() % n) + 1, r = (rnd() % n) + 1;
    if (l > r) {
      swap(l, r);
    }
    int x = opt == 3 ? rnd() % (r - l + 1) + 1 : rnd() % vmax + 1, y;
    if (opt == 4) {
      y = rnd() % vmax + 1;
    }
    if (opt == 1) {
      add(l, r, x);
    } else if (opt == 2) {
      assign(l, r, x);
    } else if (opt == 3) {
      cout << calc_rank(l, r, x) << endl;
    } else {
      cout << sum(l, r, x, y) << endl;
    }
  }
  return 0;
}
