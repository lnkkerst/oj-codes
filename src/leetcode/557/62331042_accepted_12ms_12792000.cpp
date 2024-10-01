class Solution {
public:
  string reverseWords(string s) {
    stringstream ss;
    ss << s;
    string ret;
    bool fl = 0;
    while (ss >> s) {
      if (fl) {
        ret.push_back(' ');
      }
      fl = 1;
      reverse(s.begin(), s.end());
      ret += s;
    }
    return ret;
  }
};
