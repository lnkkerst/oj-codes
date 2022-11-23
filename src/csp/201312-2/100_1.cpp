#include <cctype>
#include <iostream>
#include <vector>
using namespace std;

int main(int argc, char *argv[]) {
  string s;
  cin >> s;
  vector<int> a;
  for (auto i : s) {
    if (isdigit(i)) {
      a.emplace_back(i - '0');
    }
  }
  int r = 0;
  if (a.size() == 10) {
    r = a.back();
    a.pop_back();
  } else {
    r = 10;
  }
  int rs = 0;
  for (int i = 0; i < a.size(); ++i) {
    rs += (i + 1) * a[i];
  }
  rs %= 11;
  if (rs == r) {
    cout << "Right";
  } else {
    s.back() = rs == 10 ? 'X' : rs + '0';
    cout << s;
  }

  return 0;
}
