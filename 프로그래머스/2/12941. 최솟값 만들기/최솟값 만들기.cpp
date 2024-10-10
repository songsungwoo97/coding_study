#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int solution(vector<int> a, vector<int> b)
{
    int answer = 0;

    sort(a.begin(), a.end());
    sort(b.rbegin(), b.rend());
    
    for(int i = 0; i < a.size(); i++)     
        answer += a[i] * b[i];
    

    return answer;
}