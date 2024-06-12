#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <map>

using namespace std;

bool cmp(pair<int, int> a, pair<int, int> b) {
    return a.second < b.second;
}

int solution(int k, vector<int> tangerine) {
    int answer = 0;
    
    map<int, int> m;
    
    for(int t : tangerine) {
        if(m.find(t) != m.end()) {
            m[t]++;
        }
        else {
            m.insert({t, 1});
        }
    }
    
    vector<pair<int, int>> v(m.begin(), m.end());
    
    sort(v.begin(), v.end(), cmp);
    
    int count = tangerine.size() - k; // 나머지 갯수
    
    for(pair<int, int> p : v) {
        if(count <= 0) break;
        if(count > p.second) {
            count -= p.second;
            m.erase(p.first);
        }
        else if(count == p.second) {
            m.erase(p.first);
            break;
        }
        else {
            m[p.first] -= count;
            break;
        }
    } 
    
    answer = m.size();
    
    return answer;
}