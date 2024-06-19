#include <string>
#include <vector>
#include <stack>

using namespace std;

int solution(vector<int> order) {
    int answer = 0;
    
    stack<int> st1; // 컨테이너
    stack<int> st2; // 보조 컨테이너
    
    for(int i = order.size(); i > 0; i--) 
        st1.push(i);
    
    int idx = 0;
    while(idx < order.size()) {
        if(!st1.empty() && st1.top() == order[idx]) {
            answer++;
            idx++;
            st1.pop();
        }
        else if(!st2.empty() && st2.top() == order[idx]) {
            answer++;
            idx++;
            st2.pop();
        }
        else if(!st1.empty()) {        
            st2.push(st1.top());
            st1.pop();      
        }
        else {
            break;
        }
    }
    
    return answer;
}