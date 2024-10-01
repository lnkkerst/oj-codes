#include <algorithm>
#include <iostream>
#define int long long
using namespace std;

char cvt(unsigned ori) {
  if (ori <= 9) {
    return ori + '0';
  }
  return ori - 10 + 'A';
}

string toStr(int x, int b) {
  string s;
  while (x) {
    s.push_back(cvt(x % b));
    x /= b;
  }
  return s;
}

// bool pd(int xx, int b) {
// 	int x = xx * xx;
// 	string s;
// 	while(x) {
// 		s.push_back(cvt(x % b));
// 		x /= b;
// 	}
// 	string re = s;
// 	reverse(re.begin(), re.end());
// 	if(re == s) cout <<
// }

signed main() {
  int b;
  cin >> b;
  for (int i = 1; i <= 300; ++i) {
    string s = toStr(i * i, b), ss = toStr(i, b);
    string re = s, res = ss;
    reverse(re.begin(), re.end());
    reverse(res.begin(), res.end());
    if (re == s) {
      cout << res << ' ' << s << endl;
    }
  }
  return 0;
}
