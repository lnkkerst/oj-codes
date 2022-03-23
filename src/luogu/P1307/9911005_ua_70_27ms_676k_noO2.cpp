#include<cstdio>
#include<cstring>
using namespace std;
int main(){
    char s1[12],s2[12];
    scanf("%s",s1);
    int l=strlen(s1),i,j;
    if (s1[0]=='-'){
        printf("-");
        for (i=0;i<l-1;i++) s1[i]=s1[i+1];
        l--;
    }
    for (i=l-1,j=0;i>=0;i--,j++) s2[i]=s1[j];
    for (int i=0;i<l;i++)
        if (s2[i]!='0') printf("%c",s2[i]);
    return 0;
}