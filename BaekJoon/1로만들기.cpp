/*
#include <iostream>
using namespace std;
int dp[1000000];
int min3(int a,int b,int c);
int main()
{
	int N,count=0;
	cin>>N;
	dp[1] = 0;
	dp[2] = 1;
	dp[3] = 1;
	for(int i=4;i<=N;i++){
		if(i%3==0 && i%2!=0) dp[i] = min(dp[i/3],dp[i-1]) + 1;
		else if(i%3!=0 && i%2==0) dp[i] = min(dp[i/2],dp[i-1]) + 1;
		else if(i%3!=0 && i%2!=0) dp[i] = dp[i-1] + 1;
		else dp[i] = min3(dp[i/3],dp[i/2],dp[i-1]) + 1; 
	}
	
	cout<<dp[N];
}

int min3(int a,int b,int c)
{
	int minnum = 0;
	minnum = min(a,b);
	minnum = min(minnum,c);
	return minnum;
}
*/
