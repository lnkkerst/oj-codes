class Solution {
public:
  double findMedianSortedArrays(vector<int> nums1, vector<int> nums2) {
    for (auto i : nums2)
      nums1.emplace_back(i);
    sort(nums1.begin(), nums1.end());
    if (nums1.size() & 1) {
      return (double)nums1[nums1.size() / 2];
    }
    return (nums1[nums1.size() / 2] + nums1[nums1.size() / 2 - 1]) / 2.0;
  }
};