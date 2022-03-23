#include<iostream>
#include<cmath>
using namespace std;
int a[200200],t=0;
void opt1(){
	int n,m;
	cin>>n>>m;
	for (int i=1;i<=n;i++){
		t++;a[t]=m;
	}
}
void opt2(){
	int n;
	cin>>n;
	for (int i=1;i<=t;i++) a[i]=a[i+n];
	t=t-n;
}
void opt3(){
	int l,r,x,c,m;
	cin>>l>>r>>x>>m;
	m=pow((r-l+1),x);
	m=m%c;
	for (int i=l;i<=r;i++) a[i]=m;
}
void opt4(){
	int l,r,max=0;
	cin>>l>>r;
	for (int i=l;i<=r;i++) if (a[i]>max) max=a[i];
	a[l]=max;
	for (int i=l+1;i<=t;i++) a[i]=a[i+r-l];
	t=t-r+l;
	cout<<max<<endl;
}
void opt5(){
	int l,r;
	cin>>l>>r;
	for (int i=l;i<=r;i++) a[i]=sqrt(a[i]);
}
int main(){
	int m,n;
	cin>>m;
	for (int i=1;i<=m;i++){
		cin>>n;
		if (n==1) opt1();
		if (n==2) opt2();
		if (n==3) opt3();
		if (n==4) opt4();
		if (n==5) opt5();
	}
	for (int i=1;i<=t;i++) cout<<a[i]<<" ";
	return 0;
}