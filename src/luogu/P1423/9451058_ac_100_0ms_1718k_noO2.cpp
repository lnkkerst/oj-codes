#include<cstdio>
using namespace std;
int main(){
	float n=2,x,a=0;
	int s=0;
	scanf("%f",&x);
	if (x<=2){
		printf("1");
		return 0;
	}
	while (a<x){
		a=a+n;
		n=n*0.98;
		s++;
	}
	printf("%d",s);
	return 0;
}