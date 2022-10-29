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
  int go[26], end;
} trie[10010];

int root = 1, tot = 0;

void insert(char *str) {
  int x = root;
  for (int i = 0; str[i]; i++) {
    int k = str[i] - 'a';
    if (!trie[x].go[k])
      trie[x].go[k] = ++tot;
    x = trie[x].go[k];
  }
  trie[x].end = 1;
}

int search(char *str) {
  int x = root;
  for (int i = 0; str[i]; ++i) {
    int k = str[i] - 'a';
    if (!trie[x].go[k])
      return 0;
    x = trie[x].go[k];
  }
  int ret = trie[x].end;
  trie[x].end = 2;
  return ret;
}

int main() {
  int n = read();
  char ch[55];
  while (n--) {
    scanf("%s", ch);
    insert(ch);
  }
  n = read();
  while (n--) {
    scanf("%s", ch);
    int t2 = search(ch);
    if (t2 == 1)
      puts("OK");
    else if (t2 == 2)
      puts("REPEAT");
    else
      puts("WRONG");
  }
  return 0;
}