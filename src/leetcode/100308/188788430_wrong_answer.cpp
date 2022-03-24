class Solution {
public:
    vector<string> permutation(string s) {
        vector<string> res;
        do {
            res.emplace_back(s);
        } while(next_permutation(s.begin(), s.end()));
        return res;
    }
};