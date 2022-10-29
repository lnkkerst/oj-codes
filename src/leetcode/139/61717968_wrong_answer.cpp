bool cmp(const string &a, const string &b) { return a.length() > b.length(); }
class Solution {
public:
  bool wordBreak(string s, vector<string> wordDict) {
    sort(wordDict.begin(), wordDict.end(), cmp);
    for (auto i : wordDict) {
      int pos = s.find(i);
      while (pos != string::npos) {
        s.erase(pos, i.length());
        pos = s.find(i);
      }
    }
    return !s.length();
  }
};