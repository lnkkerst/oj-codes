class Solution {
public:
  string longestCommonPrefix(vector<string> &strs) {
    string ret;
    while (1) {
      for (int i = 1; i < strs.size(); ++i) {
        if (ret.length() > strs[0].length()) {
          return ret;
        }
        if (ret.length() > strs[i].length()
            || strs[i][ret.length()] != strs[i - 1][ret.length()]) {
          return ret;
        }
      }
      ret.push_back(strs[0][ret.length()]);
    }
  }
};
