#include <cstdio>
#include <iostream>
using namespace std;

void draw(char c, int x) {
  bool fl = 0;
  for (int i = 1; i <= x; ++i) {
    if (fl) {
      puts("");
    }
    fl = 1;
    for (int j = 1; j <= x + i - 1; ++j) {
      putchar(i == x || j == x - i + 1 || j == x + i - 1 ? c : ' ');
    }
  }
}

int main() {
  char ch;
  int cnt;
  bool fl = 0;
  while (cin >> ch) {
    if (ch == '@') {
      return 0;
    }
    cin >> cnt;
    if (fl) {
      cout << "\n\n";
    }
    draw(ch, cnt);
    fl = 1;
  }
  return 0;
}
