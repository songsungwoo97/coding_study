// 반례 123456 n = 4 k = 2

/*#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

bool check(int num, vector<int> v) {
    auto it = find(v.begin(), v.end(), num);
    if(it == v.end())
        return false; //값이 없다면
    else
        return true; //값이 있다면
    
}

int solution(int n, int k, vector<int> enemy) {
    
    vector<int> temp = enemy;
    sort(temp.rbegin(), temp.rend());
    
    temp.resize(k);

    for(int i = 0; i < enemy.size(); i++) {
        
        //i번째 가 최대값 k번째까지 값이 있다면
        if(check(enemy[i], temp) && k > 0) {
            enemy[i] = 0;
            k--;
        }
        else {
           if(n - enemy[i] >= 0) {
               n -= enemy[i];
               enemy[i] = 0;
            }
            else {
                return i;    
            }
        }
    }
    
    return enemy.size();
}
*/


#include <string>
#include <vector>
#include <queue>
using namespace std;

int solution(int n, int k, vector<int> enemy)
{
    int sum = 0;
    
    priority_queue<int, vector<int>, greater<int>> pq;
    
    for (int i = 0; i < enemy.size(); i++)
    {
        pq.push(enemy[i]);
        
        // 무적권 개수보다 크게 쌓이면
        if (pq.size() > k)
        {
            sum += pq.top();// 가장 작은값
            pq.pop();
        }
        if (sum > n) return i;// 종료
    }
    return enemy.size();
}