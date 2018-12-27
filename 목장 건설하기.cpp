/*
#include <iostream> 
using namespace std;
int p[1001][1001];
int dp[1001][1001];
int min(int a,int b)
{
	if(a>b) return b;
	else return a;
}
int main()
{
	int M,N;
	cin>>M>>N;
	for(int i=1;i<=M;i++){
		for(int j=1;j<=N;j++){
			cin>>p[i][j];
			dp[i][j] = 0;
		}
	}
	int max=0;
	for(int i=1;i<=M;i++){
		for(int j=1;j<=N;j++){
			if(p[i][j]==0){
				dp[i][j] = min(dp[i-1][j],dp[i][j-1]);
				dp[i][j] = min(dp[i][j],dp[i-1][j-1])+1;	
				if(max<dp[i][j]) max = dp[i][j];
			}
		}
	}
	cout<<max;
}
*/
