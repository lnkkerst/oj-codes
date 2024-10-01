#include <iostream>
using namespace std;

string wd[10001];
int n, m;
string str;

int main() {
  ios::sync_with_stdio(0);
  cin.tie(NULL);
  cout.tie(NULL);
  int t;
  cin >> t;
  for (int k = 1; k <= t; ++k) {
    cout << "Case #" << k << ":\n";
    cin >> n;
    for (int i = 1; i <= n; ++i) {
      cin >> wd[i];
    }
    cin >> str;
    cin >> m;
    while (m--) {
      char opt;
      cin >> opt;
      if (opt == 'Q') {
        int l, r;
        cin >> l >> r;
        string tmp = str.substr(l, r - l + 1);
        bool fl = 0;
        for (int i = 1; i <= n; ++i) {
          if (wd[i] == tmp) {
            fl = 1;
            break;
          }
        }
        if (fl) {
          cout << "Yes\n";
        } else {
          cout << "No\n";
        }
      } else {
        int x;
        char ch;
        cin >> x >> ch;
        str[x] = ch;
      }
    }
  }
  return 0;
}
