#include <string>
#include <iostream>
#include <stack>

using namespace std;

bool solution(string s)
{
    bool answer = true;
    
    stack<char> st;
    
    if(s[0] != '(')
        return false;
    
    st.push(s[0]);
    
    for(int i = 1; i < s.size(); i++) {
        if(s[i] == '(') {
            st.push(s[i]);
        }
        else {
            if(st.empty())
                return false;
            st.pop();
        }
    }
    
    if(!st.empty()) {
        answer = false;
    }
    else {
        answer = true;
    }

    return answer;
}