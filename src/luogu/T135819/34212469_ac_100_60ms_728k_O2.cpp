#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

int main() {
  int n;
  cin >> n;
  vector<string> a(n);
  for (auto &i : a) {
    cin >> i;
  }
  sort(a.begin(), a.end(), [](const string &a, const string &b) -> bool {
    return (a + b) > (b + a);
  });
  string ans;
  for (const auto &i : a) {
    ans.append(i);
  }
  cout << ans;
  return 0;
}
