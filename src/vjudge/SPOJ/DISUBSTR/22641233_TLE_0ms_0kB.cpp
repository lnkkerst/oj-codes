#include <bits/stdc++.h>
#include <cstdio>
#include <iostream>
#include <map>
using namespace std;

unordered_map<string, bool> b;
int n;
string s;
int main() {
  scanf("%d", &n);
  int cnt = 0;
  while (n--) {
    b.clear();
    cin >> s;
    int l = 0, size = 1, ans = 0;
    while (size <= s.length()) {
      if (l + size > s.length()) {
        ++size;
        l = 0;
        continue;
      }
      if (!b[s.substr(l, size)]) {
        ++ans, b[s.substr(l, size)] = 1;
      }
      ++l;
      ++cnt;
    }
    printf("%d\n", ans);
  }
  return 0;
}
