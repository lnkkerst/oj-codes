#include <cstdio>
#include <cctype>
#include <algorithm>
#include <iostream>
#include <map>
#include <vector>
#include <set>
#include <queue>
using namespace std;

int n;
map<int , int > b;

int main() {
    cin >> n;
    while(n--) {
        string opt;
        int x;
        cin >> opt >> x;
        if(opt == "add") (b[x] == -1) && (b[x] = 0), cout << ++b[x] << endl;
        else if(opt == "del") cout << b[x] << endl, b[x] = -1;
        else cout << (b[x] ? 1 : 0) << ' ' << (b[x] == -1 ? 0 : b[x]) << endl;
    }
    return 0;
}