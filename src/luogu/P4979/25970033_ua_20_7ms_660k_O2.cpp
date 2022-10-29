#include <cctype>
#include <cstdio>
#include <cstring>
#include <iostream>
#include <set>
#define IT set<Node>::iterator
using namespace std;

struct Node {
  int l, r;
  mutable char v;
  Node(int _l, int _r = -1, char _v = 0) { l = _l, r = _r, v = _v; }
  bool operator<(const Node &b) const { return l < b.l; }
};

set<Node> nodes;

int read() {
  int ret, f = 1;
  char ch;
  while (!isdigit(ch = getchar()))
    (ch == '-') && (f = -1);
  for (ret = ch - '0'; isdigit(ch = getchar()); ret *= 10, ret += ch - '0')
    ;
  return ret * f;
}

char readchar() {
  char ret;
  while (!isalpha(ret = getchar()))
    ;
  return toupper(ret);
}

void print(int x) {
  if (x < 0)
    putchar('-'), x = -x;
  if (x > 9)
    print(x / 10);
  putchar(x % 10 + '0');
}

IT split(int pos) {
  IT it = nodes.lower_bound(Node(pos));
  if (it != nodes.end() && it->l == pos)
    return it;
  --it;
  int _l = it->l, _r = it->r;
  char _v = it->v;
  nodes.erase(it), nodes.insert(Node(_l, pos - 1, _v));
  return nodes.insert(Node(pos, _r, _v)).first;
}

void assign(int l, int r, char _v) {
  IT itr = split(r + 1), itl = split(l);
  nodes.erase(itl, itr), nodes.insert(Node(l, r, _v));
}
int n;
bool query(int l, int r) {
  IT itr = split(r + 1), itl = split(l);
  char ch = itl->v;
  for (; itl != itr; ++itl)
    if (itl->v != ch)
      return 0;
  return 1;
}

bool check(int l, int r) {
  if (l == 1 || l == n || r == 1 || r == n)
    return query(l, r);
  else {
    char b = split(r + 1)->v, a = split(l - 1)->v;
    return (a != b && query(l, r));
  }
}

int main() {
  n = read();
  int cnt = 1, cntl = 1;
  char ch, last = readchar();
  for (int i = 2; i <= n; ++i) {
    ch = readchar();
    if (ch == last)
      ++cnt;
    else
      nodes.insert(Node(cntl, cntl + cnt - 1, last)), last = ch, cntl += cnt,
                                                      cnt = 1;
  }
  nodes.insert(Node(cntl, cntl + cnt - 1, last));
  int m = read();
  for (int i = 1; i <= m; ++i) {
    char opt = readchar(), a = read(), b = read();
    if (opt == 'A')
      assign(a, b, readchar());
    else
      puts(check(a, b) ? "Yes" : "No");
  }
  return 0;
}