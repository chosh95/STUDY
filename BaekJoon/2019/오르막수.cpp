#include <iostream>
using namespace std;
long long dp[1001][11];
void ascent(int n);

int main()
{
	int N;
	cin>>N;
	ascent(N);
	cout<< dp[N][10];	
} 

void ascent(int n)
{
	for(int i=0;i<=9;i++){
		dp[1][i] = 1;
	}
	for(int i=2;i<=n;i++){
		for(int j=0;j<=9;j++){
			for(int k=j;k<=9;k++){
				dp[i][j] += dp[i-1][k];
				dp[i][j] %= 10007;
			}
		}
	}
	for(int i=0;i<=9;i++){
		dp[n][10] += dp[n][i];
		dp[n][10] %= 10007;
	}
}
