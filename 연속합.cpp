/*
#include <iostream>
using namespace std;
int max(int a,int b)
{
	return a>b ? a : b;
}
int main()
{
	int N,j=0;
	cin>>N;
	int p[100001];
	int dp[100001];
	for(int i=1;i<=N;i++) scanf("%d",&p[i]);
	dp[1] = p[1];
	for(int i=1;i<=N;i++){
		dp[i] = max(dp[i-1]+p[i],p[i]);
	}
	int max = dp[1];
	for(int i=1;i<=N;i++){
		if(max<dp[i]) max = dp[i];
	}
	cout<<max;
}
*/
