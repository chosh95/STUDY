#include <iostream>
using namespace std;

int main()
{
	char str[1000001];
	cin.getline(str,1000001);
	int i=0,res=1;
	while(str[i]!='\0'){
		if(str[i]==' ' && i != 0) res++;
		if(str[i]==' ' && str[i-1]==' ' && i != 0){ //���� ���� 
			res--;
			break;
		} 
		i++;
	}
	if(str[0] == '\0') res=0;	// �ٷ� ������ �� 
	if(str[i-1]==' ' && str[i]=='\0') res--; // ����+���� 
	cout<<res;
	
	return 0;
}
