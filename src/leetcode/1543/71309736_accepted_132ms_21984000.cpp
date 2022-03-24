class Solution {
public:
    int gcd(int x, int y) {
        return !y ? x : gcd(y, x % y);
    }
    vector<string> simplifiedFractions(int n) {
        vector<string> ret;
        for(int i = 1; i <= n; ++i) {
            for(int j = 1; j <= n; ++j) {
                if(i < j && gcd(i, j) == 1) {
                    ret.push_back(to_string(i) + '/' + to_string(j));
                }
            }
        }
        return ret;
    }
};