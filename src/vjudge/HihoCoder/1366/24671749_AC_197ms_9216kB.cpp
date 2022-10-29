#include <iostream>
#include <unordered_map>
using namespace std;

unordered_map<string, bool> b;
string str[50010], res;
int n, ans;

int main() {
  cin >> n;
  for (int i = 1; i <= n; ++i) {
    cin >> str[i];
    b[str[i]] = 1;
  }
  for (int i = 1; i <= n; ++i) {
    for (auto j = str[i].rbegin(); j != str[i].rend(); ++j)
      res += *j;
    if (b[res])
      ++ans, b[str[i]] = 0;
    res.clear();
  }
  cout << ans;
  return 0;
}