#include <iostream>
using namespace std;

int main() {
  string s;
  cin >> s;
  for (int i = 0; i < (int)s.length() - 1; ++i)
    printf("%d ", s[i] != s[i + 1]);
  printf("%d", s[(int)s.length()] == 'a');
  return 0;
}