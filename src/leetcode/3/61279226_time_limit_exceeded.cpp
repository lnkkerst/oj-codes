class Solution {
public:
    bool pd(string s) {
        unordered_map<char, bool> b;
        for(auto i : s) {
            if(b[i]) return 0;
            b[i] = 1;
        }
        return 1;
    }
    int lengthOfLongestSubstring(string s) {
        int ans = 0;
        for(int i = 0; i < (int)s.length(); ++i) {
            for(int j = ans + 1; i + j <= (int)s.length(); ++j) {
                string t = s.substr(i, j);
                if(pd(t)) ans = max(ans, (int)t.length());
            }
        }
        return ans;
    }
};