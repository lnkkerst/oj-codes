#include <iostream>
#include <vector>
using namespace std;

int main() {
  string s, t;
  cin >> t >> s;
  int ls = s.size(), lt = t.size();
  s = " " + s;
  t = " " + t;
  vector<int> next(ls + 1);
  int j = 0;
  for (int i = 2; i <= ls; ++i) {
    while (j && s[j + 1] != s[i]) {
      j = next[j];
    }
    if (s[j + 1] == s[i]) {
      ++j;
    }
    next[i] = j;
  }
  j = 0;
  for (int i = 1; i <= lt; ++i) {
    while (j && s[j + 1] != t[i]) {
      j = next[j];
    }
    if (s[j + 1] == t[i]) {
      ++j;
    }
    if (j == ls) {
      cout << i - j + 1 << endl;
    }
  }
  for (int i = 1; i <= ls; ++i) {
    cout << next[i] << ' ';
  }
}
