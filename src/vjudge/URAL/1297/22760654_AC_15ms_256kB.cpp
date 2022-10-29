#include <algorithm>
#include <cctype>
#include <cstdio>
const int MAXN = 23333;
using namespace std;

char ch, s[MAXN << 1] = {'~', '#'};
int p[MAXN << 1], cnt = 1;

int main() {
  while (!isalpha(ch = getchar()))
    ;
  for (s[++cnt] = ch, s[++cnt] = '#'; isalpha(ch = getchar());
       s[++cnt] = ch, s[++cnt] = '#')
    ;
  int id, mx = 0;
  for (int i = 1; i < cnt; ++i) {
    if (mx > 1)
      p[i] = min(p[2 * id - i], mx - i);
    else
      p[i] = 1;
    while (s[i + p[i]] == s[i - p[i]])
      ++p[i];
    if (i + p[i] > mx)
      mx = i + p[i], id = i;
  }
  int maxn = -1, maxa;
  for (int i = 1; i <= cnt; ++i)
    if (p[i] > maxn)
      maxn = p[i], maxa = i;
  for (int i = maxa - maxn + 2; i <= maxa + maxn - 2; i += 2)
    putchar(s[i]);
  return 0;
}