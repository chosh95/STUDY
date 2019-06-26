#include <iostream>
using namespace std;
void case1(int N);
void case2(int N);
void case3(int N);
long long p[100001];
long long abs(long long a)
{
	if(a>0) return a;
	else return -a;
}
int min(long long a,long long b)
{
	if(abs(a)<abs(b)) return a;
	else return b;
}
int main()
{
	int N;
	cin>>N;
	for (int i = 1; i <= N; i++)	cin >> p[i];
	if(p[1]<0 && p[N]<0) case1(N);
	else if(p[1]<0 && p[N]>0) case2(N);
	else if(p[1]>0 && p[N]>0) case3(N);
} 

void case1(int N)
{
	cout<<p[N]+p[N-1];
}

void case2(int N)
{ 
	int t=0;
	for(int i=1;i<=N;i++){ 
		if(p[i]>0){
			t=i;
			break;
		}
	} 
	int min=p[1]+p[N];
	int tmp1,tmp2;
	for(int i=1;i<=t;i++){
		for(int j=i+1;j<=N;j++){
			if(j!=i+1 && p[j]==p[j-1]) continue;
			tmp1 = p[i]+p[j];
			if(abs(min)>abs(tmp1))	min = tmp1;
			if(j!=N){
				tmp2 = p[i]+p[j+1];
				if(abs(tmp1)<abs(tmp2)) break;
			}
			if(min==0) break;
		}
	}
	cout<<min;
}

void case3(int N)
{
	cout<<p[1]+p[2];
}