/*
#include <iostream>
using namespace std;
int px[10005];
int py[10005];
int main()
{
	int N,res=0;
	cin >> N;
	for (int i = 1; i <= N; i++){
		cin >> px[i] >> py[i];
	}
	int a,b;
	a = px[1]; b = py[1];
	for (int i = 2; i <= N; i++){
		if (px[i] <= b && py[i] >= b){
			b = py[i];
		}
		else if (px[i] > b){
			res+=(b-a);		
			a = px[i];
			b = py[i];
		}
		else continue;
	}
	res+=(b-a);
	cout << res;
}
*/

