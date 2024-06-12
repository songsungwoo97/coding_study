#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int solution(vector<vector<int>> data, int col, int row_begin, int row_end) {
    int answer = 0;
    
    col = col - 1;
    sort(data.begin(), data.end(), [col](const vector<int>& a, const vector<int>& b) {
        if (a[col] < b[col])
            return true;
        else if (a[col] == b[col])
            return a[0] > b[0];
        else
            return false;
    });
    
    for(int i = row_begin - 1; i < row_end; i++) {
        int num = 0;
        for(int j = 0; j < data[0].size(); j++) {
            num += data[i][j] % (i + 1);
        }
        answer ^= num;
    }
    
    return answer;
}