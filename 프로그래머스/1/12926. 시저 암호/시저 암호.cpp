#include <string>
#include <vector>

using namespace std;

string solution(string s, int n) {
    string answer = "";
    
    for(int i = 0; i < s.size(); i++) {
        if(s[i] == ' ') {
            answer += ' ';
        }
        else {
            if(isupper(s[i])) {  // 대문자인 경우
                answer += (s[i] - 'A' + n) % 26 + 'A';
            }
            else {  // 소문자인 경우
                answer += (s[i] - 'a' + n) % 26 + 'a';
            }
        }
    }
    
    return answer;
}