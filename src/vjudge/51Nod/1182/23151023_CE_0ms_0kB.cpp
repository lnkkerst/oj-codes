#include <algorithm>
#include <cctype>
#include <cstdio>
#include <iostream>
using std::cin, std::cout, std::endl;
using std::sort, std::min, std::max;

int cnt[27], ans;
char ch;

int main() {
  while (cin >> ch) {
    ++cnt[tolower(ch) - 'a' + 1];
  }
  sort(cnt + 1, cnt + 27);
  for (int i = 1; i <= 26; ++i) {
    ans += cnt[i] * i;
  }
  cout << ans << endl;
  return 0;
}
