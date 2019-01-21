#include <iostream>
#include <vector>
using namespace std;
long long p[1000005];
int main()
{
	int N,K;
	cin>>N>>K;

	p[1] = 1;
	p[2] = 2;
	p[3] = 4;
		for(int i=4;i<=N;i++){
		p[i] = (p[i-1]+p[i-2]+p[i-3]);
	}
	if(K>p[N]) cout<<-1;
	else{
		vector<int> v;
		for(int i=1;i<=p[N];i++){
			for(int j=1;j<=N;j++){
				v[i].push_back(j);
			}
		}
	}
	
	return 0;
}
