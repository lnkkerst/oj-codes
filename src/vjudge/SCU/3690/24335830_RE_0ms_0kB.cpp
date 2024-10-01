#include <cctype>
#include <cstdio>
#include <cstring>
#include <iostream>
#include <queue>
using namespace std;

int read() {
  int ret, fl = 1;
  char ch;
  while (!isdigit(ch = getchar())) {
    (ch == '-') && (fl = -1);
  }
  for (ret = ch - '0'; isdigit(ch = getchar()); ret *= 10, ret += ch - '0')
    ;
  return ret * fl;
}

void print(int x) {
  if (x < 0) {
    putchar('-');
    x *= -1;
  }
  if (x > 9) {
    print(x / 10);
  }
  putchar(x % 10 + '0');
}

struct Trie {
  int go[26], end, fail;
} trie[18611];

char s[18611];
int cnt = 0;

void insert(char *str) {
  int l = strlen(s);
  int x = 0;
  for (int i = 0; i < l; i++) {
    int k = str[i] - 'a';
    if (!trie[x].go[k]) {
      trie[x].go[k] = ++cnt;
    }
    x = trie[x].go[k];
  }
  ++trie[x].end;
}

void init_fail() {
  trie[0].fail = 0;
  queue<int> q;
  for (int i = 0; i < 26; ++i) {
    if (trie[0].go[i]) {
      trie[trie[0].go[i]].fail = 0;
      q.push(trie[0].go[i]);
    }
  }
  while (!q.empty()) {
    int u = q.front();
    q.pop();
    for (int i = 0; i < 26; ++i) {
      if (trie[u].go[i]) {
        trie[trie[u].go[i]].fail = trie[trie[u].fail].go[i];
        q.push(trie[u].go[i]);
      } else {
        trie[u].go[i] = trie[trie[u].fail].go[i];
      }
    }
  }
}

int query(char *s) {
  int l = strlen(s);
  int now = 0, ret = 0;
  for (int i = 0; i < l; ++i) {
    now = trie[now].go[s[i] - 'a'];
    for (int t = now; t && trie[t].end != -1; t = trie[t].fail) {
      ret += trie[t].end;
      trie[t].end = -1;
    }
  }
  return ret;
}

int solve() {
  memset(trie, 0, sizeof(trie));
  for (int n = read(); n--; scanf("%s", s), insert(s))
    ;
  scanf("%s", s);
  init_fail();
  cout << query(s) << endl;
  return 0;
}

int main() {
  int t = read();
  while (t--) {
    solve();
  }
  return 0;
}
