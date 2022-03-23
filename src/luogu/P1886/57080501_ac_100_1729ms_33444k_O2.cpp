#include <iostream>
#include <queue>
using namespace std;

int main() {
    int n, k;
    cin >> n >> k;
    vector<int> a;
    for(int i = 1; i <= n; ++i) {
        int x;
        cin >> x;
        a.emplace_back(x);
    }
    priority_queue<pair<int, int> > queMax;
    priority_queue<pair<int, int>, vector<pair<int, int> >, greater<pair<int, int> > > queMin;
    vector<int> ansMax, ansMin;
    for(int i = 0; i < k; ++i) {
        queMax.emplace(a[i], i);
        queMin.emplace(a[i], i);
    }
    ansMax.emplace_back(queMax.top().first);
    ansMin.emplace_back(queMin.top().first);
    for(int i = k; i < n; ++i) {
        queMax.emplace(a[i], i);
        queMin.emplace(a[i], i);
        while(queMax.top().second <= i - k) {
            queMax.pop();
        }
        while(queMin.top().second <= i - k) {
            queMin.pop();
        }
        ansMax.emplace_back(queMax.top().first);
        ansMin.emplace_back(queMin.top().first);
    }
    for(auto i : ansMin) {
        cout << i << ' ';
    }
    cout << endl;
    for(auto i : ansMax) {
        cout << i << ' ';
    }
    return 0;
}