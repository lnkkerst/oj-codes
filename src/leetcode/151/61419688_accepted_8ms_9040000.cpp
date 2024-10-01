class Solution {
public:
  string reverseWords(string s) {
    stringstream ss, out;
    vector<string> a;
    ss << s;
    while (ss >> s) {
      a.push_back(s);
    }
    bool fl = 0;
    string ret;
    for (auto i = a.rbegin(); i != a.rend(); ++i) {
      if (fl) {
        ret.push_back(' ');
      }
      ret += *i;
      fl = 1;
    }
    return ret;
  }
};
