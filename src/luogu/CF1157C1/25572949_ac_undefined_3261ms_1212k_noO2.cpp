#include <bits/stdc++.h>
using namespace std;

int n, ans;
deque<int> a;

int main() {
  cin >> n;
  for (int i = 1; i <= n; ++i) {
    int tmp;
    cin >> tmp;
    a.push_back(tmp);
  }
  string ans;
  int now = 0;
  while (!a.empty() && (a.front() >= now || a.back() >= now) &&
         (int)ans.size() != n) {
    if (a.front() > a.back()) {
      if (a.back() >= now) {
        now = a.back();
        a.pop_back();
        ans.push_back('R');
      } else if (a.front() >= now) {
        now = a.front();
        a.pop_front();
        ans.push_back('L');
      } else
        break;
    } else {
      if (a.front() >= now) {
        now = a.front();
        a.pop_front();
        ans.push_back('L');
      } else if (a.back() >= now) {
        now = a.back();
        a.pop_back();
        ans.push_back('R');
      } else
        break;
    }
  }
  cout << (int)ans.size() << endl << ans << endl;
  return 0;
}