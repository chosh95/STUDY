<<<<<<< HEAD
=======
/*
>>>>>>> 9fe011e74c4cca81972d57c2f802553362fea3eb
#include <iostream>
using namespace std;

int main()
{
	char str[10000001];
	cin.getline(str,1000001);
	int i=0,res=1;
	while(str[i]!='\0'){
		if(str[i]==' ' && i != 0) res++;
		i++;
	}
	if(str[0]==' ' && str[1]=='\0') res = 0;
	
	cout<<res;
	
	return 0;
<<<<<<< HEAD
}
=======
*/
>>>>>>> 9fe011e74c4cca81972d57c2f802553362fea3eb
