#include <iostream>
#include <algorithm>
using namespace std;

int solution(int X, int Y, int D) {
    int dist = Y - X;
    int answer = dist / D;
    if (dist % D != 0) answer++;
    return answer;
}

int main()
{
    cout << solution(10, 85, 30);
}