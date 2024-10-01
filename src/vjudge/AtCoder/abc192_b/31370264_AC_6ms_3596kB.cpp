#include <iostream>
using namespace std;

int main() {
  string s;
  cin >> s;
  for (int i = 0; i < (int)s.size(); ++i) {
    if ((i & 1) && islower(s[i])) {
      cout << "No";
      return 0;
    }
    if (!(i & 1) && isupper(s[i])) {
      cout << "No";
      return 0;
    }
  }
  cout << "Yes";
  return 0;
}
