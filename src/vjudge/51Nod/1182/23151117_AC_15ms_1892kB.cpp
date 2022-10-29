#include <algorithm>
#include <cctype>
#include <cstdio>
#include <iostream>

int cnt[27], ans;
char ch;

int main() {
  while (std::cin >> ch)
    ++cnt[tolower(ch) - 'a' + 1];
  std::sort(cnt + 1, cnt + 27);
  for (int i = 1; i <= 26; ++i)
    ans += cnt[i] * i;
  return std::cout << ans, 0;
}