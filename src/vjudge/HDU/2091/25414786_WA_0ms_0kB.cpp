#include <iostream>
using namespace std;

void draw(char c, int x) {
  for (int i = 1; i < x; ++i) {
    putchar(' ');
  }
  putchar(c);
  puts("");
  for (int i = 2; i < x; ++i) {
    for (int j = 1; j <= x - i; ++j) {
      putchar(' ');
    }
    putchar(c);
    for (int j = 1; j <= i * 2 - 3; ++j) {
      putchar(' ');
    }
    putchar(c);
    puts("");
  }
  for (int i = 1; i <= x * 2 - 1; ++i) {
    putchar(c);
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
