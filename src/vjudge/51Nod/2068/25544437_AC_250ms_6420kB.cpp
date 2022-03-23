#include <iostream>
#include <deque>
using namespace std;

int main() {
    int n;
    cin >> n;
    deque<int> a;
    for(int i = 1; i <= n; ++i) a.push_back(i);
    while(!a.empty()) {
        cout << a.front() << ' ';
        a.pop_front();
        a.push_back(a.front());
        a.pop_front();
    }
    return 0;
}