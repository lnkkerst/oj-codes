int mid;

class Solution {
public:
  vector<int> getStrongest(vector<int> &arr, int k) {
    sort(arr.begin(), arr.end());
    // vector<int> ret;
    int n = arr.size();
    mid = arr[(n - 1) / 2];
    // cout << mid << endl;
    sort(arr.begin(), arr.end(), [](const int a, const int b) -> bool {
      if (abs(a - mid) == abs(b - mid))
        return a > b;
      return (abs(a - mid) > abs(b - mid));
    });
    return vector<int>(arr.begin(), arr.begin() + k);
  }
};