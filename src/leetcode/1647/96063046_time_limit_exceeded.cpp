class Solution {
public:
    bool canConvertString(string s, string t, int k) {
        if(s == t) return 1;
        if(s.size() != t.size()) return 0;
        vector<long long> a(s.size());
        unordered_map<long long, bool> b;
        long long ma = -1;
        for(int i = 0; i < s.size(); ++i) {
            a[i] = t[i] - s[i];
            while(a[i] < 0) a[i] += 26;
            if(!a[i]) continue;
            // cout << a[i] << endl;
            while(b[a[i]]) {
                a[i] += 26;
            }
            b[a[i]] = 1;
            ma = max(ma, a[i]);
            // cout << a[i] << endl;
        }
        // cout << b.rbegin()->first;
        return ma <= k;
    }
};