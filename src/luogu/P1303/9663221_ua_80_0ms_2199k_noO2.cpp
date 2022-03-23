#include<iostream>
using namespace std;
int la,lb,lc,a[1010],b[1010],c[1010];
string s1,s2;
int main(){
	cin>>s1>>s2;
	la = s1.length();
	lb = s2.length();
	for (int i=0; i<la; i++) a[i]=s1[la-i-1]-48;
	for (int i=0; i<lb; i++) b[i]=s2[lb-i-1]-48;
	for (int i=0; i<la; i++)
          for (int j=0; j<lb; j++){        
	      c[i+j] += a[i] * b[j] ;
	      c[i+j+1] += c[i+j] / 10;
	      c[i+j] = c[i+j] % 10;
	     }
	lc = la + lb;
    while (lc>=1 && c[lc]==0) lc--;
    for (int i=lc; i>=0; i--) cout<<c[i];
    cout<<endl;
    return 0;
}