#include <iostream>
#include <vector>
#include <map>
#include <set>
#include <string>
#include <ext/hash_set>
#include <ext/hash_map>
using namespace std;
using namespace __gnu_cxx;

namespace __gnu_cxx {
    template< > struct hash<const string > {
        size_t operator()(const string &s) const {
            return hash<const char* >()(s.c_str());
        }
    };
    template< > struct hash<string > {
        size_t operator()(const string &s) const {
            return hash<const char* >()(s.c_str());
        }
    };
}

int n, t, m;
vector<string > wd;
string str;
hash_set<string > b;
hash_map<int, int > l1, l2;
vector<pair<char, pair<int, int > > > q;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> t;
    for(int k = 1; k <= t; ++k) {
        printf("Case #%d:\n", k);
        cin >> n;
        for(int i = 1; i <= n; ++i) {
            string inp;
            cin >> inp;
            if(inp.size() <= 100000)
                wd.push_back(inp);
        }
        cin >> str >> m;
        for(int i = 1; i <= m; ++i) {
            char opt;
            cin >> opt;
            if(opt == 'C') {
                int pos;
                char ch;
                cin >> pos >> ch;
                q.push_back(make_pair(opt, make_pair(pos, (int)ch)));
            }
            else {
                int l, r;
                cin >> l >> r;
                q.push_back(make_pair(opt, make_pair(l, r)));
                l1[r - l + 1] = 1;
            }
        }
        for(vector<string >::iterator i = wd.begin(); i != wd.end(); ++i)
            if(l1[(int)i->size()]) {
                b.insert(*i);
                l2[(int)i->size()] = 1;
            }
        for(vector<pair<char, pair<int, int > > >::iterator i = q.begin(); i != q.end(); ++i) {
            if(i->first == 'C') str[i->second.first] = i->second.second;
            else {
                if(!l2[i->second.second - i->second.first + 1]) cout << "No" << endl;
                else cout << (b.find(str.substr(i->second.first, i->second.second - i->second.first + 1)) != b.end() ? "Yes" : "No") << endl;
            }
        }
        wd.clear();
        l1.clear();
        l2.clear();
        b.clear();
        q.clear();
    }
    return 0;
}