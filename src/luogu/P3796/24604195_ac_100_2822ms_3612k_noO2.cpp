#include <bits/stdc++.h>

using namespace std;

int read() {
  int ret;
  bool flag = 0;
  char ch;
  while (!isdigit(ch = getchar())) {
    (ch == '-') && (flag = 1);
  }
  for (ret = ch - '0'; isdigit(ch = getchar()); ret *= 10, ret += ch - '0')
    ;
  return flag ? -ret : ret;
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
} trie[1008611];

struct count {
  int pos, no;
} ans[1008611];

char s[151][1008611];
int cnt = 0;

void clean(int x) {
  memset(trie[x].go, 0, sizeof(trie[x].go));
  trie[x].end = 0;
  trie[x].fail = 0;
}

void insert(char *str, int no) {
  int l = strlen(str);
  int x = 0;
  for (int i = 0; i < l; i++) {
    int k = str[i] - 'a';
    if (!trie[x].go[k]) {
      trie[x].go[k] = ++cnt, clean(cnt);
    }
    x = trie[x].go[k];
  }
  trie[x].end = no;
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

void query(char *s) {
  int l = strlen(s);
  int now = 0;
  for (int i = 0; i < l; ++i) {
    now = trie[now].go[s[i] - 'a'];
    for (int t = now; t; t = trie[t].fail) {
      ++ans[trie[t].end].no;
    }
  }
}

bool cmp(struct count a, struct count b) {
  if (a.no != b.no) {
    return a.no > b.no;
  } else {
    return a.pos < b.pos;
  }
}

void work(int n) {
  cnt = 0;
  clean(0);
  for (int i = 1; i <= n; ++i) {
    scanf("%s", s[i]);
    ans[i].no = 0;
    ans[i].pos = i;
    insert(s[i], i);
  }
  init_fail();
  scanf("%s", s[0]);
  query(s[0]);
  sort(ans + 1, ans + n + 1, cmp);
  cout << ans[1].no << endl << s[ans[1].pos] << endl;
  for (int i = 2; i <= n; ++i) {
    if (ans[i].no == ans[i - 1].no) {
      cout << s[ans[i].pos] << endl;
    } else {
      break;
    }
  }
  return;
}

int main() {
  while (233) {
    int qus = read();
    if (!qus) {
      return 0;
    }
    work(qus);
  }
}
