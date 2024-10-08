#include <algorithm>
#include <cstdio>
#include <iostream>
#include <set>
#define IT set<Node>::iterator
using namespace std;

struct Node {
  int l, r;
  mutable bool v;
  Node(int _l, int _r = -1, bool _v = 0) {
    l = _l, r = _r, v = _v;
  }
  bool operator<(const Node &b) const {
    return l < b.l;
  }
};

set<Node> nodes;
int ans;

int read() {
  int ret, f = 1;
  char ch;
  while (!isdigit(ch = getchar())) {
    (ch == '-') && (f = -1);
  }
  for (ret = ch - '0'; isdigit(ch = getchar()); ret *= 10, ret += ch - '0')
    ;
  return ret * f;
}

void print(int x) {
  if (x < 0) {
    putchar('-'), x = -x;
  }
  if (x > 9) {
    print(x / 10);
  }
  putchar(x % 10 + '0');
}

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

void assign(int l, int r, bool _v) {
  IT itr = split(r + 1), itl = split(l), it = itl;
  while (itl != itr) {
    ans -= itl->v * (itl->r - itl->l + 1), ++itl;
  }
  nodes.erase(it, itr), nodes.insert(Node(l, r, _v));
  ans += _v * (r - l + 1);
}

int main() {
  int n = read(), m = read();
  ans = n;
  nodes.insert(Node(1, n, 1));
  for (int i = 1; i <= m; ++i) {
    int a = read(), b = read(), opt = read();
    if (opt == 1) {
      assign(a, b, 0);
    } else {
      assign(a, b, 1);
    }
    print(ans), putchar('\n');
  }
  return 0;
}
