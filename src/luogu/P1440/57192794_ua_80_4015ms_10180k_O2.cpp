#include <iostream>
#include <queue>
#include <vector>
using namespace std;

int main() {
    int n, m;
    cin >> n >> m;
    vector<int> a;
    for(int i = 1; i <= n; ++i) {
        int x;
        cin >> x;
        a.emplace_back(x);
    }
    deque<int> que;
    cout << 0 << endl;
    for(int i = 0; i < n - 1; ++i) {
        while(!que.empty() && a[que.back()] >= a[i]) {
            que.pop_back();
        }
        que.emplace_back(i);
        if(que.front() <= i - m) {
            que.pop_front();
        }
        cout << a[que.front()] << endl;
    }
    return 0;
}