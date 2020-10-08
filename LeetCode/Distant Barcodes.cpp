#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
#include <queue>
using namespace std;

int p[10001];

class Solution {
public:
    vector<int> rearrangeBarcodes(vector<int>& barcodes) {
        int n = barcodes.size();
        vector<int> ans(n, 0);

        map<int, int > m;
        
        // map�� ���ڵ��� �� ���ڰ� �� ���� ���Դ��� ����ϸ� ���� ���� ���� ���� ã�´�.
        int maxCnt = 0, maxNum = 0;
        for (int i = 0; i < n; i++) {
            m[barcodes[i]]++;
            if (m[barcodes[i]] > maxCnt) {
                maxCnt = m[barcodes[i]];
                maxNum = barcodes[i];
            }
        }
        m.erase(maxNum);

        //���� ���� ���� ���� ������ŭ ����Ѵ�.  [maxNum, 0 ,maxNum, 0 , maxNum ,  ... ]
        int pos = 0;
        for (int i = 0; i < maxCnt; i++) {
            ans[pos] = maxNum;
            pos += 2;
        }

        //������ ���� ������ �°� �� �ڸ��� ä���. pos�� n�� �Ѿ�� 1���� ä���.
        for (auto it = m.begin(); it != m.end(); it++) {
            for (int j = 0; j < it->second; j++, pos += 2) {
                if (pos >= n) pos = 1;
                ans[pos] = it->first;
            }
        }

        return ans;
    }
};

class Solution2 {
public:
    vector<int> rearrangeBarcodes(vector<int>& barcodes) {
        vector<int> ans;
        map<int, int > m;
        priority_queue<pair<int, int>> q;

        int n = barcodes.size();

        for (int i = 0; i < n; i++)
            m[barcodes[i]]++;

        for (auto it = m.begin(); it != m.end(); it++)
            q.push({ it->second,it->first });

        while (!q.empty()) {
            int cur = q.top().second;
            int cnt = q.top().first;
            q.pop();

            if (!ans.empty() && ans.back() == cur) {
                int next = q.top().second;
                int nextCnt = q.top().first;
                q.pop();

                ans.push_back(next);

                q.push({ cnt,cur });
                if (--nextCnt == 0) continue;
                q.push({ nextCnt, next });
            }
            else {
                ans.push_back(cur);
                if (--cnt == 0) continue;
                q.push({ cnt,cur });
            }
        }

        return ans;
    }
};

int main()
{
    vector<int> input = { 1,2,2,3};
    Solution s;
    vector<int> res = s.rearrangeBarcodes(input);
    for (int i : res) 
        cout << i << " ";
    
}