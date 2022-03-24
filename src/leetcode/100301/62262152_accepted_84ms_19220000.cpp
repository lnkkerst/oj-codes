class Solution {
public:
    vector<int> getLeastNumbers(vector<int>& arr, int k) {
        stable_sort(arr.begin(), arr.end());
        return vector<int>{arr.begin(), arr.begin() + k};
    }
};