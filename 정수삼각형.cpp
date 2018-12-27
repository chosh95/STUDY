/*
#include <iostream> 
using namespace std;

int max(int a,int b)
{
	if(a>b) return a;
	else return b;
}

int main()
{
	int N;
	cin>>N;
	int lastN = N*(N+1)/2;
	int p[502][502];
	int dp[502][502];
	for(int i=1;i<=N;i++){
		for(int j=1;j<=i;j++){
			cin>>p[i][j];
		}
	} 
	dp[1][1] = p[1][1];
	int maxN = p[1][1];
	
	for(int i=2;i<=N;i++){
		for(int j=1;j<=i;j++){
			dp[i][j] = max(dp[i-1][j-1],dp[i-1][j]) + p[i][j];
			if(maxN<dp[i][j]) maxN = dp[i][j];
		}
	}
	cout<<maxN;	
}
*/
