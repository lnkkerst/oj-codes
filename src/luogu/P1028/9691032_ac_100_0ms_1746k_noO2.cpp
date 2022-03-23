#include<cstdio>
using namespace std;
int main(){
	int n[1001],x;
	scanf("%d",&x);
	n[0]=1;n[1]=1;
	for (int i=2;i<=x;i++)
		if (i%2!=0) n[i]=n[i-1];
		else n[i]=n[i-1]+n[i/2];
	printf("%d",n[x]);
	return 0;
}