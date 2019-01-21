#include <iostream>
using namespace std;

int main()
{
	int N;
	cin>>N;
	if(N>=90 && N<=100) cout<<"A";
	else if(N>=80 && N<=89) cout<<"B";
	else if(N>=70 && N<=79) cout<<"C";	
	else if(N>=60 && N<=69) cout<<"D";
	else cout<<"F";

}
