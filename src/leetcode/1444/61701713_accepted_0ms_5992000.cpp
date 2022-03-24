class Solution {
public:
    int numberOfSteps (int num) {
        int ret = 0;
        while(num) num = num & 1 ? num - 1 : num >> 1, ++ret;
        return ret;
    }
};