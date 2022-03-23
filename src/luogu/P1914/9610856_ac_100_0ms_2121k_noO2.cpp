#include<iostream>
using namespace std;
int main(){
	int n;
	string a;
	cin>>n>>a;
	for (int i=0;i<a.length();i++){
		if (a[i]+n<=122) a[i]=a[i]+n;
		else a[i]=a[i]+n-26;
	}
	for (int i=0;i<a.length();i++) cout<<a[i];
	return 0;
}