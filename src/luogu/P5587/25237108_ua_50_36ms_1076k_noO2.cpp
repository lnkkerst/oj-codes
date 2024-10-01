#include <bits/stdc++.h>
using namespace std;

vector<string> a, b;
int t, ans;

string read() {
  string ret;
  char ch;
  while (ch = getchar(), ch != '\n') {
    if (ch == '<' && ret.size()) {
      ret.erase(ret.end() - 1);
    } else {
      ret.push_back(ch);
    }
  }
  return ret;
}

int main() {
  for (string s = read(); s != "EOF"; a.push_back(s), s = read())
    ;
  for (string s = read(); s != "EOF"; b.push_back(s), s = read())
    ;
  int minl = min((int)a.size(), (int)b.size());
  for (int i = 0; i < minl; ++i) {
    int mins = min((int)a[i].size(), (int)b[i].size());
    for (int j = 0; j < mins; ++j) {
      ans += a[i][j] == b[i][j];
    }
  }
  cin >> t;
  cout << (int)(ans * 60 / (double)t) << endl;
  return 0;
}
