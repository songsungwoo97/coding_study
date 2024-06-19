#include <iostream>
#include <string>
#include <vector>

using namespace std;

vector<double> solution(int k, vector<vector<int>> ranges) {
    vector<double> answer;
    
    vector<int> v;
    
    v.push_back(k);
    
    int v_size = 0;
    while(k > 1) {
        if(k % 2 == 0) {//짝수
            k /= 2;
        }
        else {//홀수
            k = k * 3 + 1;
        }
        v.push_back(k);
        v_size++;
    }
    
    for(int i = 0; i < ranges.size(); i++) {
        ranges[i][1] += v_size;
    }
    
    vector<double> v_area;
    for(int i = 0; i < v_size; i++) {
        v_area.push_back(((double)v[i] + (double)v[i + 1]) / 2);
        cout << ((double)v[i] + (double)v[i + 1]) / 2 << " ";
    }
    
    for(int i = 0; i < ranges.size(); i++) {
        int start = ranges[i][0];
        int end = ranges[i][1];
        
        if(start == end) answer.push_back(0);
        else if(start > end) answer.push_back(-1);
        else {
            double sum = 0;
            for(int j = start; j < end; j++) {
                sum += v_area[j];
            }
            answer.push_back(sum);
        }
        
    }
    
    
    return answer;
}