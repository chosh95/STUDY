<<<<<<< HEAD
=======
/*
>>>>>>> 9fe011e74c4cca81972d57c2f802553362fea3eb
#include <iostream>
using namespace std;
void case1(int N);
void case2(int N);
void case3(int N);
int p[100001];
int abs(int a)
{
	if(a>0) return a;
	else return -a;
}
int min(int a,int b)
{
	if(abs(a)<abs(b)) return a;
	else return b;
}
int main()
{
	int N;
	cin>>N;
	for(int i=1;i<=N;i++)	scanf("%d",&p[i]);
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
<<<<<<< HEAD
=======

*/
>>>>>>> 9fe011e74c4cca81972d57c2f802553362fea3eb
