#include<cstdio>
using namespace std;
int main(){
	int n,a[1001]={6,2,5,5,4,5,6,3,7,6},s=0;
	for (int i=10;i<1001;i++)
		a[i]=a[i%10]+a[i/10];
	scanf("%d",&n);
	n=n-4;
	for (int i=0;i<1001;i++)
		for (int j=0;j<1001;j++)
			if (a[i]+a[j]+a[i+j]==n) s++;
	printf("%d",s);
}