#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <stack>

using namespace std;

bool compare(vector<string> a, vector<string> b) {
    return a[1] < b[1];
}

//0: 과제이름, 1: 시작시간, 2: 걸리는 시간
vector<string> solution(vector<vector<string>> plans) {
    vector<string> answer;
    
    sort(plans.begin(), plans.end(), compare);
    
    int now;
    stack<pair<string, int>> st;
    for(int i = 0; i < plans.size(); i++) {
        
        if(i == plans.size() - 1) {
            answer.push_back(plans[i][0]);
            break;
        }
        
        //현재 작업
        string name = plans[i][0];
        int start = stoi(plans[i][1].substr(0, 2)) * 60 + stoi(plans[i][1].substr(3, 5));
        int ing = stoi(plans[i][2]);
        
        now = start;
        
        //다음 작업
        string name_n = plans[i + 1][0];
        int start_n = stoi(plans[i + 1][1].substr(0, 2)) * 60 + stoi(plans[i + 1][1].substr(3, 5));
        int ing_n = stoi(plans[i + 1][2]);
        
        cout << start << " " << ing << " " << start_n << endl;
        
        int time = start + ing;
        if(time < start_n) { // 시간이 남을 경우
            answer.push_back(name);
            
            while(1) {
                if(st.empty()) break;
                
                time += st.top().second;
                if(start_n - time >= 0 && !st.empty()) {
                    answer.push_back(st.top().first);
                    st.pop();
                }
                else if(start_n - time < 0 && !st.empty()) {
                    string name_st = st.top().first;
                    st.pop();
                    st.push(make_pair(name_st, time - start_n));
                    break;
                }
            }
        }
        else if(time == start_n) { // 시간이 안남을 경우
            answer.push_back(name);
        }
        else { // 시간이 모자란 경우
            st.push(make_pair(name, time - start_n));
        }
        
    }
    
    while(!st.empty()) {
        answer.push_back(st.top().first);
        st.pop();
    }
    
    return answer;
}