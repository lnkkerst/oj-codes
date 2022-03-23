#include <bits/stdc++.h>
using namespace std;

int n, a[10000], b[10000], c[10000];

string sum(string x, string y) {
    int la = x.length(), lb = y.length();
    for(int i = 0; i < la; ++i) a[la - i - 1] = x[i] - '0'; 
    for(int i = 0; i < lb; ++i) b[lb - i - 1] = y[i] - '0';
    memset(c, 0, sizeof(c));
    int lmax = max(la, lb);
    for(int i = 0; i < lmax; ++i) c[i] += (a[i] + b[i]) % 10, c[i + 1] += (a[i] + b[i]) / 10;
    ++lmax;
    while(!c[lmax]) --lmax;
    string ret;
    for(int i = lmax; i >= 0; --i) ret.push_back(c[i] + '0');
    return ret;
}

string mul(string x, string y) {
	int la = x.length(), lb = y.length();
	    for(int i = 0; i < la; ++i) a[la - i - 1] = x[i] - '0'; 
    for(int i = 0; i < lb; ++i) b[lb - i - 1] = y[i] - '0';
    memset(c, 0, sizeof(c));
    
    for(int i = 0; i < la; ++i)
    	for(int j = 0; j < lb; ++j)
    		c[i + j] += a[i] * b[j];
    for(int i = 0; i < la + lb; ++i) c[i + 1] += c[i] / 10, c[i] %= 10;
    int lsum = la + lb;
    while(!c[lsum]) --lsum;
    string ret;
    for(int i = lsum; i >= 0; --i) ret.push_back(c[i] + '0');
    return ret;
}

string tostring(int x) {
	string ret;
	int dx[20], i;
	for(i = 1; x; ++i) dx[i] = x % 10, x /= 10;
	for(--i; i >= 1; --i) ret.push_back(dx[i] + '0');
	return ret;
} 

int main() {
	cin >> n;
	string jc = tostring(1), ans = tostring(1);
	for(int i = 2; i <= n; ++i) {
		jc = mul(jc, tostring(i));
		ans = sum(ans, jc);
	}
	cout << ans;
	return 0;
}