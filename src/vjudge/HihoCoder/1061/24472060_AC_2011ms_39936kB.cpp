#include <iostream>
#include <vector>
using namespace std;

vector<pair<char, int>> a;
int t, n;

int main() {
  cin >> t;
  while (t--) {
    cin >> n;
    a.clear();
    char last, ch;
    int num = 1;
    cin >> ch;
    last = ch;
    for (int i = 2; i <= n; ++i) {
      cin >> ch;
      if (ch == last)
        ++num;
      else {
        a.push_back(make_pair(last, num));
        last = ch;
        num = 1;
      }
    }
    if (num)
      a.push_back(make_pair(last, num));
    bool ans = 0;
    for (int i = 0; i < (int)a.size() - 2; ++i)
      if (a[i].second >= a[i + 1].second && a[i + 1].second <= a[i + 2].second)
        if (a[i].first == a[i + 1].first - 1 &&
            a[i].first == a[i + 2].first - 2)
          ans = 1;
    cout << (ans ? "YES\n" : "NO\n");
  }
  return 0;
}
