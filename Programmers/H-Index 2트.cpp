#include <string>
#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int solution(vector<int> v) {
    int answer = 0;
    sort(v.begin(), v.end());

    for (int i = v.size(); i >= 0; i--) {
        int cnt = 0;
        for (int j = v.size()-1; j >= 0; j--) {
            if (v[j] >= i) cnt++;
            else break;
        }
        if (cnt >= i) return i;
    }

    return answer;
}

int main()
{
    cout << solution({ 3,0,6,1,5 });
}