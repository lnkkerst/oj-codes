#include <cstring>
#include <deque>
#include <iostream>
#include <map>
#include <set>
#include <vector>
using namespace std;

char s[2000010];
int n, q;

int main() {
  scanf("%s%d", s, &q);
  n = strlen(s);
  int pos = 0;
  for (int i = 1; i <= q; ++i) {
    char c;
    int x;
    scanf(" %c %d", &c, &x);
    if (c == 'A') {
      printf("%c\n", s[(pos + x - 1 + n) % n]);
    } else {
      pos += x;
      pos = (pos + n) % n;
    }
  }
}
