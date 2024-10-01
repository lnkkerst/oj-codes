#include <iostream>
#include <vector>
using namespace std;

string inp;
vector<string> a;
int pswd = -1;

int main() {
  while (cin >> inp) {
    a.push_back(inp);
    if (pswd == -1) {
      for (int i = 0; i <= 26; ++i) {
        inp = a.back();
        if (!isalpha(inp[inp.length() - 1])) {
          a.pop_back();
        }
        for (int j = 0; j < (int)inp.size(); ++j) {
          if (isalpha(inp[j])) {
            inp[j] = isalpha(inp[j] + i) ? inp[j] + i : inp[j] + i - 26;
          }
        }
        if (inp == "that" || inp == "the" || inp == "this") {
          pswd = i;
        }
        if (pswd != -1) {
          break;
        }
      }
    }
  }
  for (auto i : a) {
    for (auto j : i) {
      if (isalpha(j)) {
        cout << (char)(isalpha(j + pswd) ? j + pswd : j + pswd - 26);
      } else {
        cout << j;
      }
    }
    putchar(' ');
  }
  return 0;
}
