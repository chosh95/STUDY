#include <iostream> 
using namespace std;
int dp[301][3] = {0};
int p[301] = {0};

int main()
{
	int N;
	cin>>N;
	for(int i=0;i<N;i++) cin>>p[i+1];
	
	dp[1][0] = 0;
	dp[1][1] = p[1];
	dp[1][2] = 0;
	
	//계단의 개수가 1,2개일 때 
	if(N<=2){
		cout<<p[N-1] + p[N];
	}
	 
	//계단이 여러개일때 
	else{
	dp[2][1] = p[2];
	dp[2][2] = p[1] + p[2];
		
	for(int i=3;i<=N;i++){
		dp[i][1] = max(dp[i-2][1],dp[i-2][2]) + p[i];
		dp[i][2] = dp[i-1][1] + p[i]; 
	}
	
	cout<<max(dp[N][1],dp[N][2]);
	}

}
