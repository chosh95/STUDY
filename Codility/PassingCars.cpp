#include <iostream>
#include <vector>
using namespace std;

int solution(vector<int>& A) {
    int res = 0, cnt = 0;
    for (int i = A.size() - 1; i >= 0; i--) {
        if (A[i] == 1) cnt++;
        else res += cnt;
        if (res > 1000000000) return -1;
    }
    return res;
}   

int main()
{
    vector<int> a = { 0,1,0,1,1 };
    cout << solution(a);
}