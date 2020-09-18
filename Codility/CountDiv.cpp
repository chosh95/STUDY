#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;


int solution(int A, int B, int K) {
    if (A == 0) return B / K + 1;
    return B / K - (A - 1) / K;
}

int main()
{
    cout << solution(11,345,17);
    cout << solution(0,100, 10);
    cout << solution(10,10, 5);

}