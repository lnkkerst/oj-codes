#include <iostream>
using namespace std;

int main() {
  string s;
  int n;
  cin >> s >> n;
  while (n--) {
    bool fl = 1;
    for (int i = 0; i < (int)s.length() - 1; ++i) {
      if (s[i] > s[i + 1]) {
        s.erase(i, 1);
        fl = 0;
        break;
      }
    }
    if (fl)
      s.pop_back();
  }
  int i = 0;
  for (; i < (int)s.length() && s[i] == '0'; ++i)
    ;
  if (i == (int)s.length())
    puts("0");
  else
    cout << s.substr(i) << endl;
  return 0;
}