class Solution {
public:
    int findKthPositive(vector<int>& arr, int k) {
        unordered_set<int> b(arr.begin(), arr.end());
        for(int i = 1, j = 0; i <= 100000; ++i) {
            if(b.find(i) == b.end()) ++j;
            if(j == k) return i;
        }
        return -1;
    }
};