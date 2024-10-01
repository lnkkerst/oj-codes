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
  Node(int _l, int _r = -1, char _v = 0) {
    l = _l, r = _r, v = _v;
  }
  bool operator<(const Node &b) const {
    return l < b.l;
  }
};

set<Node> nodes;

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

char readchar() {
  char ret;
  while (!isalpha(ret = getchar()))
    ;
  return toupper(ret);
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
  int _l = it->l, _r = it->r;
  char _v = it->v;
  nodes.erase(it), nodes.insert(Node(_l, pos - 1, _v));
  return nodes.insert(Node(pos, _r, _v)).first;
}

void assign(int l, int r, char _v) {
  IT itr = split(r + 1), itl = split(l);
  nodes.erase(itl, itr), nodes.insert(Node(l, r, _v));
}

int count(int l, int r, char _v) {
  IT itr = split(r + 1), itl = split(l);
  int ret = 0;
  for (; itl != itr; ++itl) {
    if (itl->v == _v) {
      ret += itl->r - itl->l + 1;
    }
  }
  return ret;
}

void sort_odt(int l, int r) {
  IT itr = split(r + 1), itl = split(l), it = itl;
  int arr[27] = {0};
  while (itl != itr) {
    arr[itl->v - 'A' + 1] += itl->r - itl->l + 1, ++itl;
  }
  nodes.erase(it, itr);
  for (int i = 1; i <= 26; ++i) {
    if (arr[i]) {
      nodes.insert(Node(l, l + arr[i] - 1, i + 'A' - 1)), l += arr[i];
    }
  }
}

int main() {
  int n = read(), m = read(), cnt = 1, cntl = 1;
  char ch, last = readchar();
  for (int i = 2; i <= n; ++i) {
    ch = readchar();
    if (ch == last) {
      ++cnt;
    } else {
      nodes.insert(Node(cntl, cntl + cnt - 1, last)), last = ch, cntl += cnt,
                                                      cnt = 1;
    }
  }
  nodes.insert(Node(cntl, cntl + cnt - 1, last));
  for (int i = 1; i <= m; ++i) {
    int opt = read(), a = read(), b = read();
    if (opt == 1) {
      print(count(a, b, readchar())), putchar('\n');
    } else if (opt == 2) {
      assign(a, b, readchar());
    } else {
      sort_odt(a, b);
    }
  }
  return 0;
}
