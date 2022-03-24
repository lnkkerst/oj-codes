class Solution {
public:
    int calc(const vector<int> &a, int k) {
        unordered_map<int, int> b;
        int sm = 0, ret = 0;
        for(int i = 0; i < a.size(); ++i) {
            sm += a[i];
            if(sm == k) ret = max(ret, i + 1);
            if(b.find(sm - k) != b.end())
                ret = max(ret, i - b[sm - k]);
            if(b.find(sm) == b.end())
                b[sm] = i;
        }
        return ret;
    }
    int longestAwesome(string s) {
        vector<int> a(s.begin(), s.end());
        for(auto &i : a) i -= '0' - 1;
        bool bb[11] = {0};
        for(auto &i : a) {
            int t = 1;
            if(bb[i]) bb[i] = 0, t = -1;
            else bb[i] = 1;
            i = (1 << i) * t;
        }
        cout << endl;
        int ans = 0;
        for(int i = 1; i <= 10; ++i) {
            int k = 1 << i;
            for(int j = 1; j <= 2; ++j) {
                ans = max(ans, calc(a, k));
                k *= -1;
            }
        }
        ans = max(ans, calc(a, 0));
        return ans;
    }
};