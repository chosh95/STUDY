/*
#include<iostream>
using namespace std;
int p[10002];
int dp[10002][3];

int max(int a,int b){
	if(a>=b) return a;
	else return b;
}

int main()
{
	int N;
	cin>>N;
	for(int i = 1; i<=N;i++)	cin>>p[i];
	dp[1][0] = 0;
	dp[1][1] = p[1];
	dp[2][0] = p[1];
	dp[2][1] = p[2];
	dp[2][2] = p[1]+p[2];
	if(N<=2) cout<<dp[2][2];
	else{
		for(int i=3;i<=N;i++){
			dp[i][0] = max(max(dp[i-1][0],dp[i-1][1]),dp[i-1][2]);
			dp[i][1] = dp[i-1][0]+p[i];
			dp[i][2] = dp[i-1][1]+p[i];	
		}
		int res;
		res = max(max(dp[N][1],dp[N][2]),dp[N][0]);
		cout<<res;	
	}
}
*/
