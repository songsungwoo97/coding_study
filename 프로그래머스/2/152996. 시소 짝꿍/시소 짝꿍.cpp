#include <string>
#include <vector>
#include <algorithm>

/**

*/

using namespace std;

long long solution(vector<int> weights) {
    long long answer = 0;
    int w_size = weights.size();
    sort(weights.begin(), weights.end()) ;
    for(int i = 0; i < w_size - 1; i++) {
        for(int j = i + 1; j < w_size; j++) {
            if(weights[i] == weights[j]) {
                answer++;
                continue;
            }
            if(3*weights[i] == 2*weights[j]) {
                answer++;
                continue;
            }
            if(2*weights[i] == weights[j]) {
                answer++;
                continue;
            }
            if(4*weights[i] == 3*weights[j]) {
                answer++;
                continue;
            }
        }
    }
    
    
    return answer;
}