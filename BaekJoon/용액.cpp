#include <iostream>
using namespace std;
void case1(int *p,int N);
void case2(int *p,int N);
void case3(int *p,int N);
int abs(int a)
{
	return a>0 ? a : -a;
}
int main()
{
	int N;
	cin>>N;
	int *p = new int[N+2];
	for(int i=1;i<=N;i++)	scanf("%d",&p[i]);
	if(p[1]<0 && p[N]<=0) case1(p,N);
	else if(p[1]<0 && p[N]>0) case2(p,N);
	else if(p[1]>=0 && p[N]>0) case3(p,N);
} 

void case1(int *p,int N)
{
	cout<<p[N]+p[N-1];
}

void case2(int *p,int N)
{
	int min,minmin=p[1]+p[N];
	for(int i=1;i<N;i++){
		min = p[i]+p[N];
		for(int j=N;j>i;j--){
			if(abs(min)<abs(p[i]+p[j]))	break;
			else min = p[i]+p[j];
		}
		if(abs(min)<abs(minmin)) minmin = min;
	}
	printf("%d",minmin);
}

void case3(int *p,int N)
{
	cout<<p[1]+p[2];
}
