class Solution {
public:
  string rev(string s) {
    for (auto &i : s) {
      if (i == '0')
        i = '1';
      else
        i = '0';
    }
    return s;
  }
  char findKthBit(int n, int k) {
    string s = "0";
    for (int i = 1; i < n; ++i) {
      s = s + "1" + rev(s);
      // cout << s << endl;
    }
    return s[k - 1];
  }
};