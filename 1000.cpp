/*
#include <iostream>
using namespace std;

int main()
{
	int x1,x2,y1,y2,r1,r2,T,a,b,dis;
	cin>>T;	
	for(int i=0;i<T;i++){
		cin>>x1>>y1>>r1>>x2>>y2>>r2;
		a = (x2-x1)*(x2-x1);
		b = (y2-y1)*(y2-y1);
		dis = a+b;
		
		if(dis==0 && r1==r2) cout<<"-1"<<endl; 
		else if(dis==0) cout<<"0"<<endl;
		else if(dis>(r1+r2)*(r1+r2) || (r1-r2)*(r1-r2)>dis) cout<<"0"<<endl; 
		else if(dis==(r1+r2)*(r1+r2) || dis==(r2-r1)*(r2-r1)) cout<<"1"<<endl;
		else if(dis<(r1+r2)*(r1+r2) || (r2-r1)*(r2-r1)<dis ) cout<<"2"<<endl;
		else cout<<"0"<<endl;
	}
	
	return 0;
}
*/
