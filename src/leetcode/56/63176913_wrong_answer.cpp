class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& a) {
        if(!a.size()) return a;
        vector<vector<int> > ret;
        int nl = a[0][0], nr = a[0][1];
        for(int i = 1; i < (int)a.size(); ++i) {
            if(a[i][0] <= nr) nr = a[i][1];
            else {
                ret.push_back({nl, nr});
                nl = a[i][0];
                nr = a[i][1];
            }
        }
        ret.push_back({nl, nr});
        return ret;
    }
};