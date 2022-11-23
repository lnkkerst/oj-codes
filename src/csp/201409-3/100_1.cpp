#include <cctype>
#include <iostream>
using namespace std;

int main(int argc, char *argv[]) {
  string str;
  cin >> str;
  int fl;
  cin >> fl;
  if (!fl) {
    for (auto &i : str) {
      i = tolower(i);
    }
  }
  int n;
  cin >> n;
  for (int i = 1; i <= n; ++i) {
    string s;
    cin >> s;
    string ba = s;
    if (!fl) {
      for (auto &i : s) {
        i = tolower(i);
      }
    }
    if (s.find(str) != -1) {
      cout << ba << endl;
    }
  }
  return 0;
}
