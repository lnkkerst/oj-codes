#include <cctype>
#include <iostream>
#include <sstream>
#include <string>
#include <unordered_map>
#include <vector>
using namespace std;

int main(int argc, char *argv[]) {
  string s;
  cin >> s;
  unordered_map<char, bool> b;
  for (int i = 0; i < s.size(); ++i) {
    if (isalpha(s[i])) {
      b[s[i]] = false;
    }
    if (s[i] == ':') {
      b[s[i - 1]] = true;
    }
  }
  int n;
  cin >> n;
  getchar();
  for (int i = 1; i <= n; ++i) {
    unordered_map<char, string> com;
    getline(cin, s);
    stringstream ss(s);
    ss >> s;
    while (ss >> s) {
      if (s.size() == 2 && s[0] == '-') {
        if (b.find(s[1]) == b.end()) {
          break;
        }
        if (b[s[1]]) {
          string s2;
          if (ss >> s2) {
            com[s[1]] = s2;

          } else {
            break;
          }
        } else {
          com[s[1]] = "";
        }
      } else {
        break;
      }
    }
    cout << "Case " + to_string(i) + ": ";
    for (char j = 'a'; j <= 'z'; ++j) {
      if (com.find(j) != com.end()) {
        cout << '-' << j << ' ';
        if (com[j].size()) {
          cout << com[j] << ' ';
        }
      }
    }
    cout << endl;
  }

  return 0;
}
