#include <algorithm>
#include <cctype>
#include <cstdio>
#include <functional>
#include <iostream>
using namespace std;

string a;

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
    putchar('-'), x = -x;
  }
  if (x > 9) {
    print(x / 10);
  }
  putchar(x % 10 + '0');
}

int main() {
  read();
  cin >> a;
  int num = 0, l = 0, r = 0;
  for (auto i : a) {
    // if(i == '(' && num >= 0) ++r;
    if (i == ')' && !num) {
      ++l;
    }
    num += i == '(' ? 1 : -1;
    num = max(0, num);
  }
  for (int i = 1; i <= l; ++i) {
    putchar('(');
  }
  cout << a;
  for (int i = 1; i <= num; ++i) {
    putchar(')');
  }
  return 0;
}
