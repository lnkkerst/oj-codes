#include <cctype>
#include <cstdio>

using namespace std;

int read() {
  int res;
  bool flag = 0;
  char ch;
  while (!isdigit(ch = getchar()))
    (ch == '-') && (flag = 1);
  for (res = ch - '0'; isdigit(ch = getchar()); res *= 10, res += ch - '0')
    ;
  (flag == 1) && (res *= -1);
  return res;
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
  int go[26];
  bool book[110];
} trie[9000100];

int root = 0, tot = 0, n, m;
char ch[25];

void insert(char *str, int j) {
  int x = root;
  for (int i = 0; str[i]; i++) {
    int k = str[i] - 'a';
    if (!trie[x].go[k])
      trie[x].go[k] = ++tot;
    x = trie[x].go[k];
  }
  trie[x].book[j] = 1;
}

void search(char *str) {
  int x = root;
  bool flag = 1;
  for (int i = 0; str[i]; ++i) {
    int k = str[i] - 'a';
    if (!trie[x].go[k]) {
      flag = 0;
      break;
    }
    x = trie[x].go[k];
  }
  if (flag) {
    for (int i = 1; i <= n; ++i)
      if (trie[x].book[i])
        printf("%d ", i);
  }
  putchar('\n');
}

int main() {
  n = read();
  for (int i = 1; i <= n; ++i) {
    int t1 = read();
    for (int j = 0; j < t1; ++j) {
      scanf("%s", ch);
      insert(ch, i);
    }
  }
  m = read();
  for (int i = 1; i <= m; ++i) {
    scanf("%s", ch);
    search(ch);
  }
  return 0;
}