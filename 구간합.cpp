/*
#include <iostream>
using namespace std;
int s[100001] = {0};
void savesum(int *p,int N)
{
	for(int i=1;i<=N;i++)
		s[i] = s[i-1] + p[i];
}

void printsum(int *p,int init,int final)
{
	int sum = s[final] - s[init-1];
	printf("%d\n",sum);
}
int main()
{
	int N,T;
	int init,final;
	scanf("%d %d",&N, &T);
	int *p = new int[N+2];
	for(int i=1;i<=N;i++) scanf("%d",&p[i]);
	
	savesum(p,N);
	
	for(int i=0;i<T;i++){
		scanf("%d %d",&init,&final);
		printsum(p,init,final);
	}
	
	return 0;
}
*/
