#include<iostream>
using namespace std;
int zh(string a){
	int l,s=1;
	l=a.length();
	for (int i=0;i<l;i++) s*=(int)a[i]-64;
	return s%47;
}
int main(){
	string dw,hx;
	cin>>hx>>dw;
	if (zh(dw)==zh(hx)) cout<<"GO";
	else cout<<"STAY";
	return 0;
}