#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>
using namespace std;

int main() {
    while(233) {
        int n;
        cin >> n;
        if(!n) return 0;
        vector<pair<int , int > > a;
        for(int i = 1; i <= n; ++i) {
            int x;
            cin >> x;
            a.push_back(make_pair(abs(x), x));
        }
        sort(a.begin(), a.end(), greater<pair<int, int > >());
        for(auto i = a.begin(); i != a.end(); ++i) {
            cout << i->second;
            if(i == a.end() - 1) continue;
            cout << ' ';
        }
        cout << endl;
    }
    return 0;
} 