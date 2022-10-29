#include <iostream>
using namespace std;

string a, b;

int main() {
  cin >> a;
  getline(cin, b);
  getline(cin, b);
  for (auto &i : a)
    i = tolower(i);
  for (auto &i : b)
    i = tolower(i);
  a.push_back(' ');
  b.push_back(' ');
  int pos = b.find(a);
  if (pos == string::npos) {
    puts("-1");
    return 0;
  }
  int ans = 0;
  while (pos != string::npos) {
    pos = b.find(a, pos + 1);
    ++ans;
  }
  cout << ans << ' ' << b.find(a) << endl;
  return 0;
}