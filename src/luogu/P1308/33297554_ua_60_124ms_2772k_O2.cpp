#include <cctype>
#include <iostream>
#include <string>
#include <unordered_map>
using std::cin;
using std::cout;
using std::string;
using std::unordered_map;

void cvt(string &s) {
  for (size_t i = 0; i < s.size(); ++i) {
    s[i] = tolower(s[i]);
  }
}

int strMatch(const char ori[], const char str[], int pos[],
             int *tot) { // 文本串、模式串、保存出现下标的数组、出现的次数
  int l1 = 0, l2 = 0, j = 0, ret = 0;
  while (ori[l1]) {
    ++l1;
  }
  while (str[l2]) {
    ++l2;
  }
  if (l2 > l1) {
    if (tot != NULL) {
      *tot = 0;
    }
    return 0;
  }
  int *nex = (int *)malloc(sizeof(int) * l2);
  nex[0] = nex[1] = 0;
  for (int i = 1; i < l2; ++i) {
    while (j && str[i] != str[j]) {
      j = nex[j];
    }
    nex[i + 1] = str[i] == str[j] ? ++j : 0;
  }
  j = 0;
  for (int i = 0; i < l1; ++i) {
    while (j && str[j] != ori[i]) {
      j = nex[j];
    }
    j += ori[i] == str[j];
    if (j == l2) {
      if (pos) {
        pos[ret++] = i - l2 + 1;
      } else {
        ++ret;
      }
      j = nex[j];
    }
  }
  if (tot != NULL) {
    *tot = ret;
  }
  free(nex);
  return ret;
}

int main() {
  string wd, ltr;
  cin >> wd;
  getline(cin, ltr);
  getline(cin, ltr);
  cvt(wd), cvt(ltr);
  wd.push_back(' ');
  ltr.push_back(' ');
  // cout << wd << '\n' << ltr;
  int ans = strMatch(ltr.c_str(), wd.c_str(), NULL, NULL);
  // cout << ans << '\n';
  if (!ans) {
    puts("-1");
    return 0;
  }
  cout << ans << ' ' << ltr.find(wd) << '\n';
  return 0;
}
