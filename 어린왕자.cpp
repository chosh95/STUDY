/*
#include <iostream> 
using namespace std;

int prince(int noc); // input : number of circle / output : number of ����ڰ� �����ϴ� ȸ�� 
long long cx[52],cy[52],cr[52]; //r��° ���� x,y��ǥ�� ������ 
long long x[2],y[2];	// x,y[0] = �����, x,y[1] = ������ 

int main(){
	int T,n;	// Testcast, number of ���༺, result

	cin>>T;
	if(T==0) cout<<0<<endl;
	else{
		for(int j=0;j<T;j++){
			cin>>x[0]>>y[0]>>x[1]>>y[1];
			cin>>n;
			if(n==0) cout<<0<<endl;
			else{
				for(int i=1;i<=n;i++){
					cin>>cx[i]>>cy[i]>>cr[i];
				}
				cout<<prince(n)<<endl;
				for(int i=1;i<n+1;i++){
					cx[i] = cy[i] = cr[i] = 0;
				}
			}
		}
	}
}

int prince(int noc)
{
	int nx,nr=0;
	if(x[0]==x[1] && y[0]==y[1]) return 0;
	for(int i=1;i<noc+1;i++){
		for(int j=0;j<2;j++){
			if((x[j]-cx[i])*(x[j]-cx[i]) + (y[j]-cy[i])*(y[j]-cy[i]) <= cr[i]*cr[i])  	nx++;
		}
		if(nx==1) nr++;
		nx=0;		
	}
	return nr;
}
*/
