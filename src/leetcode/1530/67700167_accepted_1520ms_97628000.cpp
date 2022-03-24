class Solution {
public:
    bool pdf(string s1, string s2) {
        set<long long> b;
        for(int i = 0; i < (int)s1.size(); ++i) b.insert((s1[i] << 20) + i);
        for(auto &i : s2) {
            // cout << i << ' ' << b.size() << endl;
            auto t = b.lower_bound(i << 20);
            if(t == b.end()) return false;
            else b.erase(t);
        }
        return true;
    }
    bool checkIfCanBreak(string s1, string s2) {
        return pdf(s1, s2) || pdf(s2, s1);
    }
};