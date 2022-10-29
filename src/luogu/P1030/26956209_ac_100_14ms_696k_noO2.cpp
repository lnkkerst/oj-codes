#include <algorithm>
#include <cctype>
#include <cstdio>
#include <iostream>
#include <string>

std::string s1, s2;

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

void dfs(std::string f, std::string to) {
  if (!f.empty()) {
    char ch = to[(int)to.size() - 1];
    putchar(ch);
    int no = f.find(ch);
    dfs(f.substr(0, no), to.substr(0, no));
    dfs(f.substr(no + 1), to.substr(no, (int)f.size() - no - 1));
  }
}

int main() {
  std::cin >> s1 >> s2;
  dfs(s1, s2);
  return 0;
}