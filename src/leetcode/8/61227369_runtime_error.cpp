class Solution {
public:
  int myAtoi(string str) {
    int ret = 0, fl = 1, f = 1;
    for (auto i : str) {
      if (i < '0' || i > '9') {
        if (i == '-') {
          fl = -1;
        } else if (i != ' ' && f) {
          return 0;
        }
      } else {
        ret *= 10, ret += i - '0', f = 0;
      }
    }
    return ret * fl;
  }
};
