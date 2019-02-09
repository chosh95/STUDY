#include <iostream>
using namespace std;
void sequence(int n);
bool promising(int n);

int N,p[81];
int main()
{
	cin>>N;
	sequence(N);
	for(int i=1;i<=N;i++)
		cout<<p[i];
	return 0;
}

bool promising(int n)
{
	int t=1;
	bool tmp = true;
	while(t<=n && tmp){
		if(p[t]==p[t-1] || )
	}
}
