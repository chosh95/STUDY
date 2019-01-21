#include <iostream>
using namespace std;

int gcd(int x,int y)
{
	int c;
	while(true){
		if(x>=y){
			c = x%y;
			if(c==0) return y;
			x = c;
		}
		else{
			c = y%x;
			if(c==0) return x;
			y = c;
		}
	}
}
int lcm(int x,int y,int z)
{
	z = gcd(x,y);
	return (x/z)*y;
}
int main()
{
	int a,b;
	cin>>a>>b;
	int c = gcd(a,b);
	int d = lcm(a,b,c); 
	
	cout<<c<<endl<<d<<endl;
}
