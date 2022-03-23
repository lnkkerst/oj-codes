#include <iostream>
#include <algorithm>
#include <cctype>
using namespace std;

int main() {
    string str, ans;
    cin >> str;
    for(auto i : str)
        if(isalpha(i))
            ans += i;
    sort(ans.begin(), ans.end());
    cout << ans;
    return 0;
}