#include <iostream>
#include <algorithm>
using namespace std;
int A[51];
int B[51];
bool cmp2(int a,int b)
{
	return a<b;
}
bool cmp1(int a,int b)
{
	return a>b;
}
int main()
{
	int N;
	cin>>N;
	for(int i=0;i<N;i++)
		cin>>A[i];
	for(int i=0;i<N;i++)
		cin>>B[i];
		
	sort(A,A+N,cmp2);
	sort(B,B+N,cmp1);
	int res = 0;
	for(int i=0;i<N;i++)	
		res += A[i]*B[i];
	cout<<res;
} 
