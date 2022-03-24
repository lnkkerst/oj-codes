
class Solution {
public:
    bool pd(const string &s) {
        for(int i = 0, j = s.size() - 1; i < j; ++i, --j) {
            if(s[i] != s[j]) return 0;
        }
        return 1;
    }
    vector<vector<int>> palindromePairs(vector<string>& words) {
        vector<vector<int> > ret;
        for(int i = 0; i < words.size(); ++i) {
            for(int j = i + 1; j < words.size(); ++j) {
                if(i == j) continue;
                // auto t = words[i] = words[j];
                if(pd(words[i] + words[j])) {
                    ret.push_back({i, j});
                }
                if(pd(words[j] + words[i])) {
                    ret.push_back({j, i});
                }
            }
        }
        return ret;
    }
};