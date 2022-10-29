#include <stdio.h>

struct Trie {
  int to[26], end;
} t[23333];

int root = 0, cnt;

void insert(char s[]) {
  int now = root;
  for (int i = 0; s[i]; ++i) {
    int v = s[i] - 'a';
    if (!t[now].to[v])
      t[now].to[v] = ++cnt;
    now = t[now].to[v];
    ++t[now].end;
  }
}

char *query(char s[]) {
  char ret[20];
  int now = root, i;
  for (i = 0; s[i] != '\0'; ++i) {
    int v = s[i] - 'a';
    ret[i] = s[i];
    if (t[t[now].to[v]].end == 1) {
      ret[i + 1] = '\0';
      return ret;
    }
    now = t[now].to[v];
  }
  return s;
}

char str[1001][21];
int tot;

int main() {
  while (scanf("%s", str[++tot]) != EOF)
    insert(str[tot]);
  for (int i = 1; i <= tot; ++i)
    printf("%s %s\n", str[i], query(str[i]));
  return 0;
}