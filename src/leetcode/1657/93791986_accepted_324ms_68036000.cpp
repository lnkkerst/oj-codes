class Solution {
public:
    int getWinner(vector<int>& arr, int k) {
        if(k >= arr.size()) return *max_element(arr.begin(), arr.end());
        deque<int> q(arr.begin(), arr.end());
        int now = 0, nown = q[0], cnt = 0;
        while(now < k) {
            if(q[1] > nown) {
                now = 1;
                nown = q[1];
                q.push_back(q[0]);
                q.pop_front();
            }
            else {
                ++now;
                q.push_back(q[1]);
                q[1] = q[0];
                q.pop_front();
            }
            if(cnt >= arr.size()) return *max_element(arr.begin(), arr.end());
            ++cnt;
        }
        return nown;
    }
};