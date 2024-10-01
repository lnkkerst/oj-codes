class Solution {
public:
  bool isValid(string s) {
    int cnt = 0;
    for (auto i : s) {
      if (i == '(' || i == '[' || i == '{') {
        ++cnt;
      } else {
        --cnt;
      }
      if (cnt < 0) {
        return 0;
      }
    }
    return !cnt;
  }
};
