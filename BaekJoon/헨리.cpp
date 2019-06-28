#include <iostream>
using namespace std;

int henry(int a,int b); 
int main()
{
	int T;
	cin>>T;
	for(int i=0;i<T;i++){
		int a,b;
		cin>>a>>b;
		int res = henry(a,b);	
		cout<<res<<endl;
	}
	return 0;
}

int henry(int a,int b)
{
	int i=b/a;
	while(1){
		if(a==1) return b;
		else if(a*i==b) return i;
		else if(a*i>b){
			a = (a*i - b);
			b *= i;		 
			return henry(a,b);
		}
		else i++;		
	}
}
