#include <iostream>
using namespace std;

int main() {
  string s;
  while (getline(cin, s)) {
    while (s.find("this") == s.npos && s.find("that") == s.npos
           && s.find("the") == s.npos) {
      for (auto &i : s) {
        if (!islower(i)) {
          continue;
        }
        if (i != 'z') {
          ++i;
        } else {
          i = 'a';
        }
      }
    }
    cout << s << endl;
  }
}
