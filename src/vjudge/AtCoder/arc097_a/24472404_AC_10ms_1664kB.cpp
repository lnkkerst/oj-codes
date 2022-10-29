#include <iostream>
#include <set>
#include <vector>
using namespace std;

string s;
set<string> a;
int k;

int main() {
  cin >> s >> k;
  for (int i = 0; i < (int)s.length(); ++i) {
    int tot = min(k, (int)s.length() - i);
    for (int j = 1; j <= tot; ++j)
      a.insert(s.substr(i, j));
  }
  int pos = 0;
  for (auto i : a) {
    ++pos;
    if (pos == k) {
      cout << i;
      return 0;
    }
  }
}