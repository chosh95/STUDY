#include <string>
#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

long long solution(int n, vector<int> times) {
    long long answer = 0;
    sort(times.begin(), times.end());
    long long lo = 0, hi = (long long)times.back() * n;

    for(int i=0;i<100;i++){
        long long mid = (lo + hi) / 2;

        long long cnt = 0;
        for (int i = 0; i < times.size(); i++)
            cnt += (mid / times[i]);

        if (cnt >= n)
            hi = mid - 1;
        else
            lo = mid + 1;
    }

    return lo;
}

int main()
{
    cout << solution(6, { 7,10 });
}