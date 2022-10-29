class Solution {
public:
  bool isdigit(char ch) { return (ch <= '9' && ch >= '0'); }
  int myAtoi(string str) {
#define int long long
    int pos = 0;
    while (pos < (int)str.length() && str[pos] == ' ')
      ++pos;
    if (pos == (int)str.length())
      return 0;
    int op = 1;

    if (str[pos] == '-')
      op = -1, ++pos;
    else if (str[pos] == '+')
      op = 1, ++pos;
    if (!isdigit(str[pos]))
      return 0;
    int ret = 0;
    while (pos < (int)str.length() && isdigit(str[pos])) {
      if (ret * 10ll * op > INT_MAX)
        return INT_MAX;
      else if (ret * 10ll * op < INT_MIN)
        return INT_MIN;
      else
        ret *= 10, ret += str[pos] - '0';
      ++pos;
    }
    ret *= op;
    if (ret > INT_MAX)
      return INT_MAX;
    if (ret < INT_MIN)
      return INT_MIN;
    return (int)ret;
#undef int
  }
};