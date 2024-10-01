class Solution {
public:
  string makeGood(string s) {
    string ret;
    for (int i = 0; i < s.size(); ++i) {
      while (i < s.size() && ret.size()
             && (ret.back() == s[i] + 32 || ret.back() == s[i] - 32)) {
        ++i, ret.pop_back();
      }
      if (i < s.size()) {
        ret += s[i];
      }
      // cout << ret.size() << endl;
    }
    // cout << ret.size();
    return ret;
  }
};
