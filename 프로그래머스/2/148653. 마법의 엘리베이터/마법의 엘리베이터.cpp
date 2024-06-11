#include <iostream>
#include <string>
#include <vector>
#include <string>

using namespace std;

int solution(int storey) {
    int answer = 0;
    
    while(storey > 0) {
        int remain = storey % 10;
        storey /= 10;
        
        if(remain > 5) {
            answer += 10 - remain;
            storey++;
            cout << remain << endl;
        }
        else if(remain == 5) {
            answer += remain;
            if(storey % 10 >= 5) {
                storey++;
            }
            cout << remain << endl;
        }
        else {
            answer += remain;
            cout << remain << endl;
        }
    } 
    
    return answer;
}