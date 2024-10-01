#include <iostream>
#include <string>
#include <vector>
using namespace std;

vector<string> a;
int p;

int main() {
  string inp;
  while (cin >> inp) {
    a.push_back(inp);
  }
  int n = (int)a.size();
  for (auto i : a) {
    if (i.length() != 3 && i.length() != 4) {
      continue;
    }
    bool fl = 0;
    for (int j = 1; j <= 26; ++j) {
      string dec;
      for (auto k : i) {
        if (isalpha(k)) {
          dec += (isalpha(k + j) ? k + j : k + j - 26);
        }
      }
      if (dec == "that" || dec == "this" || dec == "the") {
        p = j;
        fl = 1;
        break;
      }
    }
    if (fl) {
      break;
    }
  }
  for (auto i : a) {
    for (auto j : i) {
      if (isalpha(j)) {
        cout << (char)(isalpha(p + j) ? p + j : p + j - 26);
      } else {
        cout << j;
      }
    }
    cout << ' ';
  }
  return 0;
}
