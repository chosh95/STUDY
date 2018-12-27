/*
#include <iostream>
using namespace std;
int fibo[1000][2];

int main()
{
    int T,num,res;
    cin>>T;
    fibo[0][0] = 1;
    fibo[0][1] = 0;
    fibo[1][0] = 0;
    fibo[1][1] = 1;
	for(int i=2;i<41;i++){
		fibo[i][0] = fibo[i-1][0] + fibo[i-2][0];
		fibo[i][1] = fibo[i-1][1] + fibo[i-2][1];
	}
    for(int i=0;i<T;i++){
    	cin>>num;
    	cout<<fibo[num][0]<<" "<<fibo[num][1]<<"\n";	
	}	
}
*/
