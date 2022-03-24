class Solution {
public:
    int subtractProductAndSum(int n) {
        auto s = to_string(n);
        int su = 0, mu = 1;
        for(auto i : s) su += i - '0', mu *= i - '0';
        return mu - su;
    }
};