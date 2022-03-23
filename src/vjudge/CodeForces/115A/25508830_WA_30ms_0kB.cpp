//
// Created by lnkkerst on 2020/4/27/027.
//

#include <iostream>
#include <algorithm>
#include <vector>
#include <unordered_set>
using namespace std;

int find(vector<int> &a, int x) {
    return x == a[x] ? x : a[x] = find(a, a[x]);
}

int main() {
    int n;
    cin >> n;
    vector<int> f(n + 1);
    for(int i = 0; i <= n; ++i) {
        f[i] = i;
    }
    for(int i = 1; i <= n; ++i) {
        int x;
        cin >> x;
        if(x != -1) {
            f[find(f, i)] = find(f, x);
        }
    }
    unordered_set<int> b;
    for(int i = 1; i <= n; ++i) {
        cout << f[i] << endl;
        b.insert(f[i]);
    }
    cout << b.size() + 1 << endl;
    return 0;
}