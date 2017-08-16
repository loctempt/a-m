#include <cstdio>
#include <cstring>
#include <iostream>
using namespace std;
void getNext(char* s,int* Next)
{	int m=strlen(s);
	Next[0]=0; Next[1]=0;
	for(int i=1;i<m;i++)
	{	int j=Next[i];
		while(j&&s[i]!=s[j]) j=Next[j];
		if(s[i]==s[j]) Next[i+1]=j+1;
		else Next[i+1]=0;
	}
	for(int i=0;i<m;i++) printf("%3c",s[i]); printf("\n"); 
	for(int i=0;i<=m;i++) printf("%3d",Next[i]); printf("\n");
}
void KMP0(char* ss,char* s,int* Next){
//请确保s[m]='\0'
	int n=strlen(ss),m=strlen(s);
	getNext(s,Next);
	int j=0,cnt=0;
	for(int i=0;i<n;i++){
		while(j&&s[j]!=ss[i]) j=Next[j]; 
		if(s[j]==ss[i]) j++;
		if(j==m) printf("appear%d: %d\n",++cnt,i-m+1);
	}
	if(!cnt) printf("not exist!\n");
}

void get_f(char s[],int f[]){
	int m=strlen(s+1);
	f[0]=-1;
	for(int i=1;i<=m;i++){
		int p=f[i-1];
		while(p+1&&s[p+1]!=s[i]) p=f[p];
		f[i]=p+1;
	}
	for(int i=0;i<=m;i++) printf("%3c",i?s[i]:'\0'); printf("\n"); 
	for(int i=0;i<=m;i++) printf("%3d",f[i]); printf("\n");
}
void KMP1(char ss[],char s[],int f[]){
//请确保s[m+1]='\0'
	int n=strlen(ss+1),m=strlen(s+1);
	get_f(s,f);
	int p=0,cnt=0;
	for(int i=1;i<=n;i++){
		while(p+1&&s[p+1]!=ss[i]) p=f[p];
		if(++p==m) printf("appear%d: %d\n",++cnt,i-m+1);
	}
	if(!cnt) printf("not exist!\n");
}
int main()
{
	void test();
	test();
	return 0;
}
/*
abaaabab
aaabaaababaaababaa
*/
void test(){
	char s[100],ss[1000];
	printf("s(1):"); scanf("%s",s+1);
	printf("ss(1):"); scanf("%s",ss+1);
	int f[100];
	KMP1(ss,s,f);

	printf("s:"); scanf("%s",s);
	printf("ss:"); scanf("%s",ss);
	int Next[100];
	KMP0(ss,s,Next);
}

