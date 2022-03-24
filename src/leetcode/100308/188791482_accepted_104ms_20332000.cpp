class Solution {
public:
    vector<string> permutation(string s) {
        vector<int> a((int)s.size());
        for(int i = 0; i < (int)s.size(); ++i) a[i] = i;
        unordered_set<string> res;
        do {
            string t;
            for(auto i : a) {
                t.push_back(s[i]);
            }
            res.insert(t);
        } while(next_permutation(a.begin(), a.end()));
        return vector<string> {res.begin(), res.end()};
    }
};