#include <cctype>
#include <cstdio>
#include <iostream>
using namespace std;

int main() {
  string s;
  cin >> s;
  if (s.substr(0, 3) != "MDA") {
    puts("1 1 1 1 1");
    return 0;
  }
  int num;
  for (auto i = s.rbegin(); i != s.rend(); ++i) {
    if (isdigit(*i)) {
      num = *i - '0';
      break;
    }
  }
  printf("%c %c %c %c %c\n", (num == 1 || num == 9) + '0',
         (num == 2 || num == 8) + '0', (num == 3 || num == 7) + '0',
         (num == 4 || num == 6) + '0', (num == 5 || num == 0) + '0');
  return 0;
}
