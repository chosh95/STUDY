/*
#include <iostream>
using namespace std;
long long p[50];
void fun(int a)
{
	long long tmp = 0;
	for(int i=0;i<a;i++){
		tmp += p[i]*p[a-i-1];
	}
	p[a] = tmp;
}
int main()
{
	int N;
	cin>>N;
	p[0] = 1;
	for(int i=1;i<=N;i++) fun(i);
	cout<<p[N];
}
*/

