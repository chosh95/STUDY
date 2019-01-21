#include <iostream>
using namespace std;
bool promising(int n);
void sequence(int n);

int p[81] = {0};
int N;
int minp[81] = {9,9,9};

int main()
{
	cin>>N;
	sequence(0);
	for(int i=1;i<=N;i++) cout<<minp[i];
}

bool promising(int n)
{
    for (int i = 1; i <= n / 2; i++)
    {
        int k = 0;
        for (int j = 1; j <= i; j++)
        {
            if (p[n - i * 2 + j] == p[n - i + j])    // 동일한지 아닌지    비교
            {
                k++;
            }
        }
 
        if (k == i)    // 동일한 것이 생긴다면
        {
            return false;
        }
    }
 
    return true;
}

/*bool promising(int n)
{
	if(n==0) return true;
	bool tmp = true;
	if(p[n]==p[n-1]) tmp = false;
	if(n%2==0){
		int count=0;
		for(int j=1;j<=n/2;j++){
			if(p[j]==p[j+n/2]){
				count++;
				if(count=n/2){
				tmp = false;
				break;
				}
			}
			else break;  
		}
	}
	return tmp;
}
void sequence(int n) // n은 수열의 수 num은 n번째 수열의 숫자(1,2,3) 
{
	if(promising(n)){
		if(n==N){
			bool tmp = true;
			if(tmp){
				for(int i=1;i<=N;i++){
					if(minp[i]<p[i]) break;
					else if(minp[i]==p[i]) continue;
					else{
						tmp = false;
						break;
					}
				}
			}
			if(!tmp){
				for(int i=1;i<=N;i++) minp[i] = p[i];
			}
		}
		else{
			for(int i=1;i<=3;i++){
				p[n+1] = i;
				sequence(n+1);
			}
		}
	}
}
*/
