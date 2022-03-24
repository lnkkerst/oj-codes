class Solution {
public:
    int maxPower(string s) {
        int pos = 0;
        int ans = 0;
        while(pos < (int)s.length()) {
            int nex = pos;
            while(nex < (int)s.length() && s[nex] == s[pos]) ++nex;
            ans = max(ans, nex - pos);
            pos = nex;
        }
        return ans;
    }
};