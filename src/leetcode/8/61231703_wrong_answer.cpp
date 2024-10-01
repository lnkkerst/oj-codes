class Solution {
public:
  bool isdigit(char ch) {
    return (ch <= '9' && ch >= '0');
  }
  int myAtoi(string str) {
#define int long long
    int pos = 0, ret = 0, fl = 1;
    char ch;
    while (pos < (int)str.length() && !isdigit(ch = str[pos++])) {
      if (ch == '-') {
        (fl = -1);
      } else if (ch != ' ') {
        return 0;
      }
    }
    for (ret = ch - '0'; pos < (int)str.length() && isdigit(ch = str[pos++]);
         ret *= 10, ret += ch - '0')
      ;
    ret *= fl;
    if (ret > INT_MAX) {
      return INT_MAX;
    }
    if (ret < INT_MIN) {
      return INT_MIN;
    }
    return (int)ret;
#undef int
  }
};
