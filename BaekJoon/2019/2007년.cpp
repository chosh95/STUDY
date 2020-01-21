#include <iostream> 
using namespace std;

int main()
{
	int X,Y,res;
	cin>>X>>Y;
	int p[13] = {0,31,28,31,30,31,30,31,31,30,31,30,31};
	res+=Y;
	if(X>1) 
		for(int i=1;i<X;i++)
			res+=p[i];
	res%=7;
	if(res==0) cout<<"SUN"<<endl;
	else if(res==1) cout<<"MON"<<endl;
	else if(res==2) cout<<"TUE"<<endl;
	else if(res==3) cout<<"WED"<<endl;
	else if(res==4) cout<<"THU"<<endl;
	else if(res==5) cout<<"FRI"<<endl;
	else if(res==6) cout<<"SAT"<<endl;
	
}
