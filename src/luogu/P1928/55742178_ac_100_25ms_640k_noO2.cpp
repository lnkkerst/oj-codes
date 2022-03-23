#include <iostream>
#include <cctype>
using namespace std;

int main() {
    string s, tmp;
    cin >> s;
    for(int r = 1; r <= 10; ++r) {
        for (int i = 0; i < (int) s.size(); ++i) {
            if (s[i] != '[') {
                tmp.push_back(s[i]);
                //            cout << tmp <<endl;
                continue;
            }
            int cnt = 1, num = s[i + 1] - '0', l = i + 2;
            for(int j = i + 2; isdigit(s[j]); ++j) {
                num *= 10;
                num += s[j] - '0';
                ++l;
            }
            int j;
            for (j = i + 1; cnt; ++j) {
                if (s[j] == '[') {
                    ++cnt;
                }
                if (s[j] == ']') {
                    --cnt;
                }
            }
            for (int k = 1; k <= num; ++k) {
                tmp += s.substr(l, j - l - 1);
            }
            i = j - 1;
            //        cout << tmp << endl;
        }
        s = tmp;
        tmp.clear();
    }
    cout << s;
    return 0;
}