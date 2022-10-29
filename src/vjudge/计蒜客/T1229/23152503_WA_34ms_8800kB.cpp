#include <cctype>
#include <cstdio>
#include <cstring>

struct Trie {
  int nex[200010][10], val[200010], root = 0, tot = 0;
  Trie() {
    memset(nex, 0, sizeof(nex));
    memset(val, 0, sizeof(val));
  }
  void insert(char str[]) {
    int now = root;
    for (int i = 0; str[i]; ++i) {
      int k = str[i] - '0';
      if (!nex[now][k])
        nex[now][k] = ++tot;
      now = nex[now][k];
    }
    ++val[now];
  }
  int query(char str[]) {
    int now = root;
    for (int i = 0; str[i]; ++i) {
      int k = str[i] - '0';
      if (!nex[now][k])
        return 0;
      now = nex[now][k];
    }
    return val[now];
  }
  void assign(char str[], int v) {
    int now = root;
    for (int i = 0; str[i]; ++i) {
      int k = str[i] - '0';
      if (!nex[now][k])
        nex[now][k] = ++tot;
      now = nex[now][k];
    }
    val[now] = v;
  }
} tree;

int read() {
  int ret, f = 1;
  char ch;
  while (!isdigit(ch = getchar()))
    (ch == '-') && (f = -1);
  for (ret = ch - '0'; isdigit(ch = getchar()); ret *= 10, ret += ch - '0')
    ;
  return ret * f;
}

void print(int x) {
  if (x < 0)
    putchar('-'), x = -x;
  if (x > 9)
    print(x / 10);
  putchar(x % 10 + '0');
}

int main() {
  int n = read();
  char opt[4], x[2333];
  while (n--) {
    scanf("%s%s", opt + 1, x);
    if (opt[1] == 'a' && opt[2] == 'd') {
      int ori = tree.query(x);
      print(ori + 1), putchar('\n');
      tree.assign(x, ori + 1);
    } else if (opt[1] == 'd') {
      print(tree.query(x)), putchar('\n');
      tree.assign(x, -1);
    } else {
      int ori = tree.query(x);
      print(ori ? 1 : 0), putchar(' ');
      print(ori > 0 ? ori : 0), putchar('\n');
    }
  }
  return 0;
}