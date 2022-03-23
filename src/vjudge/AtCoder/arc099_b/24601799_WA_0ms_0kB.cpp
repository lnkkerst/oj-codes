#include <iostream>
#include <vector>
using namespace std;

vector<string > ans;
string base;

int main() {
    for(int i = 1; i <= 15; ++i) {
        for(int j = 1; j <= 9; ++j)
            ans.push_back(base + to_string(j));
        base += '9';
    }
    int k;
    cin >> k;
    int cnt = 0;
    for(auto i : ans) {
        for(auto j = i.rbegin(); j != i.rend(); ++j)
            cout << *j;
        cout << endl;
        if(++cnt == k) break;
    }
    return 0;
}