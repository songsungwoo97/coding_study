#include <string>
#include <vector>
#include <algorithm>

using namespace std;

long long solution(int cap, int n, vector<int> deliveries, vector<int> pickups) {
    long long answer = 0;
    
    int idx = n - 1;
    int d_idx, d_cnt = 0;
    int p_idx, p_cnt = 0;
    while(1) {
        
        //종료 조건
        if(d_idx < 0 && p_idx < 0)
            break;
        
        //시작지점 찾기 == idx
        while (0 <= idx) {
            if(deliveries[idx] > 0 || pickups[idx] > 0)
                break;
            else
                idx--;
        }
        
        d_idx = idx;
        p_idx = idx;
        
        //배달
        while(d_cnt < cap) {        
            if(d_idx < 0) {
                break;
            }
            if(deliveries[d_idx] <= 0) {
                d_idx--;
            }
            else {
                deliveries[d_idx]--;
                d_cnt++;
            } 
            
        }
        
        //수거
        while(p_cnt < cap) {
            if(p_idx < 0) {
                break;
            }
            if(pickups[p_idx] <= 0) {
                p_idx--;
            } 
            else {
                pickups[p_idx]--;
                p_cnt++;
            }
            
        }
        
        //왕복 계산(0부터 값이 있으므로)
        answer += (idx + 1) * 2;
        
        d_cnt = 0; p_cnt = 0;
    }
    
    return answer;
}