#include <iostream>
using namespace std;
int min(int a,int b)
{
	return a>b ? b : a;
	
}
int max(int a,int b)
{
	return a>b ? a : b;
}

int gcd(int a,int b)
{
	if(a%b==0) return b;
	else gcd(b,a%b);
}

int main()
{
	long long int A,B;
	cin>>A>>B;
	long long int C = gcd(max(A,B),min(A,B));
	cout<<(A/C)*(B/C)*C<<endl;
}
